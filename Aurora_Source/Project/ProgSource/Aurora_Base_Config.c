/******************************************************************************
  Copyright (C), 2013-2016,  DiHongLongXi���������أ�
  
  File name: Aurora_Base_Config.c

  Author: DHLX    Version: v0.10.0    Date: 2016.04.26

  Description: ��ʼ��оƬ�ĸ������衢�ܽ�����    

  Others:         

  Function List:  
  
  Num. | function prototypes     | Description 
    1. | void System_Init(void)  | ϵͳ���ó�ʼ������

  History:        
    
  Num. |    Date    |  Author  |  Modification
    1. | 2016.04.26 |   DHLX   |  �����ļ���System_init()   
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

  Description:    ϵͳ���ó�ʼ������

  Calls:          None

  Called By:      1��void main(void)

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-26

******************************************************************************/

/* Exported functions -------------------------------------------------------*/

void System_Init(void)
{
  /*��ʼ���ܽ����ã�Ĭ������ߵ�ƽ��˫��*/
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
  
  /*��ʼ��Timer����*/
  
  /*��ʼ��AD���ã�P10���ó�AD�˿�*/
  
  /*��ʼ��PWM���ã�Ĭ����P34��P35��P36��P37��SYSCLK/2��7λ��100%�ߵ�ƽ���*/
}



/*********** (C) COPYRIGHT DiHongLongXi���������أ�*****END OF FILE************/
