 
void c2_rdp_main() 
{

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #1");
  trace_rec_3();

  strcpy(a_string, "RDP_MAIN  DS     0H");
  strcpy(wk_remark, " ");
  strcat(wk_remark, " RDP_MAIN");
  strcat(wk_remark, " */ ");
  write_remark();
  strcpy(trace_1, "c2z_eoj RDPARSER #2");
  trace_rec_3();

  strcpy(a_string, "          LARL   R1,SV_RDP");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #3");
  trace_rec_3();

  strcpy(a_string, "          ST     R14,0(,R1)");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #4");
  trace_rec_3();

  strcpy(a_string, "          LARL   R8,MLF001");
  strcpy(wk_remark, " ");
  strcat(wk_remark, " value");
  strcat(wk_remark, " */ ");
  write_remark();
  strcpy(trace_1, "c2z_eoj RDPARSER #5");
  trace_rec_3();

  strcpy(a_string, "          LARL   R7,C370ZERO");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #6");
  trace_rec_3();
  work_use_ct[32]++;

  strcpy(a_string, "          ZAP    0(6,R8),0(6,R7)");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #7");
  trace_rec_3();

  strcpy(a_string, "          BRAS   R14,RDP_EXP");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #8");
  trace_rec_3();
 
  strcpy(a_string, "          LRL    R14,SV_RDP");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();

  strcpy(a_string, "          BR     R14");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #1");
  trace_rec_3();

  strcpy(a_string, "RDP_EXP   DS     0H");
  strcpy(wk_remark, " ");
  strcat(wk_remark, " EXPRESSION");
  strcat(wk_remark, " */ ");
  write_remark();
  strcpy(trace_1, "c2z_eoj RDPARSER #2");
  trace_rec_3();

  strcpy(a_string, "          LARL   R1,SV_EXP");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #3");
  trace_rec_3();

  strcpy(a_string, "          ST     R14,0(,R1)");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #3");
  trace_rec_3();

  strcpy(a_string, "          LARL   R8,MLF002");
  strcpy(wk_remark, " ");
  strcat(wk_remark, " ch");
  strcat(wk_remark, " */ ");
  write_remark();
  strcpy(trace_1, "c2z_eoj RDPARSER #5");
  trace_rec_3();

  strcpy(a_string, "          MVI    0(R8),C' '");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #6");
  trace_rec_3();
  work_use_ct[32]++;

  strcpy(a_string, "          MVC    1(L'MLF002-1,R8),9(R8)");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #7");
  trace_rec_3();



/*
              int pi;
           LARL  R8,C37F43                
           LARL  R7,C370ZERO              
           ZAP   0(6,R8),0(6,R7)                                         
*/

  strcpy(a_string, "          LRL    R14,SV_EXP");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();

  strcpy(a_string, "          BR     R14");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #1");
  trace_rec_3();

  strcpy(a_string, "RDP_TERM  DS     0H");
  strcpy(wk_remark, " ");
  strcat(wk_remark, " TERM");
  strcat(wk_remark, " */ ");
  write_remark();
  strcpy(trace_1, "c2z_eoj RDPARSER #2");
  trace_rec_3();

  strcpy(a_string, "          LARL   R1,SV_TRM");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #3");
  trace_rec_3();

  strcpy(a_string, "          ST     R14,0(,R1)");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #3");
  trace_rec_3();

  strcpy(a_string, "          LRL    R14,SV_TRM");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();

  strcpy(a_string, "          BR     R14");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();

  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #1");
  trace_rec_3();

  strcpy(a_string, "RDP_FACT  DS     0H");
  strcpy(wk_remark, " ");
  strcat(wk_remark, " FACTOR");
  strcat(wk_remark, " */ ");
  write_remark();
  strcpy(trace_1, "c2z_eoj RDPARSER #2");
  trace_rec_3();

  strcpy(a_string, "          LARL   R1,SV_FACT");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #3");
  trace_rec_3();

  strcpy(a_string, "          ST     R14,0(,R1)");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #3");
  trace_rec_3();

  strcpy(a_string, "          LRL    R14,SV_FACT");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();

  strcpy(a_string, "          BR     R14");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();


  strcpy(a_string, "*");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #1");
  trace_rec_3();

  strcpy(a_string, "RDP_MAT  DS     0H");
  strcpy(wk_remark, " ");
  strcat(wk_remark, " MATCH");
  strcat(wk_remark, " */ ");
  write_remark();
  strcpy(trace_1, "c2z_eoj RDPARSER #2");
  trace_rec_3();

  strcpy(a_string, "          LARL   R1,SV_MAT");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #3");
  trace_rec_3();

  strcpy(a_string, "          ST     R14,0(,R1)");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #3");
  trace_rec_3();

  strcpy(a_string, "          LRL    R14,SV_MAT");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();

  strcpy(a_string, "          BR     R14");
  src_line();
  strcpy(trace_1, "c2z_eoj RDPARSER #XXX");
  trace_rec_3();




}
