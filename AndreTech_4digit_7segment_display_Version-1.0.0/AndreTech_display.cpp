

#include "Arduino.h"
#include "AndreTech_display.h"

   
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


Segdisp::Segdisp(int Dig1_PIN,int Dig2_PIN,int Dig3_PIN,int Dig4_PIN,int SegA_PIN,int SegB_PIN,
      int SegC_PIN,int SegD_PIN,int SegE_PIN,int SegF_PIN,int SegG_PIN,int DecP_PIN){
                
     DIG_I = Dig1_PIN; DIG_II = Dig2_PIN; DIG_III = Dig3_PIN; DIG_IV = Dig4_PIN; A = SegA_PIN;
     B = SegB_PIN; C = SegC_PIN; D = SegD_PIN; E = SegE_PIN; F = SegF_PIN; G = SegG_PIN;
     DP = DecP_PIN;
      }

void Segdisp::DISPL_Pinsetup(){
  
//default display
   DISPL_Char[0] = "l";
   DISPL_Char[1] = "o";
   DISPL_Char[2] = "a";
   DISPL_Char[3] = "d";
   
//default decimal
   DISPL_Decimal[0]="off";
   DISPL_Decimal[1]="off";
   DISPL_Decimal[2]="off";
   DISPL_Decimal[3]="on";
// settting
   Val[0] = 9;  Val[1] = 9;  Val[2] = 9;  Val[3] = 9;
   
   D_1=Val[0];  D_2=Val[1];
   D_3=Val[2];  D_4=Val[3];
   
      
// SET SEGMENTS PINS
   DISPL_segmentPins[0] = A; DISPL_segmentPins[1] = B; DISPL_segmentPins[2] = C; DISPL_segmentPins[3] = D; 
   DISPL_segmentPins[4] = E; DISPL_segmentPins[5] = F; DISPL_segmentPins[6] = G; DISPL_segmentPins[7] = DP;
   
// SET DIGIT PINS
   DISPL_digitPins[0] = DIG_I; DISPL_digitPins[1] = DIG_II; DISPL_digitPins[2] = DIG_III; DISPL_digitPins[3] = DIG_IV;
   
// Set segment pins as outputs
  for (int i = 0; i < 8; i++) {
    pinMode(DISPL_segmentPins[i], OUTPUT);
  }
  
// Set digit select pins as outputs
  for (int i = 0; i < 4; i++) {
    pinMode(DISPL_digitPins[i], OUTPUT);
  }    
}

void Segdisp::DISPL_CharDraw(String Char){
 // letters
  if(Char=="A"){ptn=B01110111; }   //  case A
  if(Char=="a"){ptn=B01011111; }   //  case a
  if(Char=="b"){ptn=B01111100; }   //  case b
  if(Char=="C"){ptn=B00111001; }   //  case C
  if(Char=="c"){ptn=B01011000; }   //  case c
  if(Char=="D"){ptn=B00111111; }   //  case D
  if(Char=="d"){ptn=B01011110; }   //  case d
  if(Char=="E"){ptn=B01111001; }   //  case E
  if(Char=="e"){ptn=B01111011; }   //  case e
  if(Char=="F"){ptn=B01110001; }   //  case F
  if(Char=="G"){ptn=B00111101; }   //  case G
  if(Char=="g"){ptn=B01101111; }   //  case g
  if(Char=="H"){ptn=B01110110; }   //  case H
  if(Char=="h"){ptn=B01110100; }   //  case h
  if(Char=="I"){ptn=B00000110; }   //  case I
  if(Char=="i"){ptn=B00000100; }   //  case i
  if(Char=="J"){ptn=B00001111; }   //  case J
  if(Char=="j"){ptn=B00001110; }   //  case j
  if(Char=="L"){ptn=B00111000; }   //  case L
  if(Char=="l"){ptn=B00110000; }   //  case l
  if(Char=="n"){ptn=B01010100; }   //  case n
  if(Char=="O"){ptn=B00111111; }   //  case O
  if(Char=="o"){ptn=B01011100; }   //  case o
  if(Char=="P"){ptn=B01110011; }   //  case P
  if(Char=="q"){ptn=B01100111; }   //  case q
  if(Char=="R"){ptn=B01110111; }   //  case R
  if(Char=="r"){ptn=B01110010; }   //  case r
  if(Char=="S"){ptn=B01101101; }   //  case S
  if(Char=="s"){ptn=B01101101; }   //  case s
  if(Char=="T"){ptn=B00000111; }   //  case T
  if(Char=="t"){ptn=B01111000; }   //  case t
  if(Char=="U"){ptn=B00111110; }   //  case U
  if(Char=="u"){ptn=B00011100; }   //  case u
  if(Char=="y"){ptn=B01101110; }   //  case y
  if(Char=="Z"){ptn=B01011011; }   //  case Z
 // Characters
  if(Char=="="){ptn=B01001000; }   //  case '='
  if(Char=="_"){ptn=B00001000; }   //  case '_'
  if(Char==" "){ptn=B00000000; }   //  case ' '
  if(Char=="-"){ptn=B01000000; }   //  case '-'
  if(Char=="*"){ptn=B01100011; }   //  case 'o'
 // string numbers
  if(Char=="0"){ptn=B00111111; }   // 0
  if(Char=="1"){ptn=B00000110; }   // 1
  if(Char=="2"){ptn=B01011011; }   // 2
  if(Char=="3"){ptn=B01001111; }   // 3
  if(Char=="4"){ptn=B01100110; }   // 4
  if(Char=="5"){ptn=B01101101; }   // 5
  if(Char=="6"){ptn=B01111101; }   // 6
  if(Char=="7"){ptn=B00000111; }   // 7
  if(Char=="8"){ptn=B01111111; }   // 8
  if(Char=="9"){ptn=B01101111; }   // 9
}

void Segdisp::DISPL_Dec(String d_one,String d_two,String d_three,String d_four){
  DISPL_Decimal[0] = d_one;  DISPL_Decimal[1] = d_two;
  DISPL_Decimal[2] = d_three;  DISPL_Decimal[3] = d_four;
}

void Segdisp::Set(String CharB ,String dec){
  // Turn off all digits
  for (int i = 0; i < 4; i++) {
    digitalWrite(DISPL_digitPins[i], HIGH);
  }
  DISPL_CharDraw(CharB);
  // Set the segment pins
  byte pattern = ptn;
  for (int i = 0; i < 7; i++) {
    digitalWrite(DISPL_segmentPins[i], bitRead(pattern, i));
  }
  // setting the decimal
  if(dec=="on"){
    digitalWrite(DISPL_segmentPins[7],HIGH);
  }
  else if(dec=="off"){
    digitalWrite(DISPL_segmentPins[7],LOW);
  }
}

void Segdisp::DISPL_DisplayTime(int Time){
  dTime = Time;
  }

void Segdisp::DISPL_Enable(){
  for(int i = 0; i < 4; i++){
  // setup the segments
  Set(DISPL_Char[i],DISPL_Decimal[i]);
  // Turn on the current digit
  digitalWrite(DISPL_digitPins[i], LOW);
  // Small delay for multiplexing
  delay(2);
  }
}

void Segdisp::CharPrint(String one,String two,String three,String four){
  DISPL_Char[0] = one;   DISPL_Char[1] = two;  
  DISPL_Char[2] = three; DISPL_Char[3] = four;
  for(int i = 0; i < pow(dTime,2); i++){
  DISPL_Enable();
  }
  // Turn off all digits
    digitalWrite(DISPL_digitPins[3], HIGH);
}

void Segdisp::DISPL_PrintChar(char msg[]){
  String m = String(msg[0]);  String n = String(msg[1]);
  String o = String(msg[2]);  String p = String(msg[3]);
  CharPrint(m,n,o,p);
}

void Segdisp::DISPL_Chaser(String Direction,char chase[]){
  if(Direction == "right"){
    CharPrint(" "," "," "," ");
    CharPrint(String(chase[0])," "," "," ");
    CharPrint(String(chase[0]),String(chase[1])," "," ");
    CharPrint(String(chase[0]),String(chase[1]),String(chase[2])," ");
    CharPrint(String(chase[0]),String(chase[1]),String(chase[2]),String(chase[3]));
  }
  else if(Direction == "left"){
    CharPrint(" "," "," "," ");
    CharPrint(" "," "," ",String(chase[3]));
    CharPrint(" "," ",String(chase[2]),String(chase[3]));
    CharPrint(" ",String(chase[1]),String(chase[2]),String(chase[3]));
    CharPrint(String(chase[0]),String(chase[1]),String(chase[2]),String(chase[3]));
  }
}

void Segdisp::DISPL_MultiChar(int Charsize,char charT[]){
   for(int i = 0; i < Charsize; i++){
  if(i == 0){
     CharPrint("_","_","_",String(charT[i]));
    }
  if(i == 1){
     CharPrint("_","_",String(charT[i-1]),String(charT[i]));  
  } 
  if(i == 2){
     CharPrint("_",String(charT[i-2]),String(charT[i-1]),String(charT[i]));  
  }  
  if(i > 2){
     CharPrint(String(charT[i-3]),String(charT[i-2]),String(charT[i-1]),String(charT[i]));  
    } 
   }
  }

void Segdisp::DISPL_PrintDigit(int number){
// Break the number into digits
  int digitValues[] = {
    number / 1000 % 10,
    number / 100 % 10,
    number / 10 % 10,
    number % 10
  };
  String w = String(digitValues[0]);
  String x = String(digitValues[1]);
  String y = String(digitValues[2]);
  String z = String(digitValues[3]);
  CharPrint(w,x,y,z);
 }

void Segdisp::DISPL_Countup(){  
  d_4=D__4+1;
   D__4=d_4;
   
   if(D__4==10){
    D__3=d_3+1;
    d_3=D__3;
    D__4=0;
   }
   if(D__3==10){
    D__2=d_2+1;
    d_2=D__2;
    D__3=0;
    d_3=0;
   }
   if(D__2==10){
    D__1=d_1+1;
    d_1=D__1;
    D__2=0;
    d_2=0;
   }
   if(D__1==10){
    d_1=0; D__1=0;
    d_2=0; D__2=0;
    d_3=0; D__3=0;
    d_4=0; D__4=-1;
   }
   e = String(D__1);   f = String(D__2);
   g = String(D__3);   h = String(D__4);
   CharPrint(e,f,g,h);  

}

void Segdisp::DISPL_Timeup(){
 if(D__3>=6){
   D__3=5;  D__4=10;
  }
  else{
   D__3 = D__3;
  }
  d_4=D__4+1;
   D__4=d_4;
   
   if(D__4==10){
    D__3=d_3+1;
    d_3=D__3;
    D__4=0;
   }
   if(D__3==6){
    D__2=d_2+1;
    d_2=D__2;
    D__3=0;
    d_3=0;
   }
   if(D__2==10){
    D__1=d_1+1;
    d_1=D__1;
    D__2=0;
    d_2=0;
   }
   if(D__1==10){
    d_1=0; D__1=0;
    d_2=0; D__2=0;
    d_3=0; D__3=0;
    d_4=0; D__4=-1;
   }
   e = String(D__1);   f = String(D__2);
   g = String(D__3);   h = String(D__4);
   DISPL_Dec("off","on","off","off");
   CharPrint(e,f,g,h);  
       
 }

void Segdisp::DISPL_InitLZ(int initialize){
  // convertion 
    Val[0] = initialize / 1000 % 10;
    Val[1] = initialize / 100 % 10;
    Val[2] = initialize / 10 % 10;
    Val[3] = initialize % 10;
  // getting initialization
     D_1=Val[0];   D_2=Val[1];   
     D_3=Val[2];   D_4=Val[3];  
   
}

void Segdisp::DISPL_Countdown(){
      d_4=D_4-1;
      D_4=d_4;
 if(D_4<0){
      D_4=9;
      d_3=D_3-1; 
      D_3=d_3; 
    }
 if(D_3<0){
      D_3=9;
      d_2=D_2-1; 
      D_2=d_2;
 }
 if(D_2<0){
      D_2=9;
      d_1=D_1-1; 
      D_1=d_1;
 }
 if(D_1<0){
    d_1=0; D_1=0;
    d_2=0; D_2=0;
    d_3=0; D_3=0;
    d_4=0; D_4=0;
       }
   e = String(D_1);   f = String(D_2);
   g = String(D_3);   h = String(D_4);
   CharPrint(e,f,g,h);  
}

void Segdisp::DISPL_Timedown(){
 if(D_3>=6){
   D_3=5;  D_4=10;
  }
  else{
   D_3 = D_3;
  }
  d_4=D_4-1;
  D_4=d_4;
 if(D_4<0){
      D_4=9;
      d_3=D_3-1; 
      D_3=d_3; 
    }
 if(D_3<0){
      D_3=5;
      d_2=D_2-1; 
      D_2=d_2;
 }
 if(D_2<0){
      D_2=9;
      d_1=D_1-1; 
      D_1=d_1;
 }
 if(D_1<0){
    d_1=0; D_1=0;
    d_2=0; D_2=0;
    d_3=0; D_3=0;
    d_4=0; D_4=0;
       }
   e = String(D_1);   f = String(D_2);
   g = String(D_3);   h = String(D_4);
   DISPL_Dec("off","on","off","off");
   CharPrint(e,f,g,h);      
}

void Segdisp::DISPL_Reset(){
  //       time_d time_u
    d_1=0; D_1=0; D__1=0;
    d_2=0; D_2=0; D__2=0;
    d_3=0; D_3=0; D__3=0;
    d_4=0; D_4=0; D__4=0;
   e = String(D_1);   f = String(D_2);
   g = String(D_3);   h = String(D_4);
   CharPrint(e,f,g,h);  
}

