#include <AndreTech_display.h>
//pin connection declaration
//  Segdisp  *object*(d1,d2,d3,d4, A, B, C, D, E, F, G, DP);
    Segdisp myDisplay( 9, 6, 5, 3, 2,11,10, 8, 7, 4,13, 12);

void setup(){
  myDisplay.DISPL_Pinsetup();
  myDisplay.DISPL_DisplayTime(6);
  myDisplay.DISPL_InitLZ(5555);

}
void loop(){
//        myDisplay.DISPL_Enable();
//        myDisplay.DISPL_MultiChar(45,"Please inPut your data and dont be a Fool    ");
//        myDisplay.DISPL_Chaser("left","LUCy");
//        myDisplay.DISPL_Chaser("right","LUCy");
//        myDisplay.DISPL_Reset();
//        myDisplay.DISPL_Countdown();
//        myDisplay.DISPL_Timedown();
//        myDisplay.DISPL_Countup();
//        myDisplay.DISPL_Timeup();
//        myDisplay.DISPL_Dec("off","off","on","off");
//        myDisplay.DISPL_PrintDigit(7537);
//        myDisplay.DISPL_PrintChar("HELO");



        myDisplay.DISPL_MultiChar(26,"Please inPut your data    ");




}
