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


char* serialApp(unsigned int action)
{
  static unsigned int state,colour;
  unsigned int x,y,i;
  
  switch(action) {
     case act_name : return("SERIAL APP");
     case act_help : return("Beware of trolls ...");  
     case act_init :
         // add any code here that needs to run once at powerup - e.g. hardware detection/initialisation      
            return(0);   
     
     case act_powerdown :
          // add any code here that needs to run before powerdown
         return(0);
         
     case act_start :  
         // called once when app is selected from menu
         //counter = 0;
         state=s_start;
         colour=1;
         return(0);         
    } //switch
 
 if (action!=act_poll) return(0);
 
  // do anything that needs to be faster than tick here.
  
 if(!tick) return(0);
  
 switch(state) {
     case s_start :
       
       state=s_run;
       printf(cls tabx2 taby3 "supercon.ngrok.io");
       
       //int j;
       //for (j=0;j<sizeof(currentText);j++) currentText[j] = 0;
  
     case s_run :               
         
         
         
         
         if (polluart()) {
            //printf(cls);
            //unsigned char sentiment[12];
            
             
            if(currentText[0] == '$') {
                //printf(tabx0 taby12);
                
                //int j;
                //for(j=1;currentText[j] != '$';j++) sentiment[j-1] = currentText[j];
                //sentiment[j++] = 0;
                
                if(currentText[1] == 'p' && currentText[2] == 'o') {
                    //printf(cls);
                    plotblock(0,120,128,8,c_grn);
                }
                if(currentText[1] == 'n' && currentText[2] == 'e' && currentText[3] == 'g') {
                    //printf(cls);
                    plotblock(0,50,128,78,c_red);
                    printf(bgred tabx0 taby12 "    * * TROLL! * *    ");
                    printf(whi);
                }
                if(currentText[1] == 'n' && currentText[2] == 'e' && currentText[3] == 'u') {
                    //printf(cls);
                    plotblock(0,120,128,8,c_whi);
                }
                //printf(tabx0 taby12);
                //printf(sentiment);
                //printf(currentText);
                

            } else {
                printf(cls);
                printf(tabx0 taby0 whi);
                printf(currentText);
            }
         }
         //printf(cls);

         //printf(tabx0 taby12 whi "Tick: %5d", counter);
         //counter++;
         if(butpress & but1) state=s_start;
//       if (counter / 5 <= 10) loadbmp("name24.bmp", 2);
//       else if(counter / 5 > 20) counter = 0;
//       else loadbmp("name24_2.bmp", 2);
//       counter++;
//       if(butpress & but2) state=s_alt_2;
//       if(butpress & but3) state=s_alt_3;
//       //dispimage(0, 0, 128, 128, img_mono, imgbuf);
       break;
 
 } // switch state
 
 //if(butpress & but1) state=s_start;  // clear screen & restart
 //if(butpress & but2) if(++colour==8) colour=1;
 
 if(butpress & powerbut) return(""); // exit with nonzero value to indicate we want to quit

 return(0);
 
}
 
 
