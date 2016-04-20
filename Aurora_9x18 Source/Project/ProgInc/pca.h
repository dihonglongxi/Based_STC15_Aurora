/******************************************************************************
  Copyright (C), 2015-2016,  Bpeer Robotics. Co., Ltd.
  
  File name: pca.h

  Author: 郭世全    Version: v0.10.0    Date: 2016.02.19

  Description:      PCA的相关函数的定义，常数宏定义等

  Others:         

  Function List:  

  History:        

    1. Date: 2016.02.19
       Author: 郭世全
       Modification: Create File and Frame    
******************************************************************************/

#ifndef __pca_H
#define __pca_H

#include "..\ProgInc\config.h"

void PCA_Init(void);
void T38KHZ_Start(void);
void T38KHZ_Stop(void);
void T32HZ_Start(void);
void T32HZ_Stop(void);

/*PCA所需变量定义与初始化*/
extern unsigned int PCA0_value;
extern unsigned int PCA1_value;
    
#endif /*__pca_H */
