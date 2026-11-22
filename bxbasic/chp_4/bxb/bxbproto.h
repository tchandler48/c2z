/*	error.c 	*/
	void a_bort(int,int);

/*	input.c	*/
	void line_cnt(char *argv[]);
	void load_src(void);
	void save_tmp(void);
       void tmp_byte(int);	
	void loader_1(void);
       void tmp_label(int);
 	 int get_byte(int);
       void tmp_prog(inT);
	void loader_2(void);
	

/*	output.c	*/
	void beep(void);
	void cls(void);
	void get_prnstring(void);
	void get_prnvar(void);
	void locate(void);
       void get_strvar(void);
       char get_vartype(void);



/*	loop.c		*/
	void do_loop(void);
	void do_next(void);
	 int get_From(void);
	 int get_To(void);
	 int get_Step(void);
	 int get_avalue(void);

	

/* 	utility.c	*/
	 int get_upper(int,int);
	 int get_alpha(int,int);
	 int get_digit(int,int);
	 int iswhite(int);
       void clr_arrays(void);
	

/*	variable.c 	*/
	void parse_let(void);
     double get_varvalue(void);
	void string_value(void);
       char get_varname(void);
        int get_intndx(char *);
        int get_dblndx(char *);
       void clr_vars(void);
       void init_int(void);
       void clr_int(void);
       void init_dbl(void);
       void clr_dbl(void);
       void strng_assgn(int);
       void get_varndx(char *);


/*	rdparser.c	*/
     double rdp_start(void);
     double Expression(void);
     double Term(void);
     double Factor(void);
	void Match(char);
	void _GetChar(void);
     double GetNum(void);
	 int IsAddop(char);
	 int IsMultop(char);
	 int Is_White(char);
	void SkipWhite(void);
     double asc_2_dbl(void);

