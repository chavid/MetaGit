
#pragma once

#include "utilities.hh"

// While browsing recursively the filesystem directories,
// Check which directories are git repositories.
class DirectoryScan
 {
  public:

    // scan for git repositories
    DirectoryScan( fs::path const & path = "" ) ;

    // apply in each git repository
    void apply( auto process_path ) const ;

  private:

    fs::path path_ ;
    bool selected_dir_ = false ;
    std::vector<DirectoryScan> subdirs_ ;

    void scan_dir() ;

 } ;

void DirectoryScan::apply( auto process_path ) const
 {
  if (selected_dir_)
   {
    std::cout<<"##### "<<path_.string()<<"\n" ;
    process_path(path_) ;
   }
  for ( auto const & subdir : subdirs_ )
   { subdir.apply(process_path) ; }
 }
