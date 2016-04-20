/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: tim.c

  Author: 郭世全    Version: v0.10.0    Date: 2016.02.19 

  Description:     tim的相关操作函数

  Others:         

  Function List:  //主要函数列表，每条记录应包括函数名及功能简要说明

    待整理……
    1. ....

  History:        

    1. Date: 2016.02.19
       Author: 郭世全
       Modification: Create File and Frame    
******************************************************************************/

#include "..\ProgInc\tim.H"

/******************************************************************************

  Function:       void Timer0_Init(void) 

  Description:    1毫秒@33.1776MHz

  Calls:          1、void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-05

******************************************************************************/

void Timer0_Init(void)         
{
    /*定时器时钟1T模式*/
    AUXR |= 0x80;       
    
    /*设置定时器模式*/
    TMOD &= 0xF0;
    
    /*开始定时器中断*/
    ET0 = 1;
     
    /*设置定时初值*/
    TL0 = 0x66;         
    TH0 = 0x7E; 

    /*清除TF0标志*/
    TF0 = 0;
     
    /*定时器0开始计时*/
    TR0 = 1;       
    
    
}