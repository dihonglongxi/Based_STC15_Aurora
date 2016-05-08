
/***********************************************************************************************************************
* File Name    : Aurora_IR.c
* Version      : Keil Version: 9.52.0.0
* Device(s)    : HX1838
* Tool-Chain   : C51 V9.52
* Description  : 红外接收程序。适用于市场上用量最大的HT6121/6122及其兼容IC的编码。
* Creation Date: 2013/11/17
***********************************************************************************************************************/
#include "stc15f2k60s2.h"
#include "intrins.h"
#include "Aurora_IR.h"

/*************	本地变量声明	**************/

bit		P_IR_RX_temp;		//Last sample
bit		B_IR_Sync;			//已收到同步标志
uchar	IR_SampleCnt;		//采样计数
uchar	IR_BitCnt;			//编码位数
uchar	IR_UserH;			//用户码(地址)高字节
uchar	IR_UserL;			//用户码(地址)低字节
uchar	IR_data;			//数据原码
uchar	IR_DataShit;		//数据反码

bit		B_IrUserErr;		//User code error flag
bit		B_IR_Press;			//Key press flag,include repeat key.
uchar	IR_code;			//IR code	红外键码

//*********************** IR Remote Module **************************
//this programme is used for Receive IR Remote (HT6121).

//data format: Synchro,AddressH,AddressL,data,/data, (total 32 bit).

//send a frame(85ms), pause 23ms, send synchro of another frame, pause 94ms

//data rate: 108ms/Frame


//Synchro:low=9ms,high=4.5/2.25ms,low=0.5626ms
//Bit0:high=0.5626ms,low=0.5626ms
//Bit1:high=1.6879ms,low=0.5626ms
//frame space = 23 ms or 96 ms


//*******************************************************************************************
//**************************** IR RECEIVE MODULE ********************************************

void IR_RX_HT6121(void)
{
	uchar	SampleTime;

	IR_SampleCnt++;							//Sample + 1

	F0 = P_IR_RX_temp;						//Save Last sample status
	P_IR_RX = 1;
	P_IR_RX_temp = P_IR_RX;					//Read current status
	if (F0 && !P_IR_RX_temp)					//Last sample is high，and current sample is low, so is fall edge
	{
		SampleTime = IR_SampleCnt;			//get the sample time
		IR_SampleCnt = 0;					//Clear the sample counter

		if (SampleTime > D_IR_SYNC_MAX)		B_IR_Sync = 0;	//large the Maxim SYNC time, then error
		else if (SampleTime >= D_IR_SYNC_MIN)					//SYNC
		{
			if (SampleTime >= D_IR_SYNC_DIVIDE)
			{
				B_IR_Sync = 1;					//has received SYNC
				IR_BitCnt = D_IR_BIT_NUMBER;	//Load bit number
			}
		}
		else if (B_IR_Sync)						//has received SYNC
		{
			if (SampleTime > D_IR_DATA_MAX)		B_IR_Sync = 0;	//data samlpe time to large
			else
			{
				IR_DataShit >>= 1;					//data shift right 1 bit
				if (SampleTime >= D_IR_DATA_DIVIDE)	IR_DataShit |= 0x80;	//devide data 0 or 1
				if (--IR_BitCnt == 0)				//bit number is over?
				{
					B_IR_Sync = 0;					//Clear SYNC
					if (~IR_DataShit == IR_data)		//判断数据正反码
					{
						if ((IR_UserH == (User_code / 256)) &&
							IR_UserL == (User_code % 256))
							B_IrUserErr = 0;	//User code is righe
						else	B_IrUserErr = 1;	//user code is wrong

						IR_code = IR_data;
						B_IR_Press = 1;			//数据有效
					}
				}
				else if ((IR_BitCnt & 7) == 0)		//one byte receive
				{
					IR_UserL = IR_UserH;			//Save the User code high byte
					IR_UserH = IR_data;				//Save the User code low byte
					IR_data = IR_DataShit;			//Save the IR data byte
				}
			}
		}
	}
}


/**************** Timer1初始化函数 ******************************/
void InitTimer1(void)
{
	TMOD = 0;		//for STC15Fxxx系列	Timer1 as 16bit reload timer.
	TH1 = Timer1_Reload / 256;
	TL1 = Timer1_Reload % 256;
	ET1 = 1;
	TR1 = 1;
	IP = 0x08;
	EA = 1;
}

/********************** Timer1中断函数************************/
void timer1(void) interrupt 3
{
	//	PWM_dr[0] = CL;
	//	PWM_dr[1] = CH;
	//	CL = 0;
	//	CH = 0; 
	//	PWM_OFF;
	IR_RX_HT6121();
	//	CH = PWM_dr[1];
	//	CL = PWM_dr[0];
	//	PWM_ON;
}
