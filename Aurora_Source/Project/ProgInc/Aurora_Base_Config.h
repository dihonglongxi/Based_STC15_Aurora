/******************************************************************************
//************ <<< Use Configuration Wizard in Context Menu >>> ***************
//��������Keil Configuration Wized ����������ɾ��
//�ļ���Ҫ�����GBK��ANSI����ʽ��������ܻ��������

  Copyright (C), 2013-2016,  DiHongLongXi���������أ�
  
  File name: Aurora_Base_Config.h

  Author: DHLX    Version: v0.10.0    Date: 2016.04.20

  Description:     �����������IO���ú������������á���������Ķ���

  Others:         

  Function List:  

  History:        
    
  Num. |    Date    |  Author  |  Modification
    1. | 2016.04.20 |   DHLX   |  �����ļ����ļ����   
    2. | 2016.04.24 |   DHLX   |  �����ⲿ�ļ�����õĺ궨�塢�����ͺ���ԭ��
    3. | 2016.04.26 |   DHLX   |  ���ӹܽš�MOS���ضϲ���ʱ��ĺ궨��
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
/*P11-P12�ֱ�����COL1-COL7*/
#define COL_Low_Port        P1
/*P54��P55�ֱ�����COL8��COL9 */
#define COL_High_Port       P5
/*��������CCP_S0��CCP_S1ѡ������
  0x00:(P1.2/ECI, P1.1/CCP0, P1.0/CCP1, P3.7/CCP2) 
  0x10:(P3.4/ECI_2, P3.5/CCP0_2, P3.6/CCP1_2, P3.7/CCP2_2) 
  0x20:(P2.4/ECI_3, P2.5/CCP0_3, P2.6/CCP1_3, P2.7/CCP2_3)*/
#define RGB_Port            0x10

/*����ܽſ��ض�ʱ�䲹��*/
#define PIN_Time_Diff       0

/*�������¹�MOS���ض�ʱ�䲹��*/
#define High_MOS_Time_Diff  0
#define Low_MOS_Time_Diff   0

/*���¶�����Ϊ�˳��������Ķ����Ǳ�Ҫ���������*/
#define BUS_OPEN()          CR = 1    
#define BUS_CLOSE()         CR = 0 

#define R_BUS_RMS           CCAP0H = CCAP0L
#define G_BUS_RMS           CCAP1H = CCAP1L
#define B_BUS_RMS           CCAP2H = CCAP2L

/*����ϵͳ�Ƿ��ڵ��԰汾*/
#define DEBUG

/*ϵͳ��������ڵ��԰汾��Ĭ�ϴ��ڷ����汾*/
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
/*********** (C) COPYRIGHT DiHongLongXi���������أ� *****END OF FILE***********/
