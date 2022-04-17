 
#include "c2z_time.h"

#define PORT            7070
#define SRV_LISTEN_ADDR "0.0.0.0"
#define MAXMSG          4095
#define CHAT_PWD        "teccha"


    int x1, x2, x3;
    int j, I, K, user_ct;
    int msg_ct = 0;
    int sock;
    int u_ct = 0;
    int hdr_len;
    int sendCon;
    int nbytes;
    int size;
    int hhelp;
    int hmsg;
    int hlist;
    int hpvt;
    int hlogoff;
    int hwho;
    int hstat;
    int hshutdn;
    int filedes;
    int new;

   char hdr_msg[80];
   char prt_msg[50];
   char buffer[MAXMSG];
   char wk_buf[80];
   char output[4095];
   char dtime[8];
   char start_tm[8];
   char wk_name[9];
   char *p1;
   char *p2;
   char *p3;
   char *p4;
   char *p5;
   char *p6;
   char *p7;
/* fd_set active_fd_set, read_fd_set; */

struct users 
{
  int u_sock;
 char u_name[9];
};
struct users *w_users;


int TextRelay();
int closesocket(int);


int main (void)
{
  int i;
  struct sockaddr_in name;
  size_t size;

  time_t sytime = time(NULL);
  char * stime_str = ctime(&sytime);
  stime_str[strlen(stime_str)-1] = '\0';
  strncpy(start_tm, stime_str+11, 8);

  /* Create the socket. */
  sock = socket (AF_INET, SOCK_STREAM, 0);
  if (sock < 0)
  {
      printf("\nsocket error\n");
      return -1;
  }

  /* Give the socket a name. */
  name.sin_family = AF_INET;
  name.sin_port = htons (PORT);
  name.sin_addr.s_addr = inet_addr(SRV_LISTEN_ADDR);
  if (bind (sock, (struct sockaddr *) &name, sizeof (name)) < 0)
  {
      printf("\nbind error\n");
      return -1;
  }

  if (listen (sock, 1) < 0)
  {
      printf("\nlisten error\n");
      return -1;
  }

  /* Initialize the set of active sockets. */
  FD_ZERO (&active_fd_set);
  FD_SET (sock, &active_fd_set);

  while (1)
  {
    /* Block until input arrives on one or more active sockets. */
    read_fd_set = active_fd_set;
    if (select (FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0)
    {
      printf("\nselect error\n");
      return -1;
    }

    /* Service all the sockets with input pending. */
    for (i = 0; i < FD_SETSIZE; ++i)
      
      if (FD_ISSET (i, &read_fd_set))
      {
        if (i == sock)
        {
        /* Connection request on original socket. */
     
          size = sizeof (name);
          new = accept (sock, (struct sockaddr *) &name, &size);
          if (new < 0)
          {
            printf("\naccept error\n");
            return -1;
          }
          /*  printf ("Server: New connection from\n"); */

          strcpy(hdr_msg, "CMSCHAT Login (*xxxxxxxx): ");
          hdr_len = strlen(hdr_msg);
          sendCon = send(new, hdr_msg, hdr_len, 0);
           
	   FD_SET (new, &active_fd_set); 
        }
        else
        {
          /* Data arriving on an already-connected socket. */
          if (read_from_client (i) < 0)		
          {
          /* Disconnect remote user.... */

  	     closesocket(i);		/* i connects the local socket # */
     	     FD_CLR (i, &active_fd_set); 
            strcpy(buffer, "Has Disconnected from CMSCHAT\r\n");
            nbytes = strlen(buffer);
            
            TextRelay();
      	   }
          else
          {
            if(hmsg == 1)
            {
              TextRelay();
            }
          }
        }
     }
  }
}





int TextRelay()
{
  time_t mytime = time(NULL);
  char * time_str = ctime(&mytime);
  time_str[strlen(time_str)-1] = '\0';
  strncpy(dtime, time_str+11, 8);

  strcpy(output, " [ ");
  strncat(output, dtime, 8);
  strcat(output, " ] [ ");
  strncat(output, wk_name,9);
  x3 = strlen(wk_name);
 
  if(x3 == 9)
  {
    strcat(output, " ] ");
  }
  if(x3 == 8)
  {
    strcat(output, "  ] ");
  }
  if(x3 == 7)
  {
    strcat(output, "   ] ");
  }

  if(x3 == 6)
  {
    strcat(output, "    ] ");
  }
  
  if(x3 == 5)
  {
    strcat(output, "     ] ");
  }

  if(x3 == 4)
  {
    strcat(output, "      ] ");
  }

  if(x3 == 3)
  {
    strcat(output, "       ] ");
  }

  if(x3 == 2)
  {
    strcat(output, "        ] ");
  }

  if(x3 == 1)
  {
    strcat(output, "         ] ");
  }

  if(x3 == 0)
  {
    strcat(output, "          ] ");
  }

  strcat(output, buffer);
  x2 = strlen(output);
                    
  for (j = 0; j < FD_SETSIZE; j++)
  {
    FD_ISSET(j, &active_fd_set);
    sendCon = send(j, output, x2+2, 0);
  }
  wk_name[0] = '\0';
}

int read_from_client (int filedes)
{
  fd_set activeSet;

  hhelp = 0;
  hlist = 0;
  hpvt = 0;
  hlogoff = 0;
  hwho = 0;
  hstat = 0;
  hmsg = 1;
  hshutdn = 0;


/*  bool done = waitForSocket(&activeSet); */

  msg_ct++;
  nbytes = recv(filedes, buffer, MAXMSG, 0);
printf("recv buffer = %s\n",buffer);
  x1 = strlen(buffer);
  nbytes = nbytes - 2;
  buffer[nbytes] = '\0';

  p1 = strstr(buffer, "/help");
  if(p1)
  {
    hhelp = 1;
    hmsg = 0;
    hlist = 0;
    hpvt = 0;
    hlogoff = 0;
    hwho = 0;
    hstat = 0;
    hshutdn = 0;
  }

  p2 = strstr(buffer, "/list");
  if(p2)
  {
    hlist = 1;
    hmsg = 0;
    hhelp = 0;
    hpvt = 0;
    hlogoff = 0;
    hwho = 0;
    hstat = 0;
    hshutdn = 0;
  }

  p3 = strstr(buffer, "/pvt");
  if(p3)
  {
    hpvt = 1;
    hmsg = 0;
    hlist = 0;
    hhelp = 0;
    hlogoff = 0;
    hwho = 0;
    hstat = 0;
    hshutdn = 0;
  }
  
  p4 = strstr(buffer, "/logoff");
  if(p4)
  {
    hlogoff = 1;
    hpvt = 0;
    hmsg = 0;
    hlist = 0;
    hhelp = 0;
    hwho = 0;
    hstat = 0;
    hshutdn = 0;
  }

  p5 = strstr(buffer, "/whoami");
  if(p5)
  {
    hwho = 1;
    hlogoff = 0;
    hpvt = 0;
    hmsg = 0;
    hlist = 0;
    hhelp = 0;
    hstat = 0;
    hshutdn = 0;
  }

  p6 = strstr(buffer, "/stat");
  if(p6)
  {
    hstat = 1;
    hwho = 0;
    hlogoff = 0;
    hpvt = 0;
    hmsg = 0;
    hlist = 0;
    hhelp = 0;
    hshutdn = 0;
  }

  p7 = strstr(buffer, "/shutdown");
  if(p7)
  {
    hshutdn = 1;
    hstat = 0;
    hwho = 0;
    hlogoff = 0;
    hpvt = 0;
    hmsg = 0;
    hlist = 0;
    hhelp = 0;
  }

/* Read error. DISCONNECT */
  if (nbytes < 0)			
  { 
    for(I = 0; I < u_ct; I++)
    {
      if(filedes == w_users[I].u_sock)
      {
        strcpy(wk_name, w_users[I].u_name);
      }
    }
    return -1;
  }
  else if (nbytes == 0)		
             return -1;
  else					
  {
    /* HELP Message   */
    if(hhelp == 1)			
    {
      buffer[0] = '\0';
      strcpy(buffer, "HELP Instructions for CMSCHAT");
      x2 = strlen(buffer);
  
      strcpy(output, buffer);
      x2 = strlen(output);
  

      buffer[0] = '\0';
      strcpy(buffer, "LIST");
      x2 = strlen(buffer);
      strcat(output, buffer);
      x2 = strlen(output);
 

      buffer[0] = '\0';
      strcpy(buffer, "To list all signed on Users, enter");
      x2 = strlen(buffer);
      strcat(output, buffer);
     

      buffer[0] = '\0';
      strcpy(buffer, "the command /list.  This will display a");
      x2 = strlen(buffer);
      strcat(output, buffer);
    
      buffer[0] = '\0';
      strcpy(buffer, "list of all the Users Login I.D.");
      x2 = strlen(buffer);
      strcat(output, buffer);
  

      buffer[0] = '\0';
      strcpy(buffer,  "LOGOFF");
      x2 = strlen(buffer);
      strcat(output, buffer);
   
      buffer[0] = '\0';
      strcpy(buffer,  "To LOGOFF CMSCHAT enter the message");
      x2 = strlen(buffer);
      strcat(output, buffer);
   
      buffer[0] = '\0';
      strcpy(buffer,  "/logoff");
      x2 = strlen(buffer);
      strcat(output, buffer);
  
      buffer[0] = '\0';
      strcpy(buffer,  "HELP");
      x2 = strlen(buffer);
      strcat(output, buffer);
  
      buffer[0] = '\0';
      strcpy(buffer,  "This HELP message can be obtained");
      x2 = strlen(buffer);
  
      strcat(output, buffer);
    
      buffer[0] = '\0';
      strcpy(buffer,  "by entering the command /help");
      x2 = strlen(buffer);
      strcat(output, buffer);
 

      buffer[0] = '\0';
      strcpy(buffer,  "PVT message");
      x2 = strlen(buffer);
      strcat(output, buffer);
 

      buffer[0] = '\0';
      strcpy(buffer,  "This command allow the sending user to");
      x2 = strlen(buffer);
      strcat(output, buffer);
  

      buffer[0] = '\0';
      strcpy(buffer,  "send a PRIVATE message to another online");
      x2 = strlen(buffer);
    
      strcat(output, buffer);
  

      buffer[0] = '\0';
      strcpy(buffer,  "user in the following message");
      x2 = strlen(buffer);
      strcat(output, buffer);
 
      buffer[0] = '\0';
      strcpy(buffer,  "/pvt *tec this is a private message");
      x2 = strlen(buffer);
      strcat(output, buffer);
  

      buffer[0] = '\0';
      strcpy(buffer,  "WHOAMI");
      x2 = strlen(buffer);
    
      strcat(output, buffer);
 
      buffer[0] = '\0';
      strcpy(buffer,  "To retrive your on-line ID type the command");
      x2 = strlen(buffer);
 
      strcat(output, buffer);
 

      buffer[0] = '\0';
      strcpy(buffer,  "/whoami");
      x2 = strlen(buffer);
       strcat(output, buffer);

      x2 = strlen(output);
      sendCon = send(filedes, output, x2, 0);
    }

    if(hlist == 1)			/* LIST Message   */
    {
      output[0] = '\0';
      strcpy(wk_buf, "On_line Users ID's");
      x2 = strlen(wk_buf);
      strcpy(output, wk_buf);
       
      for(I = 0; I < u_ct; I++)
      {
        wk_buf[0] = '\0';
        x2 = strlen(w_users[I].u_name);
        if(x2 != 0)
        {
          strcpy(wk_buf, w_users[I].u_name);
          x2 = strlen(wk_buf);
          strcat(output, wk_buf);
        }
      }

      x2 = strlen(output);
      sendCon = send(filedes, output, x2, 0);
    }

    /* Private Message   */
    if(hpvt == 1)			
    {

    }

    /* CMSCHAT stats     */
    if(hstat == 1)			
    {
      user_ct = 0;
      for(I = 0; I < u_ct; I++)
      {
        x2 = strlen(w_users[I].u_name);
        if(x2 != 0)
        {
          user_ct++;
        }
      }
     
      output[0] = '\0';
      sprintf(wk_buf, "Active Users = %d", user_ct);
      x2 = strlen(wk_buf);
      strcpy(output, wk_buf);
 
      x2 = strlen(output);
      sendCon = send(filedes, output, x2, 0);

    }

/* Logoff   */
    if(hlogoff == 1)			
    {
      for(I = 0; I < u_ct; I++)
      {
         if(filedes == w_users[I].u_sock)
         {
            strcpy(wk_name, w_users[I].u_name);
            w_users[I].u_name[0] = '\0';
         }
      }

      closesocket(filedes);		/* connects the local socket # */
      FD_CLR (filedes, &active_fd_set); 
      strcpy(buffer, "Has Disconnected from CMSCHAT\r\n");
      nbytes = strlen(buffer);
            
      TextRelay();
    }

/* whoami         */
    if(hwho == 1)			
    {
      for(I = 0; I < u_ct; I++)
      {
         if(filedes == w_users[I].u_sock)
         {
            strcpy(wk_name, w_users[I].u_name);
         }
      }

      output[0] = '\0';
      strcpy(wk_buf, "Your On_line ID is - ");
      strcat(wk_buf, wk_name);
      x2 = strlen(wk_buf);
  
      strcpy(output, wk_buf);
      x2 = strlen(output);
      sendCon = send(filedes, output, x2, 0);
    }

/* /shutdown      */
    if(hshutdn == 1)			
    {
      for(I = 0; I < u_ct; I++)
      {
        x2 = strlen(w_users[I].u_name);
        if(x2 != 0)
        { 
          output[0] = '\0';
          strcpy(wk_buf, "CMSCHAT Server Terminating...");
          x2 = strlen(wk_buf);
 
          strcpy(output, wk_buf);
     
          x2 = strlen(output);
          sendCon = send(I, output, x2, 0);
          for(K = 0; K < 101; K++)
          {
          }

          closesocket(I);
        }
      }
      closesocket(7070);
 
      exit(0);
    }

/* test for login */
    if(buffer[0] == '*')		
    {
      hmsg = 1;

      if (u_ct == 0) 
      {
        size = 1;
        w_users = malloc(size * sizeof(struct users));
      } 
      else 
      {
        size = u_ct + 1;
        w_users = realloc(w_users, size * sizeof(struct users));
      }

      strncpy(wk_name, buffer, 9);
      w_users[u_ct].u_sock = filedes;
      strcpy(w_users[u_ct].u_name, wk_name);        
      u_ct++;

      strcpy(buffer, "User Has Joined CMSCHAT\n");
      strcat(buffer, "/help for instructions\n");
    } 	
/* end of logon */			

    for(I = 0; I < u_ct; I++)
    {
      if(filedes == w_users[I].u_sock)
      {
        strcpy(wk_name, w_users[I].u_name);
      }
    }

    return 0;
  }
}



static void sock_shutdown(int rc) 
{
   for(I = 0; I < u_ct; I++)
   {
     x2 = strlen(w_users[I].u_name);
     if(x2 != 0)
     {
       closesocket(I);		
     }
   }
     
   rc = 0;
   __exit(rc);
}


int closesocket(int I)
{

}



