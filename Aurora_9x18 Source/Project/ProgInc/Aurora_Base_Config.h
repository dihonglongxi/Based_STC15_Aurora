/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: config.h

  Author: 郭世全    Version: v0.10.0    Date: 2016.02.19 

  Description:     用于配置IO和系统宏定义

  Others:         

  Function List:  

  History:        

    1. Date: 2016.02.19
       Author: 郭世全
       Modification: Create File and Frame    
******************************************************************************/

// <<< Use Configuration Wizard in Context Menu >>> 

#ifndef __config_H
#define __config_H

/*调用STC15W408AS系列单片机底层硬件定义文件*/
#include "..\ProgInc\STC15W408AS.H"

/*非调试模式下可以删除,为了使用printf*/
#include "stdio.h"
#include "intrins.h"

/*定义主时钟, 33.1776MHz*/
#define MAIN_Fosc       33177600L

/*软件复位，自动下载，管脚定义*/
sbit System_IAP_REST_PIN = P3^0;

/*信号指示灯管脚定义*/
sbit Signal_LED_PIN = P3^7;

/*检查信号(开关信号)引脚定义*/
sbit Check_Signal_PIN = P3^4;

/*全向红外的管脚定义*/
sbit LED_FF_PIN = P1^2;

/*左侧红外的管脚定义*/
sbit LED_L_PIN = P1^3;

/*右侧红外的管教定义*/
sbit LED_R_PIN = P1^4;

/*检测是否存在的ADC的管教定义*/
sbit ADC_Exist_PIN = P1^0;

/*定义PCA时钟源处于SYSclk/8，38KHZ的生成常数*/
#define T38KHz (MAIN_Fosc / 16 / 38000)

/*定义PCA时钟源处于SYSclk/8，32HZ的生成常数*/
#define T32HZ  (MAIN_Fosc / 16 / 32 )

/*定义系统是否处于调试版本*/
/*#define DEBUG*/

/*系统如果不处于调试版本，默认处于发布版本*/
#ifndef DEBUG
    #define RELEASE
#endif

#endif /*__config_H */