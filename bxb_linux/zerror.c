/* bxbasic : error.c : alpha version */
/* ----- includes ----- */
#include "prototyp.h"


void a_bort(int code,int line_ndx)
{
    beep();
    switch(code)
    {   case 1:
            printf("Unspecified Program Name.\n");
            printf("code(%d)\n",code);
            break;
        case 2:
            printf("Program file:\"%s\" not found.\n", t_holder);
            printf("Program Terminated.\ncode(%d)\n", code);
            break;
        case 3:
             printf(" %d.\n%s",(line_ndx+1),p_string);
             printf("code(%d)\n", code);
            break;
        case 4:
            printf(" %d.\n%s",(line_ndx+1),p_string);
            printf("Unknown Command.\ncode(%d)\n", code);
            break;
        case 5:
            printf("\nVariable Type error: in program line:");
            printf(" %d.\n%s",(line_ndx+1),p_string);
            printf("Type must be: Long \"%c\".\ncode(%d)\n",'%',code);
            break;
        case 6:
            printf(" %d.\n%s",(line_ndx+1),p_string);
            printf("No closing quotes.\ncode(%d)\n", code);
            break;
        case 7:
            printf(" %d.\n%s",(line_ndx+1),p_string);
            printf("Expected: \"%s\".\ncode(%d)\n",t_holder,code);
            break;
        case 8:
            printf("\nGOTO Error: no such label:");
            printf(" %s:\nin program line:",t_holder);
            printf(" %d:\nGOTO %s",(line_ndx+1),p_string);
            printf("Program Terminated\ncode(%d)\n", code);
            break;
        case 9:
            printf("%s", p_string);
            printf("Missing quotes.\ncode(%d)\n", code);
            break;
        case 10:
            printf("%s", p_string);
            printf("Use: LOCATE var_x, var_y: .\ncode(%d)\n", code);
            break;
        case 11:
            printf("%s", p_string);
            printf("Useage LET (variable assignment):\ncode(%d)\n", code);
            break;
        case 12:
            printf("\nExpected %s ",t_holder);
            printf(": in line: %d.\n", (line_ndx+1));
            printf("%scode(%d)\n", p_string, code);
            break;
        case 13:
            printf("\nVariable not found: in line: %d.\n", (line_ndx+1));
            printf("%scode(%d)\n", p_string, code);
            break;
        case 14:
            printf("\nInvalid operator: in line: %d.\n", (line_ndx+1));
            printf("%scode(%d)\n", p_string, code);
            break;
        case 15:
            printf("%s {value} not found.\n%s", t_holder, p_string);
            printf("code(%d)\n", code);
            break;
        case 16:
            printf("\nFOR NEXT error: in line: %d.\n", (line_ndx+1));
            printf("NEXT without a FOR.\nNEXT %s", p_string);
            printf("code(%d)\n", code);
            break;
        case 17:
            printf("\nIF:Operand Type error: in line: ");
            printf("%d.\n%s\nNot a valid ", (line_ndx+1), p_string);
            printf("variable type.\ncode(%d)\n", code);
            break;
        case 18:
            printf("\nRelational Operator Type error: in line: ");
            printf("%d.\n%s\nValid operators:", (line_ndx+1), p_string);
            printf(" =<> .\ncode(%d)\n", code);
            break;
        case 19:
            printf("\nINPUT : error: in statement: %d.\n",(line_ndx+1));
            printf("INPUT %sUsage: INPUT \"Enter your ", p_string);
            printf("name\"; name$:\ncode(%d)\n", code);
            break;
	 case 20:
            printf("\nOPEN : error: in statment: %d. \n", (line_ndx+1));
            printf("%s\tOPEN %sUsage: OPEN \"I\", #1, ", xstring, p_string);
            printf("\"filename\"\ncode(%d)\n", code);
            break;
        case 21:
            printf("\nINPUT :error: in statement: ");
            printf("%d.\n\tCINPUT %s%s", (line_ndx+1), p_string, xstring);
            printf("Usage: INPUT#1, input$, (var,,)\ncode(%d)\n", code);
            break;
        case 22:
            printf("\nCLOSE : error: in statement: ");
            printf("%d.\n\tCLOSE %s%s", (line_ndx+1), p_string, xstring);
            printf("Usage: CLOSE 1, (handle,,)\ncode(%d)\n", code);
            break;
         case 23:
            printf("\nIF EOF : error: in statement: ");
            printf("%d.\n\tIF %s%s", (line_ndx+1), p_string, xstring);
            printf("Usage: IF EOF(1) THEN....\ncode(%d)\n", code);
            break;
        case 100:
            printf("code(%d)\n",code);
            break;
        case 101:
             break;
        case 102:
            printf("Engine.exe not found.\n");
             break;
        case 103:
             printf(" %d.\n%s",code,p_string);
            printf("Unknown Command.\ncode(%d)\n", code);
            break;
        default:
            printf("Program aborted, undefined error.");
            break;
    }
    exit(1);
}
/*-------------------------------*/

