   REM
   PRINT "BX10A testing"
   def$ = " "
   xyz$ = "testing"
   tec$ = "tom"
   PRINT xyz$
   PRINT tec$
   abc$ = "this is abc"
   PRINT abc$
   def$ = LEFT$(xyz$,4)
   PRINT def$
   def$ = RIGHT$(xyz$,3)
   PRINT def$
   def$ = MID$(xyz$,3,3)
   PRINT def$
TheEnd:
   END
