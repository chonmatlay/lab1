0#include "buttonlab.h"
  enum {
  STATE1,
  STATE2,
  STATE3,
  STATE4,
  STATE5,
  STATE6,
  STATE7
} eState;

void read_button_1(){
     firstButtonRead1=firstButtonRead2;
  firstButtonRead2 = digitalRead(BUTTON_1);
  if ( firstButtonRead1==firstButtonRead2){
      if(!firstButtonRead2){
          firstButtonPress=1;
          count1++;
          if (count1 >=100&&count1<300){
            firstButton1s=1;
            count2++;
            if(count2==49) flag1=0;
            if(count2>=50){
                count2=0;
              }
          } else if (count1 >=300){
            firstButton3s =1 ;
            count2++;
            if (count2==9) flag1 =0;
            if (count2 >=10){
                count2=0;
              }
            }
        }else{
            firstButtonPress=0;
            firstButton1s=0;
            firstButton3s=0;
            count1=0 ;
            count2=0;
          }
    }
}
void read_button_2(){
     secondButtonRead1=secondButtonRead2;
  secondButtonRead2 = digitalRead(BUTTON_2);
  if ( secondButtonRead1==secondButtonRead2){
      if(!secondButtonRead1&&firstButtonRead1){
          secondButtonPress=1;
          count3++;
          if (count3 >=ONE_SEC&&count3<THREE_SEC){
            secondButton1s=1;
            count4++;
            if (count4==49) flag1 =0; 
            if(count4>=50){
                count4=0;
              }
              
          } else if (count3 >=THREE_SEC){
            secondButton3s =1 ;
            count4++;
            if(count4==9) flag1 =0;
            if (count4 >=10){
                count4=0;
              }
            }
        }else{
            secondButtonPress=0;
            secondButton1s=0;
            secondButton3s=0;
            count3=0 ;
            count4=0;
          }
    }
};
void enable_timer(void(* func)()){
     timer1_isr_init();
  timer1_attachInterrupt(*func);
   timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP);
   timer1_write(50000);
   interrupts();
};
void init_gpio(){
    pinMode(D1 ,INPUT_PULLUP);
  pinMode(D2,INPUT_PULLUP);
}
void update_state(){switch (eState){
          case STATE1 : 
            if (firstButtonPress) {
                if(count <=127) count++;
                count =(count==128 )?0: count;
                eState =STATE2;
                Serial.println(count);
              }
             else if (secondButtonPress) {
               if(count>=0) count--;
               count =(count==-1 )?127: count;
                eState = STATE5;
                Serial.println(count);
             }
             break;
           case STATE2 : 
            if (!firstButtonPress) eState=STATE1;
            else if (firstButton1s) eState =STATE3;
            break;
           case STATE3 : 
              if (count2==49&&count<=127&&!flag1) {count++;
              count =(count==128 )?0: count;
              Serial.println(count);
              flag1=1;
              }
              if(!firstButtonPress) eState= STATE1;
              else if (firstButton3s) eState =STATE4;
              
              break;
           case STATE4: 
              if (count2==9&&count<=127&&!flag1){ count++;
              count =(count==128 )?0: count;
              Serial.println(count);
              flag1=1;
              }
              else if (!firstButtonPress) eState=STATE1;
              break;
           case STATE5: 
              if(!secondButtonPress) eState=STATE1;
              else if (secondButton1s) eState=STATE6;
              break;
           case STATE6 : 
              if(!secondButtonPress) eState=STATE1 ;
              else if (count4==49&&count>=0&&!flag1) {count --;
              if (count ==-1) count =127;
              Serial.println(count);
              flag1=1;
              }
              else if (secondButton3s) eState = STATE7;
              break;
           case STATE7 :
               if (!secondButtonPress) eState =STATE1;
               else if (!flag1) {
                  if(count4==9&&count>=0){
                    count--;
                    if (count ==-1) count =127;
                    Serial.println(count);
                    flag1=1;
                  } 
               }
               break;
        }
        }
