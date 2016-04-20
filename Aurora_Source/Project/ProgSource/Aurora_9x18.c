/******************************************************************************
  Copyright(C), 2015, 龙曦工作室
  
  File name: Aurora_9x18.c

  Author: 郭世全 Version: v0.10.0 Date: 2015.03.25 Website: longxi-team.cn

  Description:    // 用于详细说明此程序文件完成的主要功能，与其他模块

                  // 或函数的接口，输出值、取值范围、含义及参数间的控

                  // 制、顺序、独立或依赖等关系

  Others:         // 其它内容的说明

  Function List:  // 主要函数列表，每条记录应包括函数名及功能简要说明

    1. ....

  History:        

    1. Date: 2015.02.25
       Author: 郭世全
       Modification: 建立Aurora_9x18.c框架

    2. ..
******************************************************************************/

/**************************系统配置（用户不可更改）***************************/
/*调用STC15F2K60S2底层硬件定义头文件*/
#include "..\ProgInc\STC15F2K60S2.H"
#include  <stdio.h> //调试串口输出使用

/*定义主时钟, 27MHz*/
#define MAIN_Fosc       27000000L

/*****************************************************************************/


/***************************系统配置（用户可更改）****************************/

/********************************PWM参数设置**********************************/
/*设置最大PWM值*/
#define MAX_DUTY 0xFF
/*补偿LED/列驱动器的关闭时间*/
#define PORT_DELAY 42
/*补偿LED/列驱动器的开启时间*/
#define PORT_DELAY_COMP 0
/*补偿RGB驱动关闭时间*/
#define PORT_BLANK 68
/*LED refresh time = (pr_value+1)*(3*127+1)*Tcy = (pr_value+1)*382*Tcy*/
/*动态频率为 225 Hz，Tcy = 74.1ns*/
#define PR_VALUE 157

/*空闲模式下PCA计数，sysclk/2做脉冲源，无中断*/
#define CMOD_VAL 0x02
/*使能PWM模式*/
#define CCAPMX_VAL 0x82
/*设置PWM工作在8位PWM模式下*/
#define PCA_PWMX_VAL 0x00
/*设置PWM的输出管脚为P35、P36、P37*/
#define P_SW1_VAL ((P_SW1 & 0xCF) | 0x10)
/*设置PWM开启标识*/
#define PWM_START 1
/*设置PWM结束标识*/
#define PWM_END 0
/*****************************************************************************/

/******************************COL＆ROW驱动参数*******************************/
#define COL_POL 0                    /*1-9灯圈驱动为低电平有效*/
#define ROW_POL 1                    /*RGB驱动为高电平有效*/

#define num_COLs 9                   /*圈数为9*/
#define num_ROWs 1                   /*行数等效为1*/
#define num_LEDs num_COLs*num_ROWs   /*等效总LED数为9*/
/*****************************************************************************/

/*****************************端口与I / O引脚映射*****************************/
/*LED控制端口定义*/
#define LED_1_PIN P11
#define LED_2_PIN P12
#define LED_3_PIN P13
#define LED_4_PIN P14
#define LED_5_PIN P15
#define LED_6_PIN P16
#define LED_7_PIN P17
#define LED_8_PIN P54
#define LED_9_PIN P55

/*RGB总线（PWM）端口定义*/
#define PWM_R_PIN P35
#define PWM_G_PIN P36
#define PWM_B_PIN P37

/*RGB总线输出脉宽（低电平输出时间）*/
#define PWM_R_VALUE CCAP0H
#define PWM_G_VALUE CCAP1H
#define PWM_B_VALUE CCAP2H

/*RGB总线全局设定项*/
#define PWM_GLOBAL_SETTINGS CMOD

/*RGB总线输出使能*/
#define PWM_R_ENABLE CCAPM0
#define PWM_G_ENABLE CCAPM1
#define PWM_B_ENABLE CCAPM2

/*RGB总线输出模式*/
#define PWM_R_MODE PCA_PWM0
#define PWM_G_MODE PCA_PWM1
#define PWM_B_MODE PCA_PWM2

/*RGB总线输出控制*/
#define PWM_OUTPUT_CONTROL CR
/*****************************************************************************/

/*********************************动画参数************************************/
typedef struct anim_params
{
    unsigned char delay;
    unsigned char duty_diff;
    unsigned char step_up;
    unsigned char step_down;
    unsigned char update_rate;
    unsigned char update;
    unsigned char max_duty;
    unsigned char release_waitH;         /*将在多长时间后进行高电平输出*/
    unsigned char release_waitL;         /*将在多长时间后进行低电平输出*/
    unsigned char anim_flags;
    unsigned char release_cnt[num_LEDs]; /*每行LED的持续点亮时间*/
}anim_params;

anim_params RED,GREEN,BLUE;
        
/*****************************************************************************/

/************LED data - duty levels, and other parameters/flags***************/

unsigned char LED_data_R[num_LEDs];
unsigned char LED_data_G[num_LEDs];
unsigned char LED_data_B[num_LEDs];

/*****************************************************************************/

/************************for LED refresh/interrupt****************************/
unsigned char RGB;

unsigned char duty_buff_R[num_LEDs];
unsigned char duty_buff_G[num_LEDs];
unsigned char duty_buff_B[num_LEDs];
unsigned char port_buff[3];

/*****************************************************************************/

/*****************************************************************************/

/******************************************************************************
  Function:       void aurora_init(void)

  Description:    用于Aurora设备初始化

  Calls:          // 被本函数调用的函数清单

  Called By:      // 调用本函数的函数清单

  Table Accessed: // 被访问的表（此项仅对于牵扯到数据库操作的程序）

  Table Updated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）

  Input:          // 输入参数说明，包括每个参数的作

                  // 用、取值说明及参数间关系。

  Output:         // 对输出参数的说明。

  Return:         // 函数返回值的说明

  Others:         // 其它说明

******************************************************************************/
void aurora_init(void)
{
    ;
}

void UartInit(void)		//9600bps@27MHz
{
	SCON = 0x50;		//8位数据,可变波特率
	AUXR |= 0x40;		//定时器1时钟为Fosc,即1T
	AUXR &= 0xFE;		//串口1选择定时器1为波特率发生器
	TMOD &= 0x0F;		//设定定时器1为16位自动重装方式
	TL1 = 0x41;		//设定定时初值
	TH1 = 0xFD;		//设定定时初值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
    ES = 0;             //禁止串行口中断
    TI = 1;             //必须置高TI,RI
    RI = 1;
    printf("Uart Initialize Success!\n");
}

void main()
{
    int a;
    a = P_SW1_VAL;
    UartInit();
    printf ("P_SW1_VAL %d\n",a);
    while(1)
    {
        if(P30 == 0) IAP_CONTR = 0x60;;
    }
}


void Timer0() interrupt 1 using 1
{
  ;
}

void Timer2() interrupt 2 using 1
{
    switch(RGB)
    {
        case 0:

        case 1:

        case 2:

        case 3:

        default:
            RGB = 0;
            break;
    }
}






/*************************************************

  Function:       // 函数名称

  Description:    // 函数功能、性能等的描述

  Calls:          // 被本函数调用的函数清单

  Called By:      // 调用本函数的函数清单

  Table Accessed: // 被访问的表（此项仅对于牵扯到数据库操作的程序）

  Table Updated:  // 被修改的表（此项仅对于牵扯到数据库操作的程序）

  Input:          // 输入参数说明，包括每个参数的作

                  // 用、取值说明及参数间关系。

  Output:         // 对输出参数的说明。

  Return:         // 函数返回值的说明

  Others:         // 其它说明

*************************************************/

//void PWM_INIT()
//{
///*PWM管脚定义方式1：P1.2/ECI, P1.1/CCP0, P1.0/CCP1, P3.7/CCP2*/    
//#if PWM_PIN == 1
//    ACC = P_SW1;
//    ACC &= ~(CCP_S0 | CCP_S1);      /*CCP_S0=0;CCP_S1=0*/
//    P_SW1 = ACC;                   
//#endif

///*PWM管脚定义方式2：P3.4/ECI_2, P3.5/CCP0_2, P3.6/CCP1_2, P3.7/CCP2_2*/ 
//#if PWM_PIN == 2
//    ACC = P_SW1;
//    ACC &= ~(CCP_S0 | CCP_S1);      /*CCP_S0=1;CCP_S1=0*/
//    ACC |= CCP_S0;                  
//    P_SW1 = ACC;  
//#endif

///*PWM管脚定义方式3：P2.4/ECI_3, P2.5/CCP0_3, P2.6/CCP1_3, P2.7/CCP2_3*/ 
//#if PWM_PIN == 3
//    ACC = P_SW1;
//    ACC &= ~(CCP_S0 | CCP_S1);      /*CCP_S0=0;CCP_S1=1*/
//    ACC |= CCP_S1;                  
//    P_SW1 = ACC;
//#endif

////    CCON = 0;                       //初始化PCA控制寄存器
////    //PCA定时器停止
////    //清除CF标志
////    //清除模块中断标志
////    CL = 0;                         //复位PCA寄存器
////    CH = 0;
////    CMOD = 0x02;                    //设置PCA时钟源
////    //允许PCA定时器溢出中断

////    PCA_PWM0 = 0x03;                //PCA模块0工作于8位PWM
////    PWM_R = 255;                    //PWM0的占空比为87.5% ((100H-20H)/100H) 占空比255 没有高点平 高有效驱动
////    CCAPM0 = 0x53;                  //PWM,由高变低产生中断

////    PCA_PWM1 = 0x03;                //PCA模块1
////    PWM_G = 255;
////    CCAPM1 = 0x53;

////    PCA_PWM2 = 0x03;                //PCA模块2
////    PWM_B = 255;
////    CCAPM2 = 0x53;

////    EA = 1;                         //系统总中断
////    PWM_OFF;                         //PCA定时器开始工作
//}
