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
******************************************************************************/
#ifndef __usart_H
#define __usart_H 

#include "..\ProgInc\config.h"

void Uart1_Init(void);
    
#endif /*__usart_H */
