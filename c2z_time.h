/*  c2z_time.h  */

struct tm 
{
/* rct count 				*/
   int tm_rct;
/* seconds,  range 0 to 59          */
   char tm_sec[3];  
/* minutes, range 0 to 59           */       
   char tm_min[3];     
/* hours, range 0 to 23             */    
   char tm_hour[3];  
/* day of the month, range 1 to 31  */      
   char tm_mday[3]; 
/* month, range 0 to 11             */       
   char tm_mon[3];
/* The number of years since 1900   */         
   char tm_year[5]; 
};
