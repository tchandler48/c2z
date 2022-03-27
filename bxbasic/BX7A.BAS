  REM  bx7a.bas
  PRINT "BX7A.BAS Started"
  LET don$ = "don"
  LET tom$ = "tchandler"
  sam$ = "stephanie"
  dog = 1
  cat = 2
  bird = 5 + 3
  defa = 5678
  PRINT don$
  GOSUB Loop
  PRINT tom$
  PRINT sam$
  GOSUB Second
  PRINT bird
  PRINT cat
  PRINT dog
  PRINT "End of bx7a.bas"
  GOTO TheEnd
Second:
  PRINT "Subroutne TWO"
  RETURN
Loop:
  PRINT "Subroutine One"
  RETURN
TheEnd:
  END
