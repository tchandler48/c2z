'   Rem tes13.bas
    CLS
Start:
    abc$ = INKEY$
    IF abc$ = "" THEN
        GOTO Start
    ENDIF
    PRINT abc$
    PRINT "Enter your name:"
    INPUT "First: "; first$; " Initial: "; init$; " Last: "; last$:
    PRINT "Enter your age and birth date:"
    INPUT ;"Age: "; age;  " Month: "; mo; "/Day: "; day; "/Year: "; year%:
'
    PRINT first$, init$, last$
    PRINT age, mo, day, year%
TheEnd:
    END
