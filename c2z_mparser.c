*  38  int rdp_start()
C37F2    DS    0H                            /*  rdp_start */           0000194
*  39  {
*  40  int value;
         LARL  R9,C37F34                     /*  value */               0000195
         LARL  R8,C370ZERO                                              0000196
         ZAP   0(6,R9),0(6,R8)                                          0000197
*  42  value = Expression();
         LARL  R15,C37F4                     /*  Expression */          0000198
         BAKR  0,R15                                                    0000199
         LARL  R9,C37F34                     /*  value */               0000200
         LARL  R8,C37F37                     /*  Value */               0000201
         ZAP   0(6,R9),0(6,R8)                                          0000202
*  44  return value;
         PR                                  /*  sub rtn  */            0000203
*  45  }
         PR                                                             0000204
