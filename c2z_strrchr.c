/* ***************************************************
*  c2z : c2z_strrchr.c :                             *
*                                                    *
*  Copyright TCCS (c) 2015 - 2018                    *
**************************************************** */
 
/* ***************************************************
*  Punch out STRRCHR                                 *
* ************************************************** */
void c2_strrchr()
	{
		if(trace_flag == 1)
			{
				strcpy(trace_1, "c2z_strrchr.c c2_strrchr");
				trace_rec_1();
			}

		check_semi(); 

		char ch;
		char field1[VAR_LGTH];
		char field2[VAR_LGTH];

		int pi;
		int pi2;
		int x3 = 0;
		int I = 0;
		int ret = 0;

		pi = 0;
		ch = p_string[pi];
		check_blank(); 

		pi2 = 0;
		while(ch != ' ')
			{
				field1[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			} 
		field1[pi2] = '\0';

		I = 0;
		x3 = 0;
		for(I=0; I < gv_ct; I++)
			{
				ret = strcmp(field1, gw_variable[I].gv_name);
				if(ret == 0)
					{
						x3 = 1;		
						break;
					}
			}

		if(x3 != 1)
			{
				printf("c2z_strrchr.c c2_strrchr field1 Not Found = %s\n",field1);
				printf("c2z_strrchr.c c2_strrchr rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
											
		ret = strcmp(gw_variable[I].gv_type, "C");
		if(ret != 0)
			{
				printf("c2z_strrchr.c c2_strrchr field1 Not Character = %s\n",field1);
				printf("c2z_strrchr.c c2_strrchr rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}

		pi++;
		ch = p_string[pi];
		while(ch != '(')
			{
				pi++;
				ch = p_string[pi];
			} 

		pi++;
		pi2 = 0;
		ch = p_string[pi];
		while(ch != ',')
			{
				field2[pi2] = ch;
				pi2++;
				pi++;
				ch = p_string[pi];
			} 
		field2[pi2] = '\0';

		I = 0;
		x3 = 0;
		for(I=0; I < gv_ct; I++)
			{
				ret = strcmp(field2,gw_variable[I].gv_name);
				if(ret == 0)
					{
						x3 = 1;		
						break;
					}
			}

		if(x3 != 1)
			{
				printf("c2z_strrchr.c c2_strrchr field2 Not Found = %s\n",field2);
				printf("c2z_strrchr.c c2_strrchr rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
											
		ret = strcmp(gw_variable[I].gv_type, "C");
		if(ret != 0)
			{
				printf("c2z_strrchr.c c2_strrchr field2 Not Character = %s\n",field2);
				printf("c2z_strrchr.c c2_strrchr rct = %d p_string = %s",rct,p_string);
				c2_debug();
				exit(1);
			}
	}


