   
  int xyz = 0;
 char abc[32];
 char xyz[32];


int main(int argc, char *argv[])
{
   printf("CTEST2 Begin\n");

   strcpy(abc, "1234");
   strcpy(xyz, "abcde");
   strcat(abc, xyz);
   printf("abc = %s\n",abc);

   printf("End of CTEST2\n");

}
