3  60     c2z_strcpy c2_str_1 START                                     strcpy(array1[ii], "98765");
3  60     c2z_strcpy c2_str_1 #900                 LARL  R9,C370NWK1                                              0000419
3  60     c2z_strcpy c2_str_1 #901                 LARL  R8,C370ZERO                                              0000420
3  60     c2z_strcpy c2_str_1 #902                 ZAP   0(6,R9),0(6,R8)                                          0000421
3  60     c2z_strcpy c2_str_1 #903                 LARL  R6,A374T                 /* Ln#- 60 array1 */            0000422
3  60     c2z_strcpy c2_str_1 #904        L60A     DS    0H                                                       0000423
3  60     c2z_strcpy c2_str_1 #905                 LARL  R9,C370NWK1                                              0000424
3  60     c2z_strcpy c2_str_1 #906                 LARL  R8,C37F23                /* Ln#- 60 ii */                0000425
3  60     c2z_strcpy c2_str_1 #907                 CP    0(6,R9),0(6,R8)                                          0000426
3  60     c2z_strcpy c2_str_1 #908                 JLE   L60B                                                     0000427
3  60     c2z_strcpy c2_str_1 #909                 LARL  R9,C370NWK1                                              0000428
3  60     c2z_strcpy c2_str_1 #910                 LARL  R8,C370ONE                                               0000429
3  60     c2z_strcpy c2_str_1 #911                 AP    0(6,R9),0(6,R8)                                          0000430
3  60     c2z_strcpy c2_str_1 #912                 LAEY  R6,A374L(R0,R6)          /* Ln#- 60 A374L */             0000431
3  60     c2z_strcpy c2_str_1 #913                 JLU   L60A                                                     0000432
3  60     c2z_strcpy c2_str_1 #914        L60B     DS    0H                                                       0000433
3  60     c2z_strcpy c2_str_1 #914a                XC    0(32,R6),0(R6)                                           0000434
3  60     c2z_strcpy c2_str_1 #915                 LARL  R9,C37F40                                                0000435
3  60     c2z_strcpy c2_str_1 #916                 MVC   0(5,R6),0(R9)                                            0000436
3  60     c2z_strcpy c2_str_1 #916a                LARL  R8,C370EOF                                               0000437
3  60     c2z_strcpy c2_str_1 #916b                MVC   5(1,R6),0(R8)                                            0000438


z_print c2_printf_string                                    printf("array1 = %s\n",array1[ii];
3  61     c2z_print c2_printf_str #1               LARL  R9,C370WTOB                                              0000439
3  61     c2z_print c2_printf_str #2               LARL  R8,L57                                                   0000440
3  61     c2z_print c2_printf_str #3               MVC   0(9,R9),0(R8)                                            0000441
3  61     c2z_print c2_printf_str #4               LHI   R10,9                                                    0000442
3  61     c2z_print c2_printf_str[] #7             LARL  R6,A374T                                                 0000443
3  61     c2z_print c2_printf_str[] #8             LARL  R9,C370NWK1                                              0000444
3  61     c2z_print c2_printf_str[] #9             LARL  R8,C370ZERO                                              0000445
3  61     c2z_print c2_printf_str[] #10            ZAP   0(6,R9),0(6,R8)                                          0000446
3  61     c2z_print c2_printf_str[] #11   PR61A    DS    0H                                                       0000448
3  61     c2z_print c2_printf_str[] #18            LARL  R9,C37F23                /* Ln#- 61 ii */                0000449
3  61     c2z_print c2_printf_str[] #19            LARL  R8,C370NWK1                                              0000450
3  61     c2z_print c2_printf_str[] #20            CP    0(6,R9),0(6,R8)                                          0000451
3  61     c2z_print c2_printf_str[] #21            JLE   PR61E                                                    0000452
3  61     c2z_print c2_printf_str[] #22            LARL  R9,C370NWK1                                              0000454
3  61     c2z_print c2_printf_str[] #23            LARL  R8,C370ONE                                               0000455
3  61     c2z_print c2_printf_str[] #24            AP    0(6,R9),0(6,R8)                                          0000456
3  61     c2z_print c2_printf_str[] #25            LAEY  R6,A374L(R0,R6)                                          0000457
3  61     c2z_print c2_printf_str[] #26            JLU   PR61A                                                    0000458
3  61     c2z_print c2_printf_str[] #27   PR61E    DS    0H                                                       0000459
3  61     c2z_print c2_printf_str[] #28            LARL  R9,C370WTOB                                              0000460
3  61     c2z_print c2_printf_str[] #29            MVC   9(32,R9),0(R6)                                           0000461
3  61     c2z_print c2_printf_str[] #30            AHI   R10,32                                                   0000462
3  61     c2z_print c2_printf_str[] #32            LARL  R11,C370WTOB                                             0000463
3  61     c2z_print c2_printf_str[] #33            TPUTL (R11),(R10),R,ASIS                                       0000464
3  61     c2z_printf c2_printf_str[] #34           XC    0(78,R11),0(R11)                                         0000465














