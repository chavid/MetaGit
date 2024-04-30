
/*

Linux command-line utility which SHORT_DESCRIPTION.

The key features are:
-  ;
- .

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
  argparse::ArgumentParser program("SHORT_NAME", "0.1", argparse::default_arguments::all);
  program.add_description("Linux command-line utility which SHORT_DESCRIPTION.");
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