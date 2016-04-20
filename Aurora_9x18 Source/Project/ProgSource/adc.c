/******************************************************************************
    Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.

    File name: adc.c

    Author: 郭世全    Version: v0.10.0    Date: 2016.02.19

    Description:      配置ADC函数和读取ADC函数的建立

    Others:         

    Function List:  

    1. void ADC_Init(void) 初始化ADC
    2. unsigned char Get_ADC_Result(void) 获取采样结果

    History:        

    1. Date: 2016.02.19
       Author: 郭世全
       Modification: Create File and Frame    
******************************************************************************/

#include "..\ProgInc\adc.H"

/******************************************************************************

  Function:       void ADC_Init(void)

  Description:    初始化ADC模块，P1.0口作为模拟功能A/D使用，540个时钟

  Calls:          1、void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-19

******************************************************************************/
void ADC_Init(void)
{
    /*设置P1.0口作为模拟功能A/D使用*/
    P1ASF = 0x01;     

    /*清除结果寄存器*/              
    ADC_RES  = 0;
    ADC_RESL = 0;
    
    /*P1.0输入，540个时钟，电源打开*/
    ADC_CONTR = 0x80;

    /*ADC_RES:高8位，ADC_RESL：低2位*/
    CLK_DIV &= 0xDF;
}

/******************************************************************************

  Function:       unsigned int Get_ADC_Result(void)

  Description:    获取P1.0的采样结果，10位

  Calls:          1、void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.2,2016-02-22

******************************************************************************/
unsigned int Get_ADC_Result(void)
{
   /*开启ADC转换*/
   ADC_CONTR |= 0x08;

   /*等待4个指令周期*/
   _nop_();                      
   _nop_();
   _nop_();
   _nop_();

   /*等待ADC转换完成*/
   while (!(ADC_CONTR & 0x10));

   /*关闭ADC转换，并清除标志位*/
   ADC_CONTR &= 0xE7;        

   /*返回ADC采样结果，10位*/
   return (ADC_RES << 2) | ADC_RESL;      
}