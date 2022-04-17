
#define zgui    1

#include "c2z_time.h"

   char test[15];
   char abc[20];
   char name[20];
   char addr[20];
   char f_date[11];
   char f_mth[3];
   char f_day[3];
   char f_yr[5];

   char f_time[9];
   char f_hr[3];
   char f_min[3];
   char f_sec[3];


   int  xyz;

  void Get_date(void);
  void Get_time(void);


int main()
{

/* map definitions */

  fsdefine(MAP0);

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(Date: )
    fsloc(1,03)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(V)
    fsname(f_date)
    fsloc(1,09)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(C Test Program)
    fsloc(1,30)
    fscolor(WHITE)
  };


  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(Time: )
    fsloc(1,64)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(V)
    fsname(f_time)
    fsloc(1,70)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(MAP0)
    fsloc(2,34)
    fscolor(GREEN)
  };


  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(Enter Name:)
    fsloc(4,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(I)
    fstype(V)
    fsname(name)
    fsloc(4,25)
    fscolor(WHITE)
    fsattr(IC)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(V)
    fsname(test)
    fsloc(9,60)
    fscolor(GREEN)
  };

 fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(Enter Address:)
    fsloc(5,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(I)
    fstype(V)
    fsname(addr)
    fsloc(5,25)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(Enter City:)
    fsloc(6,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(Enter State:)
    fsloc(7,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(Enter Zip:)
    fsloc(8,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(V)
    fsname(abc)
    fsloc(10,60)
    fscolor(RED)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(V)
    fsname(xyz)
    fsloc(11,60)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(test hello world)
    fsloc(12,60)
    fscolor(YELLOW)
  };

 fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(Enter = Next Screen)
    fsloc(24,05)
    fscolor(RED)
  };


 fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(PF3 = Exit)
    fsloc(24,27)
    fscolor(RED)
  };

  fsaid = 
  {
    fsaid_map(MAP0)
    fsaid_attr(PF3)
    fsaid_label(end_prog)
  };

/* end of MAP0 map definitions */


  fsdefine(MAP1);

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(Date: )
    fsloc(1,03)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(V)
    fsname(f_date)
    fsloc(1,09)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(C Test Program)
    fsloc(1,30)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(Time: )
    fsloc(1,64)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(V)
    fsname(f_time)
    fsloc(1,70)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP0)
    fsio(O)
    fstype(L)
    fsname(MAP1)
    fsloc(2,34)
    fscolor(GREEN)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(Name:)
    fsloc(4,14)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(V)
    fsname(name)
    fsloc(4,25)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(MAP1 testing...)
    fsloc(12,10)
    fscolor(RED)
  };

 fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(PF3 = Exit)
    fsloc(24,10)
    fscolor(RED)
  };

 fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(PF7 = SCREEN)
    fsloc(24,25)
    fscolor(RED)
  };

  fsaid = 
  {
    fsaid_map(MAP1)
    fsaid_attr(PF7)
    fsaid_label(start_prog)
  };


/* end of MAP1 map definitions */

  strcpy(test, "THIS IS A TEST");
  strcpy(abc,"Tom Chandler");

  xyz = 1234;


start_prog:

  Get_date();
  Get_time();
  fsdisplay(MAP0);
  fsread(MAP0);


  Get_date();
  Get_time();
  fsdisplay(MAP1);

  strcpy(test,"2nd TIme");

  fsread(MAP1);

end_prog:

}

void Get_date()
{
  char tmp_var2[2];
  char tmp_var4[4];
  char date[8];
 
  date = *localtime("date");

  strcpy(f_date, tm[0].tm_mon);
  strcat(f_date, "-");
  strcat(f_date, tm[0].tm_mday); 
  strcat(f_date, "-");          
  strcat(f_date, tm[0].tm_year); */
}


void Get_time()
{
  char tmp_var2[2];
  char tmp_var4[4];
  char time[8];

  time = *localtime("time");

  strcpy(f_time, tm[0].tm_hour);
  strcat(f_time, ":");
  strcat(f_time, tm[0].tm_min);
  strcat(f_time, ":");
  strcat(f_time, tm[0].tm_sec);
}
