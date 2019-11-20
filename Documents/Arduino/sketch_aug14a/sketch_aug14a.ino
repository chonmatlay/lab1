#include "buttonlab.h"
bool firstButtonRead1=0 ,firstButtonRead2=0, secondButtonRead1=0, secondButtonRead2=0 ;
bool firstButton1s =0 , firstButton3s=0;
bool secondButton1s =0 , secondButton3s=0;
bool firstButtonPress=0 ,secondButtonPress=0;
bool flag1=0, flag2=0;
unsigned int count1=0 , count2=0, count3=0,count4=0 ;
unsigned int count=0;
//enum {
//  STATE1,
//  STATE2,
//  STATE3,
//  STATE4,


//  STATE5,
//  STATE6,
//  STATE7
//} eState;

 
  void ISR() {
      read_button_1();
      read_button_2();
    }

  void setup(){
  Serial.begin(115200);
  init_gpio();
  enable_timer(&ISR);
    }
    void loop(){
      update_state();
      }
