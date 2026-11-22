/* bxbasic : Prototyp.h : alpha version */
/* ----- function prototypes ----- */

/*	Input.c		*/
    void line_cnt(char *argv[]);
    void clr_arrays(void);
    void load_src(void);
    void save_tmp(void);
     int iswhite(int);
    void loader_1(void);
    void loader_2(void);
    void tmp_label(int);
    void tmp_byte(int);
    void tmp_prog(int);
    void token_if(int);
    void str_functn(int);
    void str_funct2(int);
     int get_byte(int);
    void get_MOD(int);
     int find_strng(char *);
     int get_upper(int,int);
     int IsEqu(int);
    void get_strfunc(char *,int);
    void get_mathfunc(char *,int);
    void str_copy(char *,int);
    void beep(void);



/* 	Error.c		*/
    void a_bort(int,int);

/*	Output.c	*/
    void cls(void);
    void get_prnstring(void);
    void get_prnvar(void);
    void locate(void);
    char *value2strng(double);
    void get_strvar(void);
    void parse_print(void);
    void reset_cursor(int,int,int,int);
    void set_TabNl(int);
     int cursor_col(void);
     int cursor_row(void);
    void prn_strfunc(void);
    void proc_digit(void);


/*	Utility.c	*/
     int get_alpha(int,int);
     int get_digit(int,int);
     int iswhiter(int);
     int get_paren(int,int);
     int get_NextOp(int);
    char *get_varname(void);
  double get_avalue(void);
  double get_varvalue(void);

/*	Strings.c	*/
    void parse_str(char *);
    void strng_assgn(void);
    void strvar_assgn(void);
    void asn_function(void);
    void chrstr(void);
    void leftstr(void);
    void rightstr(void);
    void midstr(void);
    void spacestr(void);
    void strsval(void);
    void stringstr(void);
     int get_strndx(void);
    char *str_express(void);
    void inkeystr(void);
    void inputstr(void);
    void parse_strarry(char *);


/*	Variable.c	*/
    void parse_let(void);
     int get_varndx(char *);
    void init_int(void);
    void init_dbl(void);
    void init_lng(void);
    void init_flt(void);
    void init_str(void);
    void clr_vars(void);
    void clr_int(void);
    void clr_dbl(void);
    void clr_lng(void);
    void clr_flt(void);
    void clr_str(void);
    void parse_clr(void);
    void clr_indvar(char *);
    void do_dim(void);
    void dim_strarry(char *,int,int);
    void parse_intarry(char *);
    void parse_fltarry(char *);
    void parse_dblarry(char *);
    void dim_intarry(char *,int,int);
    void dim_fltarry(char *,int,int);
    void dim_dblarry(char *,int,int);
     int get_edit (int);


/*	Rdparser.c	*/
  double rdp_main(void);
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
  double math_functn(void);
  double get_ABS(void);
  double get_ASC(void);
  double get_ATN(void);
  double get_COS(void);
  double get_SIN(void);
  double get_TAN(void);
  double get_SQRT(void);
  double get_INT(void);
    long get_CLOCK(void);
    void let_int(char *);
    void let_long(char *);
    void let_single(char *);
    void let_double(char *);
  double let_intarray(char *);
  double let_fltarray(char *);
  double let_dblarray(char *);


/*       Loops.c        */
    void do_for(void);
    void do_next(void);
     int get_From(void);
    long get_To(void);
     int get_Step(void);


/*       Ifendif.c        */
    void do_if(void);
     int boolexpress(void);
     int Nboolterm(int);
     int Nrelation(double);
     int eval_value(double,double,int);
     int AndOrBoolExp(void);
     int IsAndOrOp(void);
     int Sboolterm(int);
     int Srelation(char *);
     int eval_string(char *,char *,int);
     int get_type(void);
     int get_string(void);
    void get_qstring(void);
     int get_op(void);
     int find_endif(int);
     int find_else(int);
     int if_eof(void);
     int is_eof(void);


/*       Getinput.c        */
    void get_input(void);
    void input_str(char *,int);
    void input_val(char *,int);
    void get_lninput(void);


/*       Fileio.c	      */
    void clr_iohandles(void);
    void parse_open(void);
    void get_iomode(int);
    void fopen_short(char, int, int);
    void do_fclose(void);
    void input_io(void);
    void get_finput(int, int);
    void read_fstring(int, char *);
    void read_fvalue(int, char *);
    void write_io(void);
    void get_foutput(int, int);
     int write_fstring(int, int, char *);
     int write_fvalue(int, int, char *);


