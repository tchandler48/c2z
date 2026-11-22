
void a_bort(int code, int line_ndx)
{
  switch(code)
  {
    case 1:
      printf("Unspecified Program Name\n");
      break;

   case 2:
     printf("Unspecified Program Name\n");
     break;

   case 3:
     printf("Syntax error in program line: = %d\n",line_ndx);
     break;

   case 4:
     printf("Syntax error in program line: = %d\n",line_ndx);
     break; 

   case 6:
     printf("Case 6 Error\n");
     break;

   case 7:
     printf("Case 7 Error\n");
     break;

   case 8:
     printf("Case 8 Error\n");
     break;

   case 9:
     printf("Case 9 Error Syntax error in program line: %d\n",line_ndx);
     break;

   case 10:
     printf("Case 10 Error\n");
     break;

   case 11:
     printf("Case 11 Error Syntax error in program line: = %d\n",line_ndx);
     break;

   case 12:
     printf("Case 12 Error Out of stack space line: = %d\n",line_ndx);
     break;

   case 13:
     printf("Case 13 Error Variable not found in line: %d\n",line_ndx);
     break;

   default:
printf("error.c code = %d\n",code);
printf("error.c p_string = %s",p_string);

     printf("Program aborted, undefined error.");
     break;
  }
  exit(1);
}


