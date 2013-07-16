proc checkIncludeOrder { fileName } {
  set parentH 0
  set systemConnected 0
  set fileShortName ""
  regexp {^[^.]*} [file tail $fileName] fileShortName
  if {[regexp -nocase {.*.h$} $fileName] } { set parentH 1 }
  set lineCount 1
  foreach line [getAllLines $fileName] {
    if [regexp {[ \t]*#include[ \t]*"$fileShortName.h"[\t ]*} $line] {
      set parentH 1
     }
     if [regexp {[\t ]*#include[\t ]*<[^>]*>[ \t]*$} $line] {
	if {$parentH == 0} { report $fileName $lineCount "Invalid order of includes" }
	if {$systemConnected == 1} {report $fileName $lineCount "Invalid order of includes" }
     }
     if [regexp {[\t ]*#include[\t ]*\"[^\"]*\"[ \t]*$} $line] {
	set systemConnected 1
	if {$parentH == 0} { report $fileName $lineCount "Invalid order of includes" }
     }
     incr lineCount
  }
}

puts CIOExecuted
foreach fileName [getSourceFileNames] {
  checkIncludeOrder $fileName
}