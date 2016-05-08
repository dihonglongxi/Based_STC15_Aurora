/***********************************************************************************************************************
* File Name    : Aurora_IR.c
* Version      : Keil Version: 9.52.0.0
* Device(s)    : HX1838
* Tool-Chain   : C51 V9.52
* Description  : ������ճ����������г�����������HT6121/6122�������IC�ı��롣
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

/*************	�û�ϵͳ����	**************/

#define MAIN_Fosc		25000000L	//������ʱ��, ģ�⴮�ںͺ�����ջ��Զ���Ӧ��5~36MHZ

#define D_TIMER0		125			//ѡ��ʱ��ʱ��, us, �������Ҫ����60us~250us֮��

#define	User_code		0xBF00		//�����������û���

sbit	P_IR_RX = P2 ^ 0;		//��������������˿�

/*************	���º궨���û������޸�	**************/

#define freq_base			(MAIN_Fosc / 1200)
#define Timer1_Reload		(65536 - (D_TIMER0 * freq_base / 10000))

#if ((D_TIMER0 <= 250) && (D_TIMER0 >= 60))
#define	D_IR_sample			D_TIMER0		//�������ʱ�䣬��60us~250us֮��
#endif

#define D_IR_SYNC_MAX		(15000/D_IR_sample)	//SYNC max time
#define D_IR_SYNC_MIN		(9700 /D_IR_sample)	//SYNC min time
#define D_IR_SYNC_DIVIDE	(12375/D_IR_sample)	//decide data 0 or 1
#define D_IR_DATA_MAX		(3000 /D_IR_sample)	//data max time
#define D_IR_DATA_MIN		(600  /D_IR_sample)	//data min time
#define D_IR_DATA_DIVIDE	(1687 /D_IR_sample)	//decide data 0 or 1
#define D_IR_BIT_NUMBER		32					//bit number

/**** �ⲿ������������ ******************/
extern  bit		B_IrUserErr;	//User code error flag
extern  bit		B_IR_Press;		//Key press flag,include repeat key.
extern  uchar	IR_code;			//IR code	�������

/*************	��������	**************/
void IR_RX_HT6121(void);
void InitTimer1(void);

#endif
