/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: it.h

  Author: 郭世全    Version: v0.10.0    Date: 2016.02.19 

  Description:     中断相关函数的定义，常数初始化

  Others:         

  Function List:  

  History:        

    1. Date: 2016.02.05
       Author: 郭世全
       Modification: Create File and Frame    
******************************************************************************/
#ifndef __it_H
#define __it_H

#include "..\ProgInc\config.h"

/*PCA所需变量定义与初始化*/
extern unsigned int PCA0_value;
extern unsigned int PCA1_value;

/*TImer所需要的变量定义与初始化*/
extern unsigned int Timer;
extern unsigned int Signal_LED_PIN_Timer;
extern unsigned int Check_Signal_Timer;
extern unsigned int ADC_Timer;
extern unsigned int IR_Timer;

/*0：机器人未在充电桩，1：机器人在充电桩*/
extern unsigned char System_State;

#endif /*__it_H */