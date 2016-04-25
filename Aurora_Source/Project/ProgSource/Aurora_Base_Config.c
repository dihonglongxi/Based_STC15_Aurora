/******************************************************************************
  Copyright (C), 2013-2016,  DiHongLongXi（帝鴻龍曦）
  
  File name: Aurora_Base_Config.c

  Author: DHLX    Version: v0.10.0    Date: 2016.04.26

  Description: 初始化芯片的各项外设、管脚配置    

  Others:         

  Function List:  
  
  Num. | function prototypes     | Description 
    1. | void System_Init(void)  | 系统配置初始化函数

  History:        
    
  Num. |    Date    |  Author  |  Modification
    1. | 2016.04.26 |   DHLX   |  创建文件和System_init()   
******************************************************************************/

/* Includes -----------------------------------------------------------------*/
#include "..\ProgInc\Aurora_Base_Config.H"

/* Private typedef ----------------------------------------------------------*/

/* Private define -----------------------------------------------------------*/

/* Private macro ------------------------------------------------------------*/

/* Private variables --------------------------------------------------------*/ 

/* Private constants --------------------------------------------------------*/

/* Private function prototypes ----------------------------------------------*/

/* Private functions --------------------------------------------------------*/

/******************************************************************************

  Function:       void System_Init(void)

  Description:    系统配置初始化函数

  Calls:          None

  Called By:      1、void main(void)

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-26

******************************************************************************/

/* Exported functions -------------------------------------------------------*/

void System_Init(void)
{
  /*初始化管脚配置，默认输出高电平，双向*/
  P0M0 = 0xFF;
  P0M1 = 0xFF;
  P0   = 0xFF;
  
  P0M0 = 0xFF;
  P0M1 = 0xFF;
  P0   = 0xFF;
  
  P0M0 = 0xFF;
  P0M1 = 0xFF;
  P0   = 0xFF;
  
  P0M0 = 0xFF;
  P0M1 = 0xFF;
  P0   = 0xFF;
  
  P0M0 = 0xFF;
  P0M1 = 0xFF;
  P0   = 0xFF;
  
  P0M0 = 0xFF;
  P0M1 = 0xFF;
  P0   = 0xFF;
  
  /*初始化Timer配置*/
  
  /*初始化AD配置，P10设置成AD端口*/
  
  /*初始化PWM配置，默认是P34、P35、P36、P37，SYSCLK/2，7位，100%高电平输出*/
}



/*********** (C) COPYRIGHT DiHongLongXi（帝鴻龍曦）*****END OF FILE************/
