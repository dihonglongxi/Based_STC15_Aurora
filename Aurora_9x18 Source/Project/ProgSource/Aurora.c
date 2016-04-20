/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: BP-A1-CP_A.c

  Author: 郭世全    Version: v0.10.0    Date: 2016.02.05 

  Description:      本文件主要实现充电桩的主要功能。

                    1、引导轮式机器人找到充电桩的方位。
                    2、引导轮式机器人正确对准电极。
                    3、判断轮式机器人是否正确对准电极，是否有离开。
                    4、可靠的打开和关闭充电电源。
                    5、定时消息日志输出。

  Others:         

  Function List:  //主要函数列表，每条记录应包括函数名及功能简要说明

    待整理……
    1. ....

  History:        

    1. Date: 2016.02.05
       Author: 郭世全
       Modification: Create File and Frame    
    2. Date: 2016.02.23
       Author: 郭世全
       Modification: ADD IR Code
******************************************************************************/

/**************************系统配置（不可更改）***************************/

/*调用模块函数定义头文件*/
#include "..\ProgInc\adc.h"
#include "..\ProgInc\config.h"
#include "..\ProgInc\pca.h"
#include "..\ProgInc\tim.h"
#include "..\ProgInc\usart.h"

/*****************************************************************************/


/***************************系统配置（可更改）****************************/


/*PCA所需变量定义与初始化*/
unsigned int PCA0_value = T38KHz;
unsigned int PCA1_value = T32HZ;

/*TImer所需要的变量定义与初始化*/
unsigned int Timer = 0x00;
unsigned int Signal_LED_PIN_Timer = 0x00;
unsigned int Check_Signal_Timer = 0x00;
unsigned int ADC_Timer = 0x00;
unsigned int IR_Timer = 0x00;

/*状态值定义*/

/*0：机器人未在充电桩，1：机器人在充电桩*/
unsigned char System_State = 0;

/*定义一些缓存变量*/
unsigned int ADC_Buffer = 0;
unsigned char System_State_Buffer = 0;



/********************************主函数执行**********************************/

void main(void)
{
    /*设置红外输出引脚为推挽输出*/
    P1M1 = 0x00;
    P1M0 = 0x1C;
    
    /*PCA模块初始化*/
    PCA_Init();

    /*Timer定时器初始化*/
    Timer0_Init();
    
    /*串口初始化*/
    Uart1_Init();
    
    /*ADC的初始化*/
    ADC_Init();

    /*打开全局中断标识位*/
    EA = 1;

    /*系统上电，管脚初始化*/
    Signal_LED_PIN   = 0;
    Check_Signal_PIN = 0;

//    #ifdef DEBUG
//        /*启动32HZ和38KHZ方波输出*/
//        T38KHZ_Start();
//        T32HZ_Start();

//        Timer = 0;
//    
//        System_State = 1;
//    #endif

    /*输出初始化成功标识*/
    printf("%s","INIT DONE \r\n");

    while(1)
    {
        /*软件复位，不断电，自动下载*/
        if(System_IAP_REST_PIN == 0) IAP_CONTR = 0x60;
        
/***************************检查系统电极接触状态******************************/
        if(ADC_Timer == 198)
        {
            ADC_Buffer = Get_ADC_Result();
            printf("%d ",ADC_Buffer);
            
            /*清除系统状态*/
            System_State = 0;
            
            if((ADC_Buffer > 140) && (ADC_Buffer <250))
            {
                /*电极接触*/
                System_State = 1;
            }
            if(System_State != System_State_Buffer)
            {
                if(System_State == 0)
                {
                    T32HZ_Stop();
                    T38KHZ_Start();
                }
                else if(System_State == 1)
                {
                    T38KHZ_Stop();
                    T32HZ_Start();
                }
            }
            System_State_Buffer = System_State;
            printf("%d ",System_State_Buffer);
        }
        else if(ADC_Timer == 200)
        {
            ADC_Timer = 0;
        }
/*****************************************************************************/      
         
/************************系统状态为充电电极未接触状态*************************/
        if(System_State == 0)
        {
/*****************************指示灯部分代码程序******************************/
            /*未接触时，指示灯4S亮一次*/
            if(Signal_LED_PIN_Timer < 50)
            {
                Signal_LED_PIN = 1;
            }
            else if(Signal_LED_PIN_Timer >= 3999)
            {
                Signal_LED_PIN_Timer = 0;
                Signal_LED_PIN = 0;
            }
            else
            {
                Signal_LED_PIN = 0;
            }
/*****************************************************************************/

/****************************红外发射部分代码程序*****************************/

            if((IR_Timer >= 0) && (IR_Timer < 50))
            {

                /*全向红外发射序列*/
                /*1*/
                if((IR_Timer >= 0) && (IR_Timer < 3))
                {
                    LED_FF_PIN = 1;
                }
                else if(IR_Timer == 3)
                {
                    LED_FF_PIN = 0; 
                }
                /*0*/
                else if(IR_Timer == 4)
                {
                    LED_FF_PIN = 1;
                }
                else if((IR_Timer >= 5) && (IR_Timer < 7))
                {
                    LED_FF_PIN = 0;
                }
                /*0*/
                else if(IR_Timer == 7)
                {
                    LED_FF_PIN = 1;
                }
                else if((IR_Timer >= 8) && (IR_Timer < 10))
                {
                    LED_FF_PIN = 0;
                }
                /*1*/
                else if((IR_Timer >= 10) && (IR_Timer < 13))
                {
                    LED_FF_PIN = 1;
                }
                else if(IR_Timer == 13)
                {
                    LED_FF_PIN = 0; 
                }
                /*0*/
                else if(IR_Timer == 14)
                {
                    LED_FF_PIN = 1;
                }
                else if((IR_Timer >= 15) && (IR_Timer < 17))
                {
                    LED_FF_PIN = 0;
                }
                /*1*/
                else if((IR_Timer >= 17) && (IR_Timer < 20))
                {
                    LED_FF_PIN = 1;
                }
                else if(IR_Timer == 20)
                {
                    LED_FF_PIN = 0; 
                }
                /*0*/
                else if(IR_Timer == 21)
                {
                    LED_FF_PIN = 1;
                }
                else if((IR_Timer >= 22) && (IR_Timer < 24))
                {
                    LED_FF_PIN = 0; 
                }
                /*1*/
                else if((IR_Timer >= 24) && (IR_Timer < 27))
                {
                    LED_FF_PIN = 1; 
                }
                else
                {
                    LED_FF_PIN = 0;
                }

            }
            else if((IR_Timer >= 50) && (IR_Timer < 100))
            {
                /*左右侧红外发送序列*/
                /*L:0 R:0*/
                if(IR_Timer == 50)
                {
                    LED_L_PIN  = 1;
                    LED_R_PIN  = 1;
                }
                else if((IR_Timer >= 51) && (IR_Timer < 53))
                {
                    LED_L_PIN  = 0;
                    LED_R_PIN  = 0;  
                }
                /*L:0 R:0*/
                else if(IR_Timer == 53)
                {
                    LED_L_PIN  = 1;
                    LED_R_PIN  = 1;
                }
                else if((IR_Timer >= 54) && (IR_Timer < 56))
                {
                    LED_L_PIN  = 0;
                    LED_R_PIN  = 0;  
                }
                /*L:1 R:0*/
                /*L:0 R:1*/
                else if(IR_Timer == 56)
                {
                    LED_L_PIN  = 1;
                    LED_R_PIN  = 1; 
                }
                else if((IR_Timer >= 57) && (IR_Timer < 59))
                {
                    LED_L_PIN  = 1;
                    LED_R_PIN  = 0;  
                }
                else if(IR_Timer == 59)
                {
                    LED_L_PIN  = 0;
                    LED_R_PIN  = 1; 
                }
                else if(IR_Timer == 60)
                {
                    LED_L_PIN  = 1;
                    LED_R_PIN  = 1; 
                }
                else if(IR_Timer == 61)
                {
                    LED_L_PIN  = 0;
                    LED_R_PIN  = 1; 
                }
                else if(IR_Timer == 62)
                {
                    LED_L_PIN  = 0;
                    LED_R_PIN  = 0; 
                }
                /*L:0 R:0*/
                else if(IR_Timer == 63)
                {
                    LED_L_PIN  = 1;
                    LED_R_PIN  = 1;
                }
                else if((IR_Timer >= 64) && (IR_Timer < 66))
                {
                    LED_L_PIN  = 0;
                    LED_R_PIN  = 0;  
                }
                /*L:1 R:1*/
                else if((IR_Timer >= 66) && (IR_Timer < 69))
                {
                    LED_L_PIN  = 1;
                    LED_R_PIN  = 1;  
                }
                else if(IR_Timer == 69)
                {
                    LED_L_PIN  = 0;
                    LED_R_PIN  = 0;
                }              
                /*L:0 R:0*/
                else if(IR_Timer == 70)
                {
                    LED_L_PIN  = 1;
                    LED_R_PIN  = 1;
                }
                else if((IR_Timer >= 71) && (IR_Timer < 73))
                {
                    LED_L_PIN  = 0;
                    LED_R_PIN  = 0;  
                }
                /*L:1 R:1*/
                else if((IR_Timer >= 73) && (IR_Timer < 76))
                {
                    LED_L_PIN  = 1;
                    LED_R_PIN  = 1; 
                }
                else
                {
                    LED_L_PIN  = 0;
                    LED_R_PIN  = 0;  
                }
            }
            else if((IR_Timer >= 100))
            {
                IR_Timer = 0;
                LED_FF_PIN = 0;
                LED_L_PIN  = 0;
                LED_R_PIN  = 0;
            }





/*****************************************************************************/

        }

/**************************统状态为充电电极接触状态***************************/
        else if(System_State == 1)
        {

/*****************************指示灯部分代码程序******************************/
            /*接触时，指示灯常量*/
            Signal_LED_PIN = 1;
            Signal_LED_PIN_Timer = 0;
/*****************************************************************************/

/************************发射检测信号部分代码程序*****************************/
            if(Check_Signal_Timer < 190)
            {
                Check_Signal_PIN = 1;
            }
            else if((Check_Signal_Timer >= 197) && (Check_Signal_Timer < 200 ))
            {
                Check_Signal_PIN = 0;
            }
            else if(Check_Signal_Timer >= 200)
            {
                Check_Signal_Timer = 0;
                Check_Signal_PIN = 1;
            }
/*****************************************************************************/
        }  
    }
}










