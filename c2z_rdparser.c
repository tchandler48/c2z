/* **********************************************
 * cmsbasic : Rdparser.c : alpha version.20.3.1 *
 * Copyright:(c) sarbayo, 2001-2011             *
 * special credits to: Jack Crenshaw's:         *
 * "How to Build a Compiler"                    *
 * Modified T. Chandler CMSBASIC - CMSBRDP.c    *
 * ******************************************** */


int rdp_main()		
{   
   int value;

   value = Expression();
   return value;
}
/*---------- end rdp_main ----------*/


int Expression()	
{
   char ch;
   int pi;
   int Value;

   pi = e_pos;
   ch = p_string[pi];
   if(IsAddop(ch))
   {               
     Value = 0;  
   }
   else
   {
     Value = Term();
     pi = e_pos;
     ch = p_string[pi];
   }

   while(IsAddop(ch))
   {
     switch(ch)
     {
        case '+':
          Match('+');
          Value = Value + Term();
          break;
    
        case '-':
          Match('-');
          Value = Value - Term();
          break;

        default:
          break;
     }
     pi = e_pos;
     ch = p_string[pi];
  }
  return Value;
}
/*---------- end Expression ----------*/


int Term()		
{   
   char ch;
   int pi;
   int Value;

   Value = Factor();
   pi = e_pos;
   ch = p_string[pi];
   while(IsMultop(ch))
   {
     switch(ch)
     {
        case '*':
          Match('*');
          Value = Value * Factor();   
          break;
    
        case '/':
          Match('/');
          Value = Value / Factor();   
          break;

        case '^':
          Match('^');
          Value = pow(Value, Factor()); 
          break;

        case '%':
          Match('%');
          Value = (int) Value % (int) Factor();     
          break;

        default:
          break;
     }
     pi = e_pos;
     ch = p_string[pi];
  }
  return Value;
}
/*---------- end Term ----------*/


int Factor()                        
{   
   char ch;
   int pi;
   int value;

   pi = e_pos;
   ch = p_string[pi];
   if(ch == '(')
   {
     Match('(');
     value = Expression();
     Match(')');
   }
   else
   {
      value = GetNum();
   }
  }
  return value;
}
/*---------- end Factor ----------*/


void Match(char x)             
{   
   char ch, string[6];
   int pi, ab_code=12, ln=line_ndx;

   pi = e_pos;
   ch = p_string[pi];
   if(ch != x)
   {
     strcpy(string, "\" \"");
     string[1] = x;
     strcpy(t_holder, string);
     a_bort(ab_code,ln);
   }
   else
   {
     _GetChar();
     SkipWhite();
   }
}
/*---------- end Match ----------*/


void _GetChar()
{
  e_pos++;
}
/*---------- end _GetChar ----------*/


int Is_White(char ch)
{   
   int test=0;

   if((ch == ' ') || (ch == '\t'))
   {
     test = -1;
   }
   return test;
}
/*---------- end Is_White ----------*/


void SkipWhite() 	
{   
   char ch;
   int pi;

   pi = e_pos;
   ch = p_string[pi];
   while(Is_White(ch))
   {
     _GetChar();
     pi = e_pos;
     ch = p_string[pi];
   }
}
/*---------- end SkipWhite ----------*/


int GetNum()			
{   
   char ch;
   int pi, ab_code=12, ln=line_ndx;
   int Value=0;

   pi = e_pos;
   ch = p_string[pi];
   if((! isdigit(ch)) && (ch != '.'))
   {
     strcpy(t_holder, "Numeric Value");
     a_bort(ab_code,ln);
   }
   while(isdigit(ch))
   {
     Value = 10 * Value + ch - '0';
     _GetChar();
     pi++;
     ch = p_string[pi];
   }
   e_pos = pi;
   SkipWhite();
   return Value;
}
/*---------- end GetNum ----------*/


int IsAddop(char ch) 		
{   
   int rval=0;

   if((ch == '+') || (ch == '-'))
   {
     rval = 1;
   }
   return rval;
}
/*---------- end IsAddop ----------*/


int IsMultop(char ch) 		
{   
   int rval=0;

   if((ch == '+') || (ch == '/'))
   {
     rval = 1;
   }
   return rval;
}
/*---------- end IsMultop ----------*/


int double asc_2_dbl()
{   
   char ch, cvalue[33];
   int pi, vi_pos=0;
   double fvalue;

   pi = e_pos;
   ch = p_string[pi];
   while((isdigit(ch)) || (ch == '.') && (vi_pos <= 32))
   {
     cvalue[vi_pos] = ch;
     pi++;
     vi_pos++;
     ch = p_string[pi];
   }
   cvalue[vi_pos] = '\0';
   fvalue = atof(cvalue);                 
   e_pos = pi;
   return fvalue;
}
/*------- end asc_2_dbl ---------*/


/*
double get_LEN()
{   char ch, varname[VAR_NAME];          
    int pi, ndx, len, strnglen=0;        
    int type, indx, offset, nDims;
    int *Subscripts;
    double value=0;


    len = strlen(p_string);
    pi = e_pos;
 
    ch = p_string[pi];
    while((strchr("()", ch) == 0) && (pi < len))
    {
        pi++;
        ch = p_string[pi];
    }

    if(pi < len)
    {
        pi++;
        pi = iswhite(pi);
        ch = p_string[pi];

        if(isalpha(ch))
        {
            e_pos = pi;
            strcpy(varname, get_varname());
            type = get_objtype(pi);

            switch(type)
            {
                case 0:                     
                    if(callFlag == 0)
                    {
                        ndx = get_vndx(varname);
                    }
                    else
                    {
                        ndx = get_llvarndx(varname);     
                    }

                    strnglen = strlen(Gtbl[ndx].Str);
                    pi = e_pos;
                    break;
                case 6:                     
                    indx = get_arrayndx(varname);

                    Subscripts = &strArry[indx].sub[0];  
                    nDims = strArry[indx].dim;           
                    pi = e_pos;

                    ch = p_string[pi];
                    while((strchr("()", ch) == 0) && (pi < len))
                    {
                      pi++;
                      ch = p_string[pi];
                    }

                    pi++;
                    e_pos = pi;

                    offset = get_offset2(Subscripts, nDims, len);

                    strnglen = strlen(strArry[indx].elem[offset]);
                    break;
            }
        }
        else
        {
            pi++;
            ch = p_string[pi];

            while((ch != '\"') && (pi < len))
            {
                strnglen++;
                pi++;
                ch = p_string[pi];
            }
        }
    }

    e_pos = pi;
    value = (double) strnglen;

    return value;
}
*/
/*---------- end get_LEN ----------*/


/*
double get_LOC()
{   int ndx, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=30;
    long fil_rcrd;                
    double value;
    FILE *handle;


    value = Factor();                        
    ndx = (int) value;
    ndx--;

    err_hndlr(ab_code, x, 3, ndx, maxfiles);   
    err_hndlr(ab_code, x, 9, ndx, 0);         

    handle = fp[ndx].fptr;
    fil_rcrd = ftell(handle);
    value = (double) fil_rcrd;

    return value;
}
*/
/*---------- end get_LOC ----------*/


/*
double get_LOF()
{   int ndx, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=31;
    long offset;
    double value;
    FILE *handle;


    value = Factor();                         
    ndx = (int) value;
    ndx--;

    err_hndlr(ab_code, x, 3, ndx, maxfiles);   
    err_hndlr(ab_code, x, 9, ndx, 0);         

    handle = fp[ndx].fptr;
    fseek(handle, 0L, SEEK_END);
    offset = ftell(handle);
    value = (double) offset;

    return value;
}
*/
/*---------- end get_LOF ----------*/


/*
double get_CVD()
{   double value;        
                        

    value = Factor();

    return value;
}
*/
/*---------- end get_CVD ----------*/
