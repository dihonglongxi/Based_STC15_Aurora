/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: it.h

  Author: ����ȫ    Version: v0.10.0    Date: 2016.02.19 

  Description:     �ж���غ����Ķ��壬������ʼ��

  Others:         

  Function List:  

  History:        

    1. Date: 2016.02.05
       Author: ����ȫ
       Modification: Create File and Frame  
******************************************************************************/
#ifndef __it_H
#define __it_H

#include "..\ProgInc\config.h"

/*PCA��������������ʼ��*/
extern unsigned int PCA0_value;
extern unsigned int PCA1_value;

/*TImer����Ҫ�ı����������ʼ��*/
extern unsigned int Timer;
extern unsigned int Signal_LED_PIN_Timer;
extern unsigned int Check_Signal_Timer;
extern unsigned int ADC_Timer;
extern unsigned int IR_Timer;

/*0��������δ�ڳ��׮��1���������ڳ��׮*/
extern unsigned char System_State;

#endif /*__it_H */