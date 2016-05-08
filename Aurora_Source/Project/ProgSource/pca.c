/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: pca.c

  Author: ����ȫ    Version: v0.10.0    Date: 2016.02.19 

  Description:      PCA����ز�������

  Others:         

  Function List:  
    1.void PCA_Init(void)       PCAģ��ͨ�����ó�ʼ��
    2.void T38KHZ_Start(void)   38KHZ�����������
    3.void T38KHZ_Stop(void)    38KHZ����ֹͣ����
    4.void T32HZ_Start(void)    32HZ��ȫ���ŷ����������
    5.void T32HZ_Stop(void)     32HZ��ȫ���ŷ���ֹͣ����

  History:        

    1. Date: 2016.02.19
       Author: ����ȫ
       Modification: Create File and Frame   
******************************************************************************/

#include "..\ProgInc\pca.h"

/******************************************************************************

  Function:       void PCA_Init(void)

  Description:    ��ʼ��PCAģ���ͨ�����á�

  Calls:          1��void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-05

******************************************************************************/

void PCA_Init(void)
{
     /*��ʼ��CCON��PCA��ʱ��ֹͣ�����CF��־�����ģ���жϱ�־*/ 
     CCON = 0;

     /*��ʼ��PCA������*/ 
     CH = 0;
     CL = 0;

     /*PWM�ܽŶ��巽ʽ2��P3.4/ECI_2, P3.5/CCP0_2, P3.6/CCP1_2, P3.7/CCP2_2*/ 
     AUXR1 = (AUXR1 & ~(3<<4)) | (1<<4);           

     /*����PCAʱ��ԴΪSYSclk/8*/
     CMOD  = (CMOD  & ~(7<<1)) | (7<<1);   

     /*�ر�PCA�жˣ�ECF��*/
     CMOD  = CMOD  & ~1;  

     /*����PCA�ж�Ϊ�����ȼ�*/
     PPCA = 1;  

     /*Ĭ�����е�ģ�鶼�ر�*/
     CCAPM0 = 0x00;     
     CCAPM1 = 0x00;
     CCAPM2 = 0x00;
}

/******************************************************************************

  Function:       void T38KHZ_Start(void)

  Description:    �ṩ38KHZ 50% ����PWM����ֹͣ����򿪡�

  Calls:          1��void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-06

******************************************************************************/

void T38KHZ_Start(void)
{
     /*��ʼ��CCON��PCA��ʱ��ֹͣ�����CF��־�����ģ���жϱ�־*/ 
     CCON = 0;

     /*��ʼ��PCA������*/ 
     CH = 0;
     CL = 0;

     /*����ģ��0Ϊ�����������ģʽ�����������38KHZ����*/
     CCAPM0 = 0x4d;

     CCAP0L = PCA0_value;
     CCAP0H = PCA0_value >> 8;

     PCA0_value += T38KHz;

     /*PCAģ�鿪ʼ����*/
     CR = 1;
}

/******************************************************************************

  Function:       void T38KHZ_Stop(void)

  Description:    ֹͣ�ṩ38KHZ 50% ����PWM

  Calls:          1��void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-06

******************************************************************************/

void T38KHZ_Stop(void)
{
//     /*��ʼ��CCON��PCA��ʱ��ֹͣ�����CF��־�����ģ���жϱ�־*/ 
//     CCON = 0;

//     /*��ʼ��PCA������*/ 
//     CH = 0;
//     CL = 0;

     /*�ر�ģ��0*/
     CCAPM0 = 0x00;

     CCAP0L = 0x00;
     CCAP0H = 0x00;
    
     /*���ùܽ����Ϊ�׵�ƽ*/
     P3 &= 0xDF;
}

/******************************************************************************

  Function:       void T32HZ_Start(void)

  Description:    �ṩ32HZ 50% ��������ֹͣ����򿪡�

  Calls:          1��void main(void);

  Called By:      // ���ñ������ĺ����嵥

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-06

******************************************************************************/

void T32HZ_Start(void)
{
     /*��ʼ��CCON��PCA��ʱ��ֹͣ�����CF��־�����ģ���жϱ�־*/ 
     CCON = 0;

     /*��ʼ��PCA������*/ 
     CH = 0;
     CL = 0;

     /*����ģ��1Ϊ�����������ģʽ�����������32HZ����*/
     CCAPM1 = 0x4d;

     CCAP1L = PCA1_value;
     CCAP1H = PCA1_value >> 8;

     PCA1_value += T32HZ;

     /*PCAģ�鿪ʼ����*/
     CR = 1;
}

/******************************************************************************

  Function:       void T32HZ_Stop(void)

  Description:    ֹͣ�ṩ32HZ 50% ����PWM

  Calls:          1��void main(void);

  Called By:      None

  Input:          None

  Output:         None

  Return:         None

  Others:         None

  Version:        V0.10.0,2016-02-06

******************************************************************************/

void T32HZ_Stop(void)
{
     /*��ʼ��CCON��PCA��ʱ��ֹͣ�����CF��־�����ģ���жϱ�־*/ 
     CCON = 0;

     /*��ʼ��PCA������*/ 
     CH = 0;
     CL = 0;

     /*�ر�ģ��0*/
     CCAPM1 = 0x00;

     CCAP1L = 0x00;
     CCAP1H = 0x00;
    
    /*���ùܽ����Ϊ�׵�ƽ*/
     P3 &= 0xBF;
}
