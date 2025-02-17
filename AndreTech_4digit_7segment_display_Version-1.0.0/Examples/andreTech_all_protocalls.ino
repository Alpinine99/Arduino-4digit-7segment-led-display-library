//declaration of the library
#include <AndreTech_display.h>
//pin connection declaration
//  Segdisp  *object*(d1,d2,d3,d4, A, B, C, D, E, F, G, DP);
    Segdisp myDisplay( 9, 6, 5, 3, 2,11,10, 8, 7, 4, 13,12);

void setup(){
//setup the pins
  myDisplay.DISPL_Pinsetup();
//set the time for switching characters
  myDisplay.DISPL_DisplayTime(9);
//Set initial value for a count down
  myDisplay.DISPL_InitLZ(5555);

}
void loop(){
////call onto the display
//  myDisplay.DISPL_Enable();
////display multiple characters of choice
//  myDisplay.DISPL_MultiChar(26,"Please inPut your data    ");
////set a chaser to your left direction
//  myDisplay.DISPL_Chaser("left","LUCy");
////set a chaser to your right direction
//  myDisplay.DISPL_Chaser("right","LUCy");
////reset your conter/timer values back to 0000
//  myDisplay.DISPL_Reset();
////start a count down from what you initialized
//  myDisplay.DISPL_Countdown();
////start a timedown from what you initialized
//  myDisplay.DISPL_Timedown();
////start a countup from 0000
//  myDisplay.DISPL_Countup();
////start a countup from 00.00
//  myDisplay.DISPL_Timeup();
////set dicimal placings
//  myDisplay.DISPL_Dec("off","off","on","off");
////prit a 4 digit number
//  myDisplay.DISPL_PrintDigit(7537);
////print a character
//  myDisplay.DISPL_PrintChar("HELO");

/*special characters "_" for underscore , "*" for degree , " " for space,"-" for minus , "=" for equals  */

  myDisplay.DISPL_DisplayTime(15);
  myDisplay.DISPL_Dec("on","on","on","on");
  myDisplay.DISPL_PrintDigit(8888);
  myDisplay.DISPL_Dec("off","off","off","off");
  myDisplay.DISPL_DisplayTime(7);
  myDisplay.DISPL_MultiChar(34,"logging into the syst_____________");
  myDisplay.DISPL_MultiChar(47,"loading data _-_-_-_-_-_-_-_-_-_-_-_-____");
  myDisplay.DISPL_DisplayTime(4);
  for(int i = 0; i < 6; i++){
  myDisplay.DISPL_Chaser("right","Load");
  }
  myDisplay.DISPL_Dec("on","off","off","on");
  myDisplay.DISPL_DisplayTime(4);
  for(int i = 0; i < 3; i++){
  myDisplay.DISPL_Chaser("left","****");
  myDisplay.DISPL_Chaser("right","oooo");
  }
  myDisplay.DISPL_DisplayTime(6);
  myDisplay.DISPL_MultiChar(20,"o*o*o*o*o*o*o*o*o*o*");
  delay(700);
  myDisplay.DISPL_DisplayTime(10);
  myDisplay.DISPL_Dec("off","off","off","on");
  myDisplay.DISPL_MultiChar(48,"loaded all data sho in 5_____4____3___2__1_0    ");
  myDisplay.DISPL_MultiChar(25,"andre is just so cool    ");
  delay(500);
  myDisplay.DISPL_MultiChar(41,"agree stranger or just a guy I Forgot    ");
  delay(1500);
  myDisplay.DISPL_MultiChar(39,"bye guy I Forgot or rather stranger____");
  myDisplay.DISPL_MultiChar(32,"logging out-_-_-_-_-_-_-_-_-_-_");
  myDisplay.DISPL_MultiChar(38,"lets start once again in 5 seconds   ");
  myDisplay.DISPL_DisplayTime(3);
  for(int i = 0; i < 10; i++){
  myDisplay.DISPL_Chaser("right","OUt_");
  }
  myDisplay.DISPL_DisplayTime(10);
  myDisplay.DISPL_Chaser("left","OUt_");
  myDisplay.DISPL_DisplayTime(18);
  myDisplay.DISPL_PrintChar("OUt_");
  delay(5000);
}
