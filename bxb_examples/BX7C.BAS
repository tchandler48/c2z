  REM BX7C.BAS
  CLS
  GOSUB TOP
  GOSUB CTR
  GOSUB BOT
  GOTO TheEnd
  REM
CTR:
  REM FOR x = 1 TO 5
  PRINT "*";
    FOR c = 1 TO 28
      PRINT " ";
    NEXT c
    PRINT "*":
  REM NEXT x
  RETURN
  REM
TOP:
BOT:
  FOR x = 1 TO 30
    PRINT "*";
  NEXT x
  PRINT " ":
  RETURN
  REM
TheEnd:
  END
