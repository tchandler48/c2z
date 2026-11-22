
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
     printf("Case 3 Syntax error in program line: = %d\n",line_ndx);
     printf("Case 3 Variable p_string = %s\n",p_string);
     break;

   case 4:
     printf("Case 4 Syntax error in program line: = %d\n",line_ndx);
     printf("Case 4 Variable p_string = %s\n",p_string);
     break; 

   case 5:
     printf("Case 5 Error\n");
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
     printf("Case 9 Error\n");
     break;

   case 10:
     printf("Case 10 Error\n");
     break;

   case 11:
     printf("Case 11 Error\n");
     printf("Case 11 Variable p_string = %s\n",p_string);
     break;

   case 12:
     printf("Case 12 Error\n");
     break;

   case 13:
     printf("Case 13 Error\n");
     break;

   default:
     printf("Program aborted, undefined error.");
     break;
  }
  exit(1);
}


