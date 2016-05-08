/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: it.c

  Author: 郭世全    Version: v0.10.0    Date: 2016.02.05 

  Description:     各种中断的相关操作。

  Others:         

  Function List: 

  History:        

    1. Date: 2016.02.19
       Author: 郭世全
       Modification: Create File and Frame    
******************************************************************************/

#include "..\ProgInc\it.h"
#include "..\ProgInc\pca.h"

/******************************************************************************

  Function:       void T0_time() interrupt 1 using 1 

  Description:    更新相关的软件定时器参数

  Calls:          None

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-05

******************************************************************************/

void T0_isr() interrupt 1 using 1
{
    /*不管系统状态，处于什么样，均200MS检测一次ADC*/
    ADC_Timer++;

    /*系统状态为充电电极未接触状态*/
    if(System_State == 0)
    {
        Signal_LED_PIN_Timer ++;
        IR_Timer++;
    }
    /*系统状态为充电电极接触状态*/
    else if(System_State == 1)
    {
        Check_Signal_Timer = ADC_Timer;     
    }
}


/******************************************************************************

  Function:       void PCA_isr() interrupt 7 using 1

  Description:    PCA中断，更新38KHZ，32HZ的参数值

  Calls:          None

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-06

******************************************************************************/
void PCA_isr() interrupt 7 using 2
{
    /*模块0的处理函数，38KHZ波*/
     if(CCF0 == 1)
     {
          CCF0 = 0;                       //清中断标志

          CCAP0L = PCA0_value;            //更新比较值
          CCAP0H = PCA0_value >> 8;            

          PCA0_value += T38KHz;
     }
     /*模块1的处理函数，32HZ波*/
     else if (CCF1 == 1)
     {
          CCF1 = 0;                       //清中断标志

          CCAP1L = PCA1_value;            //更新比较值
          CCAP1H = PCA1_value >> 8;

          PCA1_value += T32HZ;
     }

}