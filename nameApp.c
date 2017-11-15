// template demonstration application for camera badge
// new apps need to be added to list in applist.h

#include "cambadge.h"
#include "globals.h"

// states used by this application

#define s_start 0
#define s_run 1
#define s_freeze 2
#define s_alt_2 3
#define s_alt_3 4

int counter;
char* nameApp(unsigned int action)
{
  static unsigned int state,colour;
  unsigned int x,y,i;
  
  switch(action) {
     case act_name : return("Name App");
     case act_help : return("Just click it, damnit.");  
     case act_init :
         // add any code here that needs to run once at powerup - e.g. hardware detection/initialisation      
            return(0);   
     
     case act_powerdown :
          // add any code here that needs to run before powerdown
         return(0);
         
     case act_start :  
         // called once when app is selected from menu
         counter = 0;
         state=s_start;
         colour=1;
         return(0);         
    } //switch
 
 if (action!=act_poll) return(0);
 
  // do anything that needs to be faster than tick here.
  
 if(!tick) return(0);
  
 switch(state) {
     case s_start :
       printf(cls top butcol "Shit" bot "Dance");
       state=s_run;
       
  
     case s_run :         
       //
      
       //x=accx/300+64;
       //y=accy/300+64;
       //plotblock(x+10,y,4,4,primarycol[colour]);
       //printf();
       //printf( bot butcol "COUNTING");
       //printf(tabx0 taby12 whi "Tick %5d, %5d",counter,counter / 5);
       //if(butpress & but2)loadbmp("name24.bmp", 2);
       //else if(butpress & but3)loadbmp("name24_2.bmp", 2);
       if (counter / 5 <= 10) loadbmp("name24.bmp", 2);
       else if(counter / 5 > 20) counter = 0;
       else loadbmp("name24_2.bmp", 2);
       counter++;
       if(butpress & but2) state=s_alt_2;
       if(butpress & but3) state=s_alt_3;
       //dispimage(0, 0, 128, 128, img_mono, imgbuf);
       break;
 
     case s_alt_2 : 
         loadbmp("name24.bmp", 2);
         if(butpress) state=s_run;
       break;
    case s_alt_3 : 
         loadbmp("name24_2.bmp", 2);
         if(butpress) state=s_run;
       break;
 
 } // switch state
 
 if(butpress & but1) state=s_start;  // clear screen & restart
 if(butpress & but2) if(++colour==8) colour=1;
 
 if(butpress & powerbut) return(""); // exit with nonzero value to indicate we want to quit

 return(0);
 
}
 
 
