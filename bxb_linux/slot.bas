'   Slot1.BAS || Bxbasm/Bxbasic
'   a slot machine... simulation
'
    CLS 
    GOSUB SCRNSETUP
' ***********************play game **************
    total1 = 0
    points = 0
Playgame:
    '                           generate numbers from 0-5
    d1i = RAND() % RAND() % 6
    d2i = RAND() % RAND() % 6
    d3i = RAND() % RAND() % 6
    GOSUB DRUM1
    GOSUB DRUM2
    GOSUB DRUM3
    total1 = (cell1 + cell2 + cell3)
    GOSUB RLLDRUMS
    GOSUB LetitRoll
    '
    COLOR 7,0
    LOCATE 20, 20
Getkeypress:
    a$ = INKEY$
        IF a$ = "" THEN
            GOTO Getkeypress
        ELSEIF a$ = "x" OR a$ = "X" THEN
            GOTO XAlldone
        ENDIF
    GOTO Playgame
XAlldone:
    END
'===============================================================
LetitRoll:
    LOCATE 15, 45
    COLOR 7, 0
    '                                       test for all LEMONS
    IF total1 = 0 AND points >= 1 THEN
        points = 0
        PRINT SPACE$(8);
        COLOR 12, 0
        LOCATE 17, 45
        PRINT "You Lose All Points!";
Flash:
        COLOR 12, 0
        LOCATE 17, 45
        PRINT "You Lose All Points!";
        a$ = INKEY$
            COLOR 7, 0
            LOCATE 17, 45
            PRINT SPACE$(20);
        IF a$ = "" THEN
            GOTO Flash
        ENDIF
            LOCATE 17, 45
            PRINT SPACE$(20);
        GOTO RepeatX
    ENDIF
    '
    IF total1 = 0 AND points <= 0 THEN
        GOTO Nomoney
    ENDIF
'                           test for paying combinations
    IF total1 >= 10000 THEN
        GOTO Bars
    ELSEIF total1 >= 1000 THEN
        GOTO Bells
    ELSEIF total1 >= 100 THEN
        GOTO Limes
    ELSEIF total1 >= 10 THEN
        GOTO Oranges
    ELSE
        GOTO Cherries
    ENDIF
Bars:
    IF total1 = 30000 THEN
        points = (points + 9000)
        PRINT "Win 9000";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
        '                               test for 2 BELLS plus 1 BAR
    ELSEIF total1 = 12000 THEN
        points = (points + 500)
        PRINT "Win 500 ";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
        '                               test for 2 LIMES plus 1 BAR
    ELSEIF total1 = 10200 THEN
        points = (points + 50)
        PRINT "Win 50  ";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
        '                               test for 2 ORANGES plus 1 BAR
    ELSEIF total1 = 10020 THEN
        points = (points + 10)
        PRINT "Win 10  ";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
    ENDIF
    GOTO Cherries
    '                                   test for all BELLS
Bells:
    IF total1 = 3000 THEN
        points = (points + 2000)
        PRINT "Win 2000";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
    ENDIF
    GOTO Cherries
    '                                           test for all LIMES
Limes:
    IF total1 = 300 THEN
        points = (points + 100)
        PRINT "Win 100 ";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
    ENDIF
    GOTO Cherries
    '                                       test for all ORANGES
Oranges:
    IF total1 = 30 THEN
        points = (points + 25)
        PRINT "Win 25  ";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
    ENDIF
    '                                       test for CHERRIES
Cherries:
    IF total1 >= 10000 THEN
        total1 = (total1 - 10000)
        GOTO Cherries
    ENDIF
    '
Minus1k:
    IF total1 >= 1000 THEN
        total1 = (total1 - 1000)
        GOTO Minus1k
    ENDIF
    '
Minus1h:
    IF total1 >= 100 THEN
        total1 = (total1 - 100)
        GOTO Minus1h
    ENDIF
    '
Minusten:
    IF total1 >= 10 THEN
        total1 = (total1 - 10)
        GOTO Minusten
    ENDIF
    IF total1 = 3 THEN
        points = (points + 6)
        PRINT "Win 6   ";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
    ELSEIF total1 = 2 THEN
        points = (points + 5)
        PRINT "Win 5   ";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
    ELSEIF total1 = 1 THEN
        points = (points + 1)
        PRINT "Win 1   ";
        LOCATE 17, 45
        PRINT "Points:          ";
        LOCATE 17, 52
        PRINT points;
        GOTO RepeatX
    ENDIF
    '
Nomoney:
    points = (points - 10)
    PRINT "Lose -10 ";
    LOCATE 17, 45
    PRINT "Points:          ";
    LOCATE 17, 52
    PRINT points;
RepeatX:
    RETURN
'
RLLDRUMS:
    FOR i% = 1 TO 100
        FOR ii% = 0 TO 8 STEP 1
            COLOR 7, ii%
            LOCATE 15, 20
            PRINT SPACE$(7);
        NEXT ii%
    NEXT i%
    LOCATE 15, 20
    COLOR co1, co2
    PRINT d1s$; 
    '                                               clear drum2
    FOR i% = 1 TO 100
        FOR ii% = 0 TO 8 STEP 1
            COLOR 7, ii%
            LOCATE 15, 27
            PRINT SPACE$(7);
        NEXT ii%
    NEXT i%
    LOCATE 15, 27
    COLOR co3, co4
    PRINT d2s$; 
    '                                               clear drum3
    FOR i% = 1 TO 100
        FOR ii% = 0 TO 8 STEP 1
            COLOR 7, ii%
            LOCATE 15, 34
            PRINT SPACE$(7);
        NEXT ii%
    NEXT i%
    LOCATE 15, 34
    COLOR co5, co6
    PRINT d3s$;
    RETURN
'
DRUM1:
    IF d1i = 0 THEN
        d1s$ = " LEMON "
        cell1 = 0
        co1 = 14
        co2 = 0
    ELSEIF d1i = 1 THEN
        d1s$ = "CHERRY "
        cell1 = 1
        co1 = 4
        co2 = 0
    ELSEIF d1i = 2 THEN
        d1s$ = "ORANGE "
        cell1 = 10
        co1 = 12
        co2 = 0
    ELSEIF d1i = 3 THEN
        d1s$ = " LIME  "
        cell1 = 100
        co1 = 10
        co2 = 2
    ELSEIF d1i = 4 THEN
        d1s$ = " BELL  "
        cell1 = 1000
        co1 = 14
        co2 = 6
    ELSE
        d1s$ = "-BAR-- "
        cell1 = 10000
        co1 = 0
        co2 = 7
    ENDIF
    RETURN
'
DRUM2:
    IF d2i = 0 THEN
        d2s$ = " LEMON "
        cell2 = 0
        co3 = 14
        co4 = 0
    ELSEIF d2i = 1 THEN
        d2s$ = "CHERRY "
        cell2 = 1
        co3 = 4
        co4 = 0
    ELSEIF d2i = 2 THEN
        d2s$ = "ORANGE "
        cell2 = 10
        co3 = 12
        co4 = 0
    ELSEIF d2i = 3 THEN
        d2s$ = " LIME  "
        cell2 = 100
        co3 = 10
        co4 = 2
    ELSEIF d2i = 4 THEN
        d2s$ = " BELL  "
        cell2 = 1000
        co3 = 14
        co4 = 6
    ELSE
        d2s$ = "-BAR-- "
        cell2 = 10000
        co3 = 0
        co4 = 7
    ENDIF
    RETURN
'
DRUM3:
    IF d3i = 0 THEN
        d3s$ = " LEMON "
        cell3 = 0
        co5 = 14
        co6 = 0
    ELSEIF d3i = 1 THEN
        d3s$ = "CHERRY "
        cell3 = 1
        co5 = 4
        co6 = 0
    ELSEIF d3i = 2 THEN
        d3s$ = "ORANGE "
        cell3 = 10
        co5 = 12
        co6 = 0
    ELSEIF d3i = 3 THEN
        d3s$ = " LIME  "
        cell3 = 100
        co5 = 10
        co6 = 2
    ELSEIF d3i = 4 THEN
        d3s$ = " BELL  "
        cell3 = 1000
        co5 = 14
        co6 = 6
    ELSE
        d3s$ = "-BAR-- "
        cell3 = 10000
        co5 = 0
        co6 = 7
    ENDIF
    RETURN
'
SCRNSETUP:
    CLS 
'    seed% = CLOCK
'    RANDOM seed%
'                               the 6 possible options:
'                           Bar, Bell, Lime, Orange, Cherry, Lemon
    LOCATE 1, 5
    PRINT "Winning Combinations";
    LOCATE 2, 1
    COLOR 7, 0
    PRINT "-BAR-- -BAR-- -BAR--";
    LOCATE 2, 22
    COLOR 7, 0
    PRINT "= 9,000";
'
    LOCATE 3, 1
    COLOR 14, 6
    PRINT " BELL   BELL   BELL ";
    LOCATE 3, 22
    COLOR 7, 0
    PRINT "= 2,000";
    LOCATE 4, 1
    COLOR 14, 6
    PRINT " BELL   BELL  "; 
    COLOR 7, 0
    PRINT "-BAR--";
    LOCATE 4, 22
    COLOR 7, 0
    PRINT "= 500";
'
    LOCATE 5, 1
    COLOR 10, 2
    PRINT " LIME   LIME   LIME ";
    LOCATE 5, 22
    COLOR 7, 0
    PRINT "= 100";
    LOCATE 6, 1
    COLOR 10, 2
    PRINT " LIME   LIME  "; 
    COLOR 7, 0
    PRINT "-BAR--";
    LOCATE 6, 22
    COLOR 7, 0
    PRINT "= 50";
'
    LOCATE 7, 1
    COLOR 12, 0
    PRINT "ORANGE ORANGE ORANGE";
    LOCATE 7, 22
    COLOR 7, 0
    PRINT "= 25";
    LOCATE 8, 1
    COLOR 12, 0
    PRINT "ORANGE ORANGE "; 
    COLOR 7, 0
    PRINT "-BAR--";
    LOCATE 8, 22
    COLOR 7, 0
    PRINT "= 10";
'
    LOCATE 9, 1
    COLOR 4, 0
    PRINT "       CHERRY CHERRY";
    LOCATE 9, 22
    COLOR 7, 0
    PRINT "= 5";
    LOCATE 10, 1
    COLOR 4, 0
    PRINT "              CHERRY";
    LOCATE 10, 22
    COLOR 7, 0
    PRINT "= 1";
'
    LOCATE 11, 1
    COLOR 14, 0
    PRINT " LEMON  LEMON  LEMON ";
    LOCATE 11, 22
    COLOR 7, 0
    PRINT "= Lose All";
'
    LOCATE 19, 1
    PRINT "press: [space] to roll again";
    LOCATE 20, 1
    PRINT "press: [X] to quit";
'
    RETURN
'===================================================================
