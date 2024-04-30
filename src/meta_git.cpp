
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

int main( int argc, char const* argv[] )
 {
  // Parse arguments
  argparse::ArgumentParser program("mgit", "0.1", argparse::default_arguments::all);
  program.add_description("Linux command-line utility which apply git commands in a hierarchy of git repositories..");
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
 }