/* bxbasic : Loops.c : alpha version */
/* ----- function prototypes ----- */
#include "prototyp.h"


void do_for()
{   char ch, varname[VAR_NAME];
    int pi, f_ndx, Inc=1, ab_code;
    int start, next_tru, x=line_ndx;
    long From, Final;

/* --- assign FROM --- */
    f_ndx = get_From();

/* --- get TO --- */
    Final = get_To();

/* --- get STEP --- */
    pi = e_pos;
    ch = p_string[pi];
    if(ch == 'S')
    {   Inc = get_Step();
    }

/* --- setup for-loop conditions --- */
    From = lv_stack[f_ndx];
    start = line_ndx;                       /* register: line counter */
    fornxt_flg++;                          /* increment For/Next flag */

/* --- increment loop --- */
    if(From < Final)
    {   for(; From <= Final; From += Inc)
        {   next_tru = 1;
            line_ndx = (start + 1);        /* set pointer to: here+1 */
            while(next_tru == 1)
            {   get_token();
                s_pos = 0;
                e_pos = 0;
                parser();
                if(token == 12)           /* encountered a: return */
                {   next_tru = 0;
                    token = 0;
                }
                else
                {   line_ndx++;
                }
            }
        }
    }
/* --- decrement loop --- */
    else
    {   for(; From >= Final; From += Inc)
        {   next_tru = 1;
            line_ndx = (start + 1);        /* set pointer to: here+1 */
            while(next_tru == 1)
            {   get_token();
                s_pos = 0;
                e_pos = 0;
                parser();
                if(token == 12)           /* encountered a: return */
                {   next_tru = 0;
                    token = 0;
                }
                else
                {   line_ndx++;
                }
            }
        }
    }
    fornxt_flg--;                          /* decrement For-Next flag */
}
/*-------- end do_for ----------*/

void do_next()
{   int ab_code=16, x=line_ndx;

    if(fornxt_flg == 0)
    {   a_bort(ab_code,x);
    }
}
/*-------- end do_next ---------*/

int get_From()
{   char ch, varname[VAR_NAME];
    int pi, f_ndx, sav_pi, ab_code, x=line_ndx;

    pi = e_pos;
    sav_pi = pi;

/* --- get varname --- */                   /* FOR x%=a TO b STEP c: */
    strcpy(varname, get_varname());
    pi = e_pos;
    ch = p_string[pi];
    if(ch != '%')                   /* variable type must be: long */
    {   ab_code=5;
        a_bort(ab_code, x);
    }

/* --- assign FROM --- */
    e_pos = sav_pi;
    parse_let();
    pi = e_pos;
    ch = p_string[pi];

/* --- get long array index --- */
    nam_stack = ln_stack;
    max_vars = lmax_vars;
    f_ndx = get_varndx(varname);

    return f_ndx;
}
/*-------- end get_from ----------*/

long get_To()
{   char ch, varname[VAR_NAME];
    int pi, ab_code, x=line_ndx;
    long Final;

    pi = e_pos;
    ch = p_string[pi];

/* --- get TO --- */
    if(ch != 'T')
    {   strcpy(t_holder,"TO");
        ab_code=7;
        a_bort(ab_code,x);
    }
    else
    {   strcpy(varname, get_varname());
        pi = e_pos;
        ch = p_string[pi];
        if(strcmp(varname, "TO") != 0)
        {   strcpy(t_holder,"TO");
            ab_code=7;
            a_bort(ab_code,x);
        }
    }
    pi = iswhite(pi);
    ch = p_string[pi];
    e_pos = pi;

/* --- get Final value --- */
    if(isalnum(ch))
    {   Final = (long) get_avalue();
    }
    else                       /* error: failed to find a value */
    {   strcpy(t_holder,"TO");
        ab_code=15;
        a_bort(ab_code, x);
    }
    return Final;
}
/*-------- end get_to ----------*/

int get_Step()
{   char ch, varname[VAR_NAME];
    int pi, Inc;
    int ab_code, x=line_ndx;
    char sav_ch=' ';

    strcpy(varname, get_varname());
    if(strcmp(varname, "STEP") != 0)
    {   strcpy(t_holder, "STEP");
        ab_code=7;
        a_bort(ab_code,x);
    }
    pi = e_pos;
    pi = iswhiter(pi);
    ch = p_string[pi];

/* --- get Inc value --- */
    if(IsAddop(ch))
    {   sav_ch = ch;
        pi++;
        pi = iswhiter(pi);
        ch = p_string[pi];
    }
    e_pos = pi;
    if(isalnum(ch))
    {   Inc = (int) get_avalue();
    }
    else                       /* error: failed to find a value */
    {   strcpy(t_holder,"STEP");
        ab_code=15;
        a_bort(ab_code, x);
    }
    if(sav_ch == '-')
    {   Inc = (0 - Inc);
    }

    return Inc;
}
/*-------- end get_Step ----------*/

