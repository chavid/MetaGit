
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
  // Parse arguments
  argparse::ArgumentParser program("mgit", "0.1", argparse::default_arguments::all);
  program.add_description("Linux command-line utility which apply git commands in a hierarchy of git repositories..");
  program.add_argument("cmd")
    .nargs(argparse::nargs_pattern::any)
    .help("the command to apply in each embedded git repository."); 
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