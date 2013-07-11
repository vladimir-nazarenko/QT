#!/usr/bin/tclsh
# Checks if lines in the source start with no spaces

proc checkTabs { fileName } {
  set lineCount 0
  foreach line [getAllLines $fileName] {
    if {![regexp -nocase {^[^ ]+.*[\n\r]*|^$} $line] } {
      report $fileName $lineCount "String starts with spaces"
    }
    incr lineCount
    }
}

foreach fl [getSourceFileNames] {
  checkTabs $fl
}