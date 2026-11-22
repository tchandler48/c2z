  
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

int main(int argc, char *argv[])
{
  
  printf("Start of tom2\n");
  fsdisplay(STREAM);
  fsread(STREAM);

  fsdisplay(MAP1);
  fsread(MAP1);
  

}

