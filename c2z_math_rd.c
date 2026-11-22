/* ***************************************************
*  c2z  : c2z_math_rd.c                              *
*                                                    *
*  Copyright TCCS (c) 2015 - 2020                    *
**************************************************** */

void c2_math_rdp(void)
{
  strcpy(trace_1, "c2z_eoj c2_math_rdp START");
  trace_rec_1();
 
   strcpy(a_string, "*");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #1");
   trace_rec_3();

   strcpy(a_string, "RDPSTART DS    0H");
   strcpy(wk_remark, " rdparser ");
   strcat(wk_remark, " */");
   write_remark();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #2");
   trace_rec_3();

   strcpy(a_string, "         ST    R14,SVSUB_1");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #3");
   trace_rec_3();

   printf("tc_string #33 = %s\n",tc_string);

   strcpy(a_string, "         ST    R1,tc_string");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #3");
   trace_rec_3();




/*
   44     c2z_strcpy.c c2_str_4 #1                 LARL  R9,C37F29                
2  44     c2z_strcpy.c c2_str_4 #2                 LARL  R8,C37F33               
2  44     c2z_strcpy.c c2_str_4 #3                 MVC2  C37F29,C37F33                                            0000184
*/
   work_use_ct[70]++;  


   strcpy(a_string, "         LARL  R9,MLF001");
   strcpy(wk_remark, " value ");
   strcat(wk_remark, " */ ");
   write_remark();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #4");
   trace_rec_3();
   work_use_ct[66]++;

   strcpy(a_string, "         LARL  R8,C370ZERO");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #5");
   trace_rec_3();

   strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #6");
   trace_rec_3();

   strcpy(a_string, "         BRAS  R14,RDP001");
   strcpy(wk_remark, " Expression ");
   strcat(wk_remark, " */ ");
   write_remark();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #7");
   trace_rec_3();

   strcpy(a_string, "         LARL  R9,MLF001");
   strcpy(wk_remark, " value ");
   strcat(wk_remark, " */ ");
   write_remark();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #8");
   trace_rec_3();
   work_use_ct[66]++;

   strcpy(a_string, "         LARL  R8,MLF002");
   strcpy(wk_remark, " Value ");
   strcat(wk_remark, " */");
   write_remark();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #9");
   trace_rec_3();
   work_use_ct[67]++;

   strcpy(a_string, "         ZAP   0(6,R9),0(6,R8)");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #20");
   trace_rec_3();

   strcpy(a_string, "         L     R14,SVSUB_1");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #11");
   trace_rec_3();

   strcpy(a_string, "         XR    R15,R15");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #12");
   trace_rec_3();

   strcpy(a_string, "         BR    R14");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #13");
   trace_rec_3();

   strcpy(a_string, "*");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #14");
   trace_rec_3();

   strcpy(a_string, "RDP001   DS    0H");
   strcpy(wk_remark, " Expression ");
   strcat(wk_remark, " */ ");
   write_remark();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #15");
   trace_rec_3();

   strcpy(a_string, "         ST    R14,SVSUB_2");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #16");
   trace_rec_3();

   strcpy(a_string, "         LARL  R8,MLF003");
   strcpy(wk_remark, " ch ");
   strcat(wk_remark, " */ ");
   write_remark();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #18");
   trace_rec_3();
   work_use_ct[68]++;

   strcpy(a_string, "         MVI   0(R8),C' '");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #19");
   trace_rec_3();

   strcpy(a_string, "         MVC   1(L'MLF003-1,R8),0(R8)");                             
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #20");
   trace_rec_3();

   strcpy(a_string, "         LARL  R8,MLF004");
   strcpy(wk_remark, " pi ");
   strcat(wk_remark, " */ ");
   write_remark();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #21");
   trace_rec_3();
   work_use_ct[69]++;

   strcpy(a_string, "         LARL  R7,C370ZERO");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #22");
   trace_rec_3();
   work_use_ct[32]++;

   strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #23");
   trace_rec_3();

   strcpy(a_string, "         LARL  R8,MLF002");
   strcpy(wk_remark, " Value ");
   strcat(wk_remark, " */ ");
   write_remark();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #24");
   trace_rec_3();
   work_use_ct[67]++;

   strcpy(a_string, "         LARL  R7,C370ZERO");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #25");
   trace_rec_3();
   work_use_ct[32]++;

   strcpy(a_string, "         ZAP   0(6,R8),0(6,R7)");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #26");
   trace_rec_3();






   strcpy(a_string, "         XR    R15,R15");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #XXXXX");
   trace_rec_3();

   strcpy(a_string, "         L     R14,SVSUB_2");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #XXX");
   trace_rec_3();

   strcpy(a_string, "         BR    14");
   src_line();
   strcpy(trace_1, "c2z_eoj c2_math_rdp #XXX");
   trace_rec_3();





   convert = 1;
   return;
}

