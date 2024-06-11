
/*

Linux command-line utility which apply git commands in a hierarchy of git repositories..

The key features are:
- recursive visit of the directories ;
- git repositories can be nested.

*/

#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

#include "argparse.hpp"
#include "scan.hh"

int main( int argc, char const* argv[] )
 {
  constexpr auto version { "0.2" } ;

  // Parse arguments
  argparse::ArgumentParser program("mgit", version, argparse::default_arguments::none);
  program.add_description("Linux command-line utility which apply git commands in a hierarchy of git repositories..");
  program.add_argument("--meta-help")
    .help("shows help message and exits")
    .flag();
  program.add_argument("--meta-version")
    .help("prints version information and exits")
    .flag();
  program.add_argument("cmd")
    .remaining()
    .help("the git command to apply in each embedded git repository."); 
  try
   {
    program.parse_args(argc, argv);
   }
  catch (const std::runtime_error& err)
   {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return 1;
   }

  // Interpret arguments
  if (program.get<bool>("--meta-help"))
   {
    std::cout << program.help().str();
    std::exit(0);
   }
  if (program.get<bool>("--meta-version"))
   {
    std::cout << version << std::endl;
    std::exit(0);
   }
  auto cmd { std::format("git {}",join(program.get<std::vector<std::string>>("cmd"))) } ;

  // Recursively scan the top directory
  DirectoryScan top_dir(fs::current_path().string()) ;
  top_dir.apply([cmd]( fs::path path)
   {
    fs::current_path(path) ;
    std::system(cmd.data()) ;
   }) ;
  std::cout<<"#####"<<std::endl ;

  // That's all folks
  std::exit(0) ;
 }