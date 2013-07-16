#!/usr/bin/tclsh
# Checks if there is pragma once and there is no ifdef

proc checkGuards { fileName } {
  if {![regexp -nocase {.*.h$} $fileName] } { return }
  set lineCount 1 
  set guardFound 0
  foreach line [getAllLines $fileName] {
    if {[regexp {^[\t ]*#pragma once[\t\r\n ]*} $line] } {
      set guardFound 1 
    }
    if {[regexp {^[\t ]*#ifn?def .*|^[\t ]*#endif.*} $line] } {
      set guardFound 1
      report $fileName $lineCount "Old-style include guard"
    }
    incr lineCount
  }
  if {![expr $guardFound]} {
    puts "$fileName: No include guard in header file"
  }
}

foreach fileName [getSourceFileNames] {
  checkGuards $fileName
}