
#ifndef AndreTech_display_h
#define AndreTech_display_h
#include "Arduino.h"



class Segdisp   {
  
   private:
   
// Define the segment pins
   int A;  int B;  int C;  int D;  int E;  int F;  int G;  int DP;
   int DISPL_segmentPins[8];
   
// Define the digit select pins
   int DIG_I;  int DIG_II;  int DIG_III;  int DIG_IV;
   int DISPL_digitPins[4];
   
   byte ptn;
   
   String DISPL_Char[4];
   String DISPL_Decimal[4];
   
   int dTime;
   int Val[4];

   String e; String f; String g;  String h;
   
//Countdown and Timedown variables
   int d_1; int D_1;
   int d_2; int D_2;
   int d_3; int D_3;   
   int d_4; int D_4;
   
//Countup and Timeup variables
   int D__1;  int D__2;
   int D__3;  int D__4=-1;
     
     public:

Segdisp(int Dig1_PIN,int Dig2_PIN,int Dig3_PIN,int Dig4_PIN,int SegA_PIN,int SegB_PIN,
      int SegC_PIN,int SegD_PIN,int SegE_PIN,int SegF_PIN,int SegG_PIN,int DecP_PIN);
          
void DISPL_Pinsetup();
void DISPL_CharDraw(String Char);
void DISPL_Dec(String d_one,String d_two,String d_three,String d_four);
void Set(String CharB ,String dec);
void DISPL_DisplayTime(int Time);
void DISPL_Enable();
void CharPrint(String one,String two,String three,String four);
void DISPL_PrintChar(char msg[]);
void DISPL_Chaser(String Direction,char chase[]);
void DISPL_MultiChar(int Charsize,char charT[]);
void DISPL_PrintDigit(int number);
void DISPL_Countup();
void DISPL_Timeup();
void DISPL_InitLZ(int initialize);
void DISPL_Countdown();
void DISPL_Timedown();
void DISPL_Reset();





};


#endif
