/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: usart.c

  Author: 郭世全    Version: v0.10.0    Date: 2016.02.19 

  Description:      usart的相关操作函数

  Others:         

  Function List:  

  History:        

    1. Date: 2016.02.19
       Author: 郭世全
       Modification: Create File and Frame    
******************************************************************************/

#include "..\ProgInc\usart.h"

/******************************************************************************

  Function:       void Uart1_Init(void) 

  Description:    初始化串口1,115200bps@33.1776MHz

  Calls:          1、void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.1,2016-02-22

******************************************************************************/

void Uart1_Init(void) 
{   
    /*8位数据,可变波特率*/
    SCON = 0x50;    

    /*定时器2时钟为Fosc,即1T*/    
    AUXR |= 0x04;    

    /*串口1选择定时器2为波特率发生器*/
    AUXR |= 0x01;        

    /*设定定时初值*/
    T2L = 0xB8;
    T2H = 0xFF;      

    /*启动定时器1*/
    AUXR |= 0x10;       
    
    /*拉高RI，TI电平,以便可以正常使用printf()*/
    RI = TI = 1; 
    
}