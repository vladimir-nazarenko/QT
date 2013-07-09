#!/usr/bin/tclsh
# Source files should not use the '\r' (CR) character

proc printSubfolders { folder } {
  foreach subfolder [glob -nocomplain -type {d r} -directory $folder *] { 
  puts $subfolder 
  printSubfolders $subfolder}
}

puts [pwd]
printSubfolders [pwd]
