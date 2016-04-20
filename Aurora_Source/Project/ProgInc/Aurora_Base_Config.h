/******************************************************************************
//************ <<< Use Configuration Wizard in Context Menu >>> ***************
//��������Keil Configuration Wized ����������ɾ��
//�ļ���Ҫ�����ANSI��ʽ��������ܻ��������

  Copyright (C), 2013-2016,  DiHongLongXi���������أ�
  
  File name: config.h

  Author: DHLX    Version: v0.10.0    Date: 2016.04.20

  Description:     �������IO���ú�����������������ĺ궨��

  Others:         

  Function List:  

  History:        
    
  Num. |    Date    |  Author  |  Modification
    1. | 2016.04.20 |   DHLX   |  �����ļ����ļ����   
******************************************************************************/



#ifndef __config_H
#define __config_H

//     <o.0>   PAGES: Page Size      <0=> 1M Byte    <1=> 4M Bytes
//                 <i> Selects Active Bits in Base Address
#define Hardware_Model 0


/*����STC15W408ASϵ�е�Ƭ���ײ�Ӳ�������ļ�*/
#include "..\ProgInc\STC15W408AS.H"

/*�ǵ���ģʽ�¿���ɾ��,Ϊ��ʹ��printf*/
#include "stdio.h"
#include "intrins.h"

/*������ʱ��, 33.1776MHz*/
#define MAIN_Fosc       33185792L

/*�����λ���Զ����أ��ܽŶ���*/
sbit System_IAP_REST_PIN = P3^0;

/*�ź�ָʾ�ƹܽŶ���*/
sbit Signal_LED_PIN = P3^7;

/*����ź�(�����ź�)���Ŷ���*/
sbit Check_Signal_PIN = P3^4;

/*ȫ�����ĹܽŶ���*/
sbit LED_FF_PIN = P1^2;

/*������ĹܽŶ���*/
sbit LED_L_PIN = P1^3;

/*�Ҳ����Ĺ̶ܽ���*/
sbit LED_R_PIN = P1^4;

/*����Ƿ���ڵ�ADC�Ĺ̶ܽ���*/
sbit ADC_Exist_PIN = P1^0;

/*����PCAʱ��Դ����SYSclk/8��38KHZ�����ɳ���*/
#define T38KHz (MAIN_Fosc / 16 / 38000)

/*����PCAʱ��Դ����SYSclk/8��32HZ�����ɳ���*/
#define T32HZ  (MAIN_Fosc / 16 / 32 )

/*����ϵͳ�Ƿ��ڵ��԰汾*/
/*#define DEBUG*/

/*ϵͳ��������ڵ��԰汾��Ĭ�ϴ��ڷ����汾*/
#ifndef DEBUG
    #define RELEASE
#endif

#endif /*__config_H */