#ifndef BUTTONLAB_H
#define BUTTONLAB_H

#include <Arduino.h>


#define INTERVAL 10
#define ONE_SEC 100
#define THREE_SEC 300
#define INTERVAL_1  50
#define INTERVAL_2 10
#define BUTTON_1 D1
#define BUTTON_2 D2


extern bool firstButtonRead1 ,firstButtonRead2, secondButtonRead1, secondButtonRead2 ;
extern bool firstButton1s  , firstButton3s;
extern bool secondButton1s  , secondButton3s;
extern bool firstButtonPress ,secondButtonPress;
extern bool flag1, flag2;
extern unsigned int count1 , count2, count3,count4 ;
extern unsigned int count;

void read_button_1();
void read_button_2();
void enable_timer(void(* func)());
void update_state();
void init_gpio();

#endif
