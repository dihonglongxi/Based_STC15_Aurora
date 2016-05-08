/***********************************************************************************************************************
* File Name    : Aurora_IR.c
* Version      : Keil Version: 9.52.0.0
* Device(s)    : HX1838
* Tool-Chain   : C51 V9.52
* Description  : 红外接收程序。适用于市场上用量最大的HT6121/6122及其兼容IC的编码。
* Creation Date: 2013/11/17
***********************************************************************************************************************/
#ifndef Aurora_IR_H
#define Aurora_IR_H

#ifndef uchar 
#define uchar unsigned char
#endif

#ifndef uint 
#define uint unsigned int
#endif

/*************	用户系统配置	**************/

#define MAIN_Fosc		25000000L	//定义主时钟, 模拟串口和红外接收会自动适应。5~36MHZ

#define D_TIMER0		125			//选择定时器时间, us, 红外接收要求在60us~250us之间

#define	User_code		0xBF00		//定义红外接收用户码

sbit	P_IR_RX = P2 ^ 0;		//定义红外接收输入端口

/*************	以下宏定义用户请勿修改	**************/

#define freq_base			(MAIN_Fosc / 1200)
#define Timer1_Reload		(65536 - (D_TIMER0 * freq_base / 10000))

#if ((D_TIMER0 <= 250) && (D_TIMER0 >= 60))
#define	D_IR_sample			D_TIMER0		//定义采样时间，在60us~250us之间
#endif

#define D_IR_SYNC_MAX		(15000/D_IR_sample)	//SYNC max time
#define D_IR_SYNC_MIN		(9700 /D_IR_sample)	//SYNC min time
#define D_IR_SYNC_DIVIDE	(12375/D_IR_sample)	//decide data 0 or 1
#define D_IR_DATA_MAX		(3000 /D_IR_sample)	//data max time
#define D_IR_DATA_MIN		(600  /D_IR_sample)	//data min time
#define D_IR_DATA_DIVIDE	(1687 /D_IR_sample)	//decide data 0 or 1
#define D_IR_BIT_NUMBER		32					//bit number

/**** 外部变量引用声明 ******************/
extern  bit		B_IrUserErr;	//User code error flag
extern  bit		B_IR_Press;		//Key press flag,include repeat key.
extern  uchar	IR_code;			//IR code	红外键码

/*************	函数声明	**************/
void IR_RX_HT6121(void);
void InitTimer1(void);

#endif
