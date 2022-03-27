  REM    bx4b.bas
  PRINT "HERE 1"
  LET yahoo = 9
  LET abc = 12
  LET def = 123
  GOTO First
Loop1:
  PRINT "HERE 3"
  PRINT yahoo
  PRINT abc
  GOTO TheEnd
First:
  PRINT "HERE 2"
  LET ghk = 567
  LET zz = 12345
  PRINT ghk
  PRINT zz
  GOTO Loop1
TheEnd:
  PRINT "END OF PROGRAM"
  END 
