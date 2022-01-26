  REM  bx7a.bas
  PRINT "BX7A.BAS Started"
  LET don$ = "don"
  LET tom$ = "tchandler"
  sam$ = "stephanie"
  dog = 1
  cat = 2
  pet = dog + cat
  bird = 5 + 3
  def = 5678
  PRINT don$
  GOSUB Loop1
  PRINT tom$
  PRINT sam$
  GOSUB Loop2
  PRINT def
  PRINT pet
  PRINT bird
  PRINT "End of bx7a.bas"
  GOTO TheEnd
Loop2:
  PRINT "Subroutne TWO"
  RETURN
Loop1:
  PRINT "Subroutine One"
  RETURN
TheEnd:
  END
