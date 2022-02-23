   #define BUFSIZE     100
   #define MAX_VARS    90
   #define VAR_NAME    33
 
   char r_string[BUFSIZE];
   char fielda[10];
   char fieldc[10];
   char varname[32];
   int  fieldb;
   int  I;
   int  len;
   int  xyz;
   int  def;
   int  ghi;
   int  jkl;
   int  mno;
   int  pqr;
  
   char sn_stack[MAX_VARS][VAR_NAME];
   char sv_stack[MAX_VARS][VAR_NAME];

   char in_stack[MAX_VARS][VAR_NAME];
    int iv_stack[MAX_VARS];
 
	
int main(int argc, char *argv[])
{

  printf("Hello Z390 World\n");

  strcpy(fielda, "abcdefghi");
  printf("fielda = %s",fielda);

  len = strlen(fielda);
  printf("len fielda = %d\n",len);

  I = 0;
  strcpy(varname, "fielda");
  strcpy(sv_stack[I], varname);
  strcpy(sv_stack[I],fielda);


  xyz = 12;
  printf("xyz = %d\n",xyz);
  I = 0;

  iv_stack[I] = xyz;
  strcpy(in_stack[I], "xyz");

  def = 4;
  printf("def = %d\n",def);
  I = 1;
  iv_stack[I] = def;
  strcpy(in_stack[I], "def");

  ghi = xyz + def;
  printf("ghi = %d\n",ghi);
  I = 2;
  iv_stack[I] = ghi;
  strcpy(in_stack[I], "ghi");

  jkl = xyz - def;
  printf("jkl = %d\n",jkl);
  I = 3;
  iv_stack[I] = jkl;
  strcpy(in_stack[I], "jkl");

  mno = xyz * def;
  printf("mno = %d\n",mno);
  I = 4;
  iv_stack[I] = mno;
  strcpy(in_stack[I], "mno");

  pqr = xyz / def;
  printf("pqr = %d\n",pqr);
  I = 5;
  iv_stack[I] = pqr;
  strcpy(in_stack[I], "pqr");

  pqr = iv_stack[0] + 4; 
  printf("pqr #1 stack = %d\n",pqr);

  I = 0;
  pqr = iv_stack[I] + 2;
  printf("pqr #2 stack = %d\n",pqr);

  printf("iv_stack[1] = %d\n",iv_stack[1]); 
  pqr = 6 + iv_stack[1];
  printf("pqr #3 stack = %d\n",pqr); 


  for(I=0; I < 6; I++)
  {
    printf("sv_stack = %s\n",sv_stack[I]);
  }



}
