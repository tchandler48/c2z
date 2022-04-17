/* bxbasic : fileio.c  */


void clr_iohandles()
	{
		int ii;

		for(ii=0; ii< IOARRAY; ii++)		/* clear all file handles */
			{
				fp[ii].path[0] = '\0';	/* reset "path" to 0 */
				fp[ii].mode = '\0';
				fp[ii].fptr = '\0';
			}
	}


void parse_open()
	{
		int pi, len, ab_code=20, x=line_ndx;

		len = strlen(p_string);
		pi = e_pos;
		pi = get_upper(pi, len);
		/* ----------------------- OPEN "I", #1, "path"  */
		if(pi < len)
			{
				e_pos = pi;
				get_iomode(len);
			}
		/*( ---------------------- if not an alpha, abort */
			else
			{
				strcpy(xstring, "Invalid Open Mode:");
				a_bort(ab_code, x);		/* ie: not: "I", #1, "path" */
			}
	}


void get_iomode(int len)
	{
		char ch, io_mode;
		int pi, ndx, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=20;
		double fileno;

		pi = e_pos;
		ch = p_string[pi];
		io_mode = ch;
		pi = get_digit(pi, len);
		if(pi == len)				/* at end of line */
			{
				strcpy(xstring, "Invalid File Format:");
				a_bort(ab_code, x);
			}
			else
			{
				e_pos = pi;
				fileno = get_avalue();
				ndx = (int) fileno;
				ndx--;
				if((ndx < 0) || (ndx > maxfiles))		/* if it's out of range, abort */
					{
						strcpy(xstring, "Invalid File Number:\n1 to 99:");
						a_bort(ab_code, x);
					}
					else if(fp[ndx].path[0] != '\0')	/* if it's not closed, abort */
						{
							strcpy(xstring, "File Number In Use:");
							a_bort(ab_code, x);
						}
					else 
						{
							fopen_short(io_mode, ndx, len);
						}
			}
	}

void fopen_short(char io_mode, int ndx, int len)
	{
		char ch, quote='\"', io_path[PATH];
		int pi, indx, x=line_ndx, ab_code=20;
		FILE *handle;

		pi = e_pos;
		ch = p_string[pi];
		while((ch != quote) && (isalpha(ch) == 0) && (pi < len))
			{
				pi++;				/* advance to: quote or alpha char */
				ch = p_string[pi];		/* "filename" or filename$         */
			}
		if(pi == len)
			{
				strcpy(xstring, "Invalid File Name:");
				a_bort(ab_code, x);
			}
		e_pos = pi;
		if(ch == quote)				/* OPEN "I", #1, "path" */
			{
				strng_assgn();
				strcpy(io_path, s_holder);
			}
			else					/* OPEN "I", #1, pathname$ */
			{
				indx = get_strndx();
				strcpy(io_path, sv_stack[indx]);
			}
		pi = e_pos;
		fp[ndx].mode = io_mode;
		strcpy(fp[ndx].path, io_path);
		/* ----- now open file for I/O-'type' ---- */
		switch(io_mode)
			{
				case 'I':				/* open file for input */
					handle = fopen(io_path, "r");	/* open file for Input */
					strcpy(xstring, "File Not Found:");
					break;
				case 'O':				/* open ffile for output */
					handle = fopen(io_path, "w");
					strcpy(xstring, "Unable to Open FIle:");
					break;
				case 'A':				/* open file for append */
					handle = fopen(io_path, "a");
					strcpy(xstring, "Unable to Open FIle:");
					break;
				default:
					strcpy(xstring, "Invalid Mode:\t I,O,A,R: \n");
					a_bort(ab_code, x);
			}
		/* --------- */
		if(handle == NULL)
			{
				a_bort(ab_code, x);			/* could not be open  */
			}
			else
			{
				fp[ndx].fptr = handle;
			}
	}


void do_fclose()
	{
		char ch;
		int ii, pi, ndx, len, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=22;
		double fileno;
		FILE *handle;

		len = strlen(p_string);
		pi = e_pos;
		pi = get_digit(pi, len);
		if(pi == len)						/* clear all file handles */
			{
				for(ii=0; ii<IOARRAY; ii++)
					{
						if(fp[ii].path[0] != '\0')	/* if path[0] != \0, it's open */
							{
								handle = fp[ii].fptr;
								fclose(handle);
								fp[ii].path[0] = '\0';	/* reset "path" to 0 */
								fp[ii].mode = '\0';
								fp[ii].fptr = '\0';
							}
					}
			}
			else
			{
				ch = p_string[pi];
				while(pi < len)
					{
						if(isdigit(ch) == 0)
							{
								pi = get_digit(pi, len);
							}
						if(pi < len)
							{
								e_pos = pi;
								fileno = get_avalue();
								ndx = (int) fileno;
								ndx--;
								if((ndx < 0) || (ndx > maxfiles))
									{
										strcpy(xstring, "Invalid File Number:\t1 to 99:\n");
										a_bort(ab_code, x);		/* if it's out of range, abort */
									}
									else if(fp[ndx].path[0] != '\0')		/* if path[0] != 0 */
										{
											handle = fp[ndx].fptr;	/* it's open */
											fclose(handle);
											fp[ndx].path[0] = '\0';	/* reset "path" to 0 */
											fp[ndx].mode = '\0';
											fp[ndx].fptr = '\0';
										}
									pi = e_pos;
							}
					}
			}
	}


void input_io()
	{
		int pi, port, len, maxfile=(IOARRAY-1), x=line_ndx, ab_code=21;
		double fileno;

		len = strlen(p_string);
		pi = e_pos;
		pi = get_digit(pi, len);
		if(pi == len)				/* at end of line */
			{
				strcpy(xstring, "Invalid Input Format:");
				a_bort(ab_code, x);
			}
			else
			{
				e_pos = pi;
				fileno = get_avalue();
				port = (int) fileno;
				port--;
				if((port < 0) || (port > maxfile))
					{
						strcpy(xstring, "Invalid File Number:\t1 to 99:\n");
						a_bort(ab_code, x);		/* if it's out of range, abort */
					}
					else if(fp[port].mode != 'I')
						{
							strcpy(xstring, "FILE is not Open for INPUT:\n");
							a_bort(ab_code, x);		/* file not opened for Input */
						}
						else
						{
							get_finput(port, len);
						}
			}
	}
                           

void get_finput(int port, int len)
	{
		char ch, varname[VAR_NAME];
		int pi, type;

		pi = e_pos;
		ch = p_string[pi];
		while((pi < len) && (ch != '\n'))  		/* process up to line terminator */
			{
				if(isalpha(ch) == 0)
					{
						pi = get_alpha(pi, len);
						ch = p_string[pi];
					}
				if(pi < len)
					{
						e_pos = pi;
						type = get_vtype(pi);
						e_pos = pi;
						strcpy(varname, get_varname());
						if(type == 3)			/* a string$ assignment */
							{
								read_fstring(port, varname);
							}
							else			/* type==0/1: numeric assignment */
							{
								read_fvalue(port, varname);
							}
						pi = e_pos;
						ch = p_string[pi];
					}
			}
	}


void read_fstring(int port, char *name)
	{
		char chIn='\0', varname[VAR_NAME], temp[BUFSIZE];
		int ii=0, ndx=0, indx=0, xsize;
		FILE *handle;

		strcpy(varname, name);
		nam_stack = sn_stack;		/* indirect ref. to name_stack */
		max_vars = smax_vars;
		init_fn = init_str;			/* indirect ref.to function */
		ndx = get_varndx(varname);

/* ----------    read file input -------------- */
		handle = fp[port].fptr;
		while((chIn != '\"') && (!feof(handle)))
			{
				ii = fgetc(handle);
				chIn = (char) ii;
			}
		chIn = '\0';
		if(!feof(handle))
			{
				while((chIn != '\"') && (!feof(handle)))
					{
						ii = fgetc(handle);
						chIn = (char) ii;
						if(chIn != '\"')
							{
								temp[indx] = chIn;
								indx++;
							}
					}
			}
		temp[indx] = '\0';

/* ----------- Save data --------------- */
		xsize = strlen(temp);
		xsize++;
		sv_stack[ndx] = realloc(sv_stack[ndx], xsize * sizeof(char));
		strcpy(sv_stack[ndx], temp);			/* save new string */
	}


void read_fvalue(int port, char *name)
	{
		char chi='\0', varname[VAR_NAME], temp[BUFSIZE];
		int pi, type, ii=0, ndx=0, indx=0;
		FILE *handle;

		strcpy(varname, name);
		pi = e_pos;
		type= get_vtype(pi);

	/* --------  get var-type index --------- */
		if(type == 4)				/* double float */
			{
				nam_stack = dn_stack;
				max_vars = dmax_vars;
				init_fn = init_dbl;
			}
			else if(type == 3)		/* single float */
				{
					nam_stack = fn_stack;
					max_vars = fmax_vars;
					init_fn = init_flt;
				}
			else if(type == 2)		/* long integer */
				{
					nam_stack = ln_stack;
						max_vars = lmax_vars;
					init_fn = init_lng;
				}
			else 				/* type 0/1  integer  */
				{
					nam_stack = ln_stack;
					max_vars = lmax_vars;
					init_fn = init_int;
				}
			ndx = get_varndx(varname);
			/* ----- read file data ------------ */
			handle = fp[port].fptr;
			while((isdigit(chi) == 0) && (!feof(handle)))
				{
					ii = fgetc(handle);		/* get digit or: . or: - */
					chi = (char) ii;
					if((chi == '-') || (chi == '.'))
						{
							temp[indx] = chi;
							indx++;
						}
				}
			while((isdigit(chi) != 0) || (chi =='.') && (!feof(handle)))
				{
					temp[indx] = chi;
					indx++;
					ii = fgetc(handle);
					chi = (char) ii;
				}
			temp[indx] = '\0';

	/* --------------- store data ------------ */

			if(type == 4)
				{
					dv_stack[ndx] = (double) atof(temp);
				}
			else if(type == 3)
				{
					fv_stack[ndx] = atof(temp);
				}
			else if(type == 2)
				{
					lv_stack[ndx] = atol(temp);
				}
			else 
				{
					iv_stack[ndx] = atoi(temp);
				}
		}

void write_io()
	{
		char chmode;
		int pi, len, port, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=24;
		double fileno;

		len = strlen(p_string);
		pi = e_pos;
		pi = get_digit(pi, len);			/* WRITE#1, outpu$ */
		if(pi == len)					/* at end of line  */
			{
				strcpy(xstring, "Invalid Write Format:");
				a_bort(ab_code, x);	
			}
			else
			{
				e_pos = pi;
				fileno = get_avalue();
				port = (int) fileno;
				port--;
				chmode = fp[port].mode;	/* I?O mode */
				if((port < 0) || (port > maxfiles))
					{
						strcpy(xstring, "Invalid File Number:\t1 to 99:\n");
						a_bort(ab_code, x);		/* if it's out of range, abort */
					}
				else if((chmode != 'O') && (chmode != 'A'))
					{
						strcpy(xstring, "FILE not OPEN for OUTPUT:\n");
						a_bort(ab_code, x);		/* file not opened for Output or APPEND */
					}
				else
					{
						get_foutput(port, len);
					}
			}
	}

void get_foutput(int port, int len)
	{
		char ch, nl='\n', vaname[VAR_NAME];
		int pi, type, wflag=0, maxfiles=(IOARRAY-1), x=line_ndx, ab_code=24;
		double fileno;
		FILE *handle;

	}

