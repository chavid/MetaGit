
#include "scan.hh"

//=============================================================================
// DirectoryScan
//=============================================================================

DirectoryScan::DirectoryScan( fs::path const & path ) : path_(path)
 {
  // check status
  auto s = fs::status(path_) ;
  if (fs::is_regular_file(s))
   { throw std::runtime_error("Unexpected regular file.") ; }
  if (fs::is_symlink(s))
   { return ; }
  if (!fs::is_directory(s))
   { throw std::runtime_error("Unexpected non directory.") ; }

  // check name
  std::string dirname { path_.filename().string() } ;
  if ((std::size(dirname)>1)&&(dirname[0]=='.')&&(dirname[1]!='.'))
   { throw std::runtime_error("Unexpected .*") ; }
  if ((std::size(dirname)>1)&&(dirname[0]=='_')&&(dirname[1]=='_'))
   { throw std::runtime_error("Unexpected __") ; }

  // scan the directory
  for ( auto it = fs::directory_iterator(path_) ; it != fs::directory_iterator() ; ++it )
   {
    fs::path subpath = *it ;
    auto subs = fs::status(subpath) ;
    // Note : if a link is dangling, is_symlink returns false
    if (fs::is_symlink(subs))
     { continue ; }
    if (!fs::is_directory(subs))
     { continue ; }
    std::string subdirname { subpath.filename().string() } ;
    if (subdirname==".git")
     { selected_dir_ = true ; }
    if ((std::size(subdirname)>1)&&(subdirname[0]=='.')&&(subdirname[1]!='.'))
     { continue ; }
    if ((std::size(subdirname)>1)&&(subdirname[0]=='_')&&(subdirname[1]=='_'))
     { continue ; }
    subdirs_.emplace_back(subpath) ;
   }
 }
  

