/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: adc.h

  Author: 郭世全    Version: v0.10.0    Date: 2016.02.19 

  Description:      ADC相关函数的定义，常数初始化

  Others:         

  History:        

    1. Date: 2016.02.19
       Author: 郭世全
       Modification: Create File and Frame    
******************************************************************************/

#ifndef __adc_H
#define __adc_H

#include "..\ProgInc\config.h"

void ADC_Init(void);
unsigned int Get_ADC_Result(void);

#endif /*__adc_H */