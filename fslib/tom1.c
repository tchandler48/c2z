
#define zgui    1

#include "c2z_time.h"

   char test[15];
   char name[20];
   char addr[30];

   char f_date[11];
   char f_mth[3];
   char f_day[3];
   char f_yr[5];

   char f_time[9];
   char f_hr[3];
   char f_min[3];
   char f_sec[3];

  void Get_date(void);
  void Get_time(void);

  fsdefine(STREAM);

  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(L)
    fsname(Date: )
    fsloc(1,03)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(V)
    fsname(f_date)
    fsloc(1,09)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(L)
    fsname(C Test Program)
    fsloc(1,30)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(L)
    fsname(Time: )
    fsloc(1,64)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(V)
    fsname(f_time)
    fsloc(1,70)
    fscolor(WHITE)
  };


  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(L)
    fsname(STREAM)
    fsloc(2,34)
    fscolor(GREEN)
  };


  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(L)
    fsname(Enter Name:)
    fsloc(4,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(STREAM)
    fsio(I)
    fstype(V)
    fsname(name)
    fsloc(4,25)
    fscolor(WHITE)
    fsattr(IC)
  };

  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(L)
    fsname(Enter Address:)
    fsloc(5,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(STREAM)
    fsio(I)
    fstype(V)
    fsname(addr)
    fsloc(5,25)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(L)
    fsname(Enter City:)
    fsloc(6,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(L)
    fsname(Enter State:)
    fsloc(7,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(STEAM)
    fsio(O)
    fstype(L)
    fsname(Enter Zip:)
    fsloc(8,10)
    fscolor(BLUE)
  };


 fsfield =
  {
    fsmap(STREAM)
    fsio(O)
    fstype(L)
    fsname(PF3 = Exit)
    fsloc(24,10)
    fscolor(RED)
  };

  fsaid = 
  {
    fsaid_map(STREAM)
    fsaid_attr(PF3)
    fsaid_label(end_prog)
  };



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
    fsmap(MAP1)
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
    fsloc(4,10)
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
    fsname(Address:)
    fsloc(5,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(V)
    fsname(addr)
    fsloc(5,25)
    fscolor(WHITE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(City:)
    fsloc(6,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(State:)
    fsloc(7,10)
    fscolor(BLUE)
  };

  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(Zip:)
    fsloc(8,10)
    fscolor(BLUE)
  };


  fsfield =
  {
    fsmap(MAP1)
    fsio(O)
    fstype(L)
    fsname(PF7 = SCREEN)
    fsloc(24,10)
    fscolor(RED)
  };

  fsaid = 
  {
    fsaid_map(MAP1)
    fsaid_attr(PF7)
    fsaid_label(start_prog)
  };


int main()
{
  

start_prog:

  Get_date();
  Get_time();
  fsdisplay(STREAM);
  fsread(STREAM);

  Get_date();
  Get_time();
  fsdisplay(MAP1);
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
