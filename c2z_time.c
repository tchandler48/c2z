/* ***************************************************
*  c2z : c2_time.c :                                 *
*                                                    *
*  Copyright TCCS (c) 2015 - 2021                    *
**************************************************** */


/* ***************************************************
*  Punch out TIME                                    *
* ************************************************** */
void c2_time()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_time.c c2_time");
				trace_rec_1();
			}

		if(z390 == 1)
			{

			}
	}


/* ***************************************************
*  Punch out time variables                          *
* ************************************************** */
void c2_compute_time()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "Pass_3 c2_compute_time ");
				trace_rec_1();
			}
		
		int size = 0;

		/*  put C370TIME & C370PWK into v_variable  */
		if((tot_localtime == 0) && (tot_time == 0))
			{
				if(gv_ct == 0)
					{
						size = 1;
						gw_variable = malloc(size * sizeof(struct variables));
					}
				else
					{
						size = gv_ct + 1;
						gw_variable = realloc(gw_variable, size * sizeof(struct variables));
					}
					
				gw_variable[gv_ct].gv_rct = rct;
				strcpy(gw_variable[gv_ct].gv_name, "C370TIME");
				strcpy(gw_variable[gv_ct].gv_type, "L");
				gw_variable[gv_ct].gv_lgth = 11;
				strcpy(gw_variable[gv_ct].gv_literal,"  hh:mm:ss");
				gw_variable[gv_ct].gv_dec = 0;
				gv_ct++;
			}
	}

