/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: pca.c

  Author: 郭世全    Version: v0.10.0    Date: 2016.02.19 

  Description:      PCA的相关操作函数

  Others:         

  Function List:  
    1.void PCA_Init(void)       PCA模块通用设置初始化
    2.void T38KHZ_Start(void)   38KHZ基波输出函数
    3.void T38KHZ_Stop(void)    38KHZ基波停止函数
    4.void T32HZ_Start(void)    32HZ安全引脚方波输出函数
    5.void T32HZ_Stop(void)     32HZ安全引脚方波停止函数

  History:        

    1. Date: 2016.02.19
       Author: 郭世全
       Modification: Create File and Frame   
******************************************************************************/

#include "..\ProgInc\pca.h"

/******************************************************************************

  Function:       void PCA_Init(void)

  Description:    初始化PCA模块的通用设置。

  Calls:          1、void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-05

******************************************************************************/

void PCA_Init(void)
{
     /*初始化CCON：PCA定时器停止，清除CF标志，清除模块中断标志*/ 
     CCON = 0;

     /*初始化PCA计数器*/ 
     CH = 0;
     CL = 0;

     /*PWM管脚定义方式2：P3.4/ECI_2, P3.5/CCP0_2, P3.6/CCP1_2, P3.7/CCP2_2*/ 
     AUXR1 = (AUXR1 & ~(3<<4)) | (1<<4);           

     /*设置PCA时钟源为SYSclk/8*/
     CMOD  = (CMOD  & ~(7<<1)) | (7<<1);   

     /*关闭PCA中端（ECF）*/
     CMOD  = CMOD  & ~1;  

     /*设置PCA中断为低优先级*/
     PPCA = 1;  

     /*默认所有的模块都关闭*/
     CCAPM0 = 0x00;     
     CCAPM1 = 0x00;
     CCAPM2 = 0x00;
}

/******************************************************************************

  Function:       void T38KHZ_Start(void)

  Description:    提供38KHZ 50% 基础PWM，先停止，后打开。

  Calls:          1、void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-06

******************************************************************************/

void T38KHZ_Start(void)
{
     /*初始化CCON：PCA定时器停止，清除CF标志，清除模块中断标志*/ 
     CCON = 0;

     /*初始化PCA计数器*/ 
     CH = 0;
     CL = 0;

     /*设置模块0为高速脉冲输出模式，并设置输出38KHZ方波*/
     CCAPM0 = 0x4d;

     CCAP0L = PCA0_value;
     CCAP0H = PCA0_value >> 8;

     PCA0_value += T38KHz;

     /*PCA模块开始计数*/
     CR = 1;
}

/******************************************************************************

  Function:       void T38KHZ_Stop(void)

  Description:    停止提供38KHZ 50% 基础PWM

  Calls:          1、void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-06

******************************************************************************/

void T38KHZ_Stop(void)
{
//     /*初始化CCON：PCA定时器停止，清除CF标志，清除模块中断标志*/ 
//     CCON = 0;

//     /*初始化PCA计数器*/ 
//     CH = 0;
//     CL = 0;

     /*关闭模块0*/
     CCAPM0 = 0x00;

     CCAP0L = 0x00;
     CCAP0H = 0x00;
    
     /*设置管脚输出为底电平*/
     P3 &= 0xDF;
}

/******************************************************************************

  Function:       void T32HZ_Start(void)

  Description:    提供32HZ 50% 方波，先停止，后打开。

  Calls:          1、void main(void);

  Called By:      // 调用本函数的函数清单

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-06

******************************************************************************/

void T32HZ_Start(void)
{
     /*初始化CCON：PCA定时器停止，清除CF标志，清除模块中断标志*/ 
     CCON = 0;

     /*初始化PCA计数器*/ 
     CH = 0;
     CL = 0;

     /*设置模块1为高速脉冲输出模式，并设置输出32HZ方波*/
     CCAPM1 = 0x4d;

     CCAP1L = PCA1_value;
     CCAP1H = PCA1_value >> 8;

     PCA1_value += T32HZ;

     /*PCA模块开始计数*/
     CR = 1;
}

/******************************************************************************

  Function:       void T32HZ_Stop(void)

  Description:    停止提供32HZ 50% 基础PWM

  Calls:          1、void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-06

******************************************************************************/

void T32HZ_Stop(void)
{
     /*初始化CCON：PCA定时器停止，清除CF标志，清除模块中断标志*/ 
     CCON = 0;

     /*初始化PCA计数器*/ 
     CH = 0;
     CL = 0;

     /*关闭模块0*/
     CCAPM1 = 0x00;

     CCAP1L = 0x00;
     CCAP1H = 0x00;
    
    /*设置管脚输出为底电平*/
     P3 &= 0xBF;
}
