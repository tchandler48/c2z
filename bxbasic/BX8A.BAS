  REM  bx8a.bas
  PRINT "Hello Z390 World bx8a"
  LET abc = 99
  xyz = 33
  abc$ = "test"
  xyz$ = "testing"
  IF xyz$ = "testing" AND abc >= xyz THEN
     PRINT "#0 if:expression = true"
  ELSEIF abc <= 100 OR abc$ <= "hello" THEN
     PRINT "#1 elseif:expression = true"
  ELSE
     PRINT "#2 else:expressions = false"
  ENDIF
  PRINT "done"
TheEnd:
  END
