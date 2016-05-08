/******************************************************************************
//************ <<< Use Configuration Wizard in Context Menu >>> ***************
//用于引导Keil Configuration Wized 启动，请勿删除
//文件需要保存成GBK（ANSI）格式，否则可能会产生乱码

  Copyright (C), 2013-2016,  DiHongLongXi（帝鴻龍曦）
  
  File name: Aurora_Base_Config.h

  Author: DHLX    Version: v0.10.0    Date: 2016.04.20

  Description:     用于输出输入IO配置和其他功能配置、常数所需的定义

  Others:         

  Function List:  

  History:        
    
  Num. |    Date    |  Author  |  Modification
    1. | 2016.04.20 |   DHLX   |  创建文件和文件框架   
    2. | 2016.04.24 |   DHLX   |  定义外部文件需调用的宏定义、常量和函数原型
    3. | 2016.04.26 |   DHLX   |  增加管脚、MOS开关断补偿时间的宏定义
******************************************************************************/

/* Define to prevent recursive inclusion -------- ---------------------------*/
#ifndef __Aurora_Base_Config_H
#define __Aurora_Base_Config_H

/* Includes -----------------------------------------------------------------*/
#include "STC15F2K60S2.H"

/* Exported types -----------------------------------------------------------*/

/* Exported constants -------------------------------------------------------*/
#define Main_Fosc           27000000L

/* Exported macro -----------------------------------------------------------*/
#define Button_PIN          P32
#define IR_PIN              P33
#define Analog_Sound_PIN    P10
/*P11-P12分别用于COL1-COL7*/
#define COL_Low_Port        P1
/*P54，P55分别用于COL8，COL9 */
#define COL_High_Port       P5
/*用于设置CCP_S0，CCP_S1选择引脚
  0x00:(P1.2/ECI, P1.1/CCP0, P1.0/CCP1, P3.7/CCP2) 
  0x10:(P3.4/ECI_2, P3.5/CCP0_2, P3.6/CCP1_2, P3.7/CCP2_2) 
  0x20:(P2.4/ECI_3, P2.5/CCP0_3, P2.6/CCP1_3, P2.7/CCP2_3)*/
#define RGB_Port            0x10

/*定义管脚开关断时间补偿*/
#define PIN_Time_Diff       0

/*定义上下管MOS开关断时间补偿*/
#define High_MOS_Time_Diff  0
#define Low_MOS_Time_Diff   0

/*以下定义是为了程序容易阅读，非必要，请勿更改*/
#define BUS_OPEN()          CR = 1    
#define BUS_CLOSE()         CR = 0 

#define R_BUS_RMS           CCAP0H = CCAP0L
#define G_BUS_RMS           CCAP1H = CCAP1L
#define B_BUS_RMS           CCAP2H = CCAP2L

/*定义系统是否处于调试版本*/
#define DEBUG

/*系统如果不处于调试版本，默认处于发布版本*/
#ifndef DEBUG
    #define RELEASE
#endif

/* Exported functions prototypes --------------------------------------------*/
void System_Init (void);

/* Private types ------------------------------------------------------------*/

/* Private defines ----------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/

/* Private constants --------------------------------------------------------*/

/* Private macros -----------------------------------------------------------*/

/* Private functions prototypes ---------------------------------------------*/

/* Private functions --------------------------------------------------------*/


#endif /* __Aurora_Base_Config_H */
/*********** (C) COPYRIGHT DiHongLongXi（帝鴻龍曦） *****END OF FILE***********/
