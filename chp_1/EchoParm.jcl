USERID DOSVS
// JOB ECHOPARM
// OPTION LINK,LOG
// EXEC ASSEMBLY
         TITLE 'DISPLAY EXEC PARM= ON CONSOLE'
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* Program name: ECHOPARM                                          *
*                                                                 *
* Author:  Fran Hensler                                           *
*                                                                 *
* Version 1.0  27-May-2010                                        *
* Version 1.1  29-May-2010  Length correction by "somitcw"        *
*                                                                 *
* Released to the public domain.                                  *
*                                                                 *
* Purpose: This program will ECHO the EXEC PARM=                  *
*                                                                 *
* Restriction:  This program will work in DOS/VS R34 only if      *
*               modifications to $JOBCTLE are made to support     *
*               the PARM= field on the EXEC statement.            *
*                                                                 *
* Input: Data from the EXEC statement PARM field                  *
*                                                                 *
* Output: Data is displayed on SYSLOG, truncated to 61 bytes      *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
         PRINT NOGEN
ECHOPARM START 0
         BALR  R10,0
         USING *,R10
         CLR   R1,R15                  WAS A PARM PASSED ?
         BZ    NOPARM                    NO
         TM    0(R1),X'80'             CHECK AGAIN
         BZ    NOPARM                    NO
         L     R4,0(R1)                  YES   GET THE EPARM ADDR
         XR    R3,R3                   CLEAR WORK REGISTER
         ICM   R3,B'0011',0(R4)        GET THE HALFWORD LENGTH     1.1
         CH    R3,=H'061'              MSG TOO LONG ?
         BNH   LENOK                     NO...PROCEED
         LA    R3,61                   TRUNCATE THE MESSAGE
LENOK    BCTR  R3,0                    MAKE MACHINE LENGTH         1.1
         EX    R3,MOVEPARM             MOVE THE PARM= TEXT TO CONSOLE
         PUT   CONSOLE
         EOJ
NOPARM   MVC   PARMTEXT(31),=CL31'    No PARM= on EXEC statement.'
         PUT   CONSOLE
         EOJ
*
MOVEPARM MVC   PARMTEXT(*-*),2(R4)    EXECUTED MOVE
*
IOAREA   EQU   *
         DC    CL9'ECHOPARM:'
PARMTEXT DC    CL61' '
CONSOLE  DTFCN BLKSIZE=70,DEVADDR=SYSLOG,TYPEFLE=OUTPUT,IOAREA1=IOAREA
*
* * * * * * * * * * * * * * * *
* *    REGISTER EQUATES     * *
* * * * * * * * * * * * * * * *
R0       EQU    0   EQUATE    *
R1       EQU    1   ALL       *
R2       EQU    2   THE       *
R3       EQU    3   REGISTERS *
R4       EQU    4   TO        *
R5       EQU    5   SYMBOLS   *
R6       EQU    6   SO        *
R7       EQU    7   THAT      *
R8       EQU    8   REGISTER  *
R9       EQU    9   USAGE     *
R10      EQU   10   MAY       *
R11      EQU   11   BE        *
R12      EQU   12   TRACED    *
R13      EQU   13   IN THE    *
R14      EQU   14   X-REF     *
R15      EQU   15   LISTING   *
* * * * * * * * * * * * * * * *
         END
/*
// EXEC LNKEDT
// EXEC
// EXEC ,PARM='I hope this works!'
// EXEC ,PARM='What''s up Doc?'
// EXEC ,PARM='This PARM contains an equal sign (=), and comma.'
/*
/&
