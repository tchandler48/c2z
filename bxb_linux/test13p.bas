'    test13p.bas
    CLS
    abc$ = "This is a test of the Emergecny Brtoadcast System"
    PRINT "Test: >"; CHR$(251); "< End Test"
    PRINT ">"; LEFT$(abc$, 14); "<"
    PRINT ">"; RIGHT$(abc$, 26); "<"
    PRINT ">"; MID$(abc$, 23, 19); "<"
    PRINT ">"; SPACE$(10); "<"
    PRINT ">"; STR$(1000); "<"
    PRINT ">"; STRING$(10, 251); "<"
TheEnd:
    END
