/******************************************************************************
//************ <<< Use Configuration Wizard in Context Menu >>> ***************
//用于引导Keil Configuration Wized 启动，请勿删除
//文件需要保存成ANSI格式，否则可能会产生乱码

  Copyright (C), 2013-2016,  DiHongLongXi（帝鴻龍曦）
  
  File name: config.h

  Author: DHLX    Version: v0.10.0    Date: 2016.04.20

  Description:     用于输出IO配置和其他功能配置所需的宏定义

  Others:         

  Function List:  

  History:        
    
  Num. |    Date    |  Author  |  Modification
    1. | 2016.04.20 |   DHLX   |  创建文件和文件框架   
******************************************************************************/



#ifndef __config_H
#define __config_H

//     <o.0>   PAGES: Page Size      <0=> 1M Byte    <1=> 4M Bytes
//                 <i> Selects Active Bits in Base Address
#define Hardware_Model 0


/*调用STC15W408AS系列单片机底层硬件定义文件*/
#include "..\ProgInc\STC15W408AS.H"

/*非调试模式下可以删除,为了使用printf*/
#include "stdio.h"
#include "intrins.h"

/*定义主时钟, 33.1776MHz*/
#define MAIN_Fosc       33185792L

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