#!/usr/bin/tclsh
# Source files should not use the '\r' (CR) character

proc getFiles { folder } {
  set listOfFiles ""
  foreach sourceFile [glob -nocomplain -type f -directory $folder *] {
  puts $sourceFile
    if [regexp -nocase {.*[.]cpp$} $sourceFile ] {
      set listOfFiles [concat $listOfFiles $sourceFile]
    }
  }
  foreach subfolder [glob -nocomplain -type {d r} -directory $folder *] {    
    set listOfFiles [concat $listOfFiles [getFiles $subfolder ]]
  }
  return $listOfFiles
}

set parameters "-p allRules"
set parameters [concat $parameters [getFiles [pwd]]]
set fo [open "buildScripts/vera++/params" "w" ]
puts $fo $parameters
close $fo