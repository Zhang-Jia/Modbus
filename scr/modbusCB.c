/**
  ******************************************************************************
  * @文件
  * @作者
  * @版本
  * @日期
  * @概要
  ******************************************************************************
  * @注意事项
  *
  *
  *
  ******************************************************************************
  */

/* 头文件       --------------------------------------------------------------*/
#include "mb.h"
#include "stdio.h"
/* 私有数据类型 --------------------------------------------------------------*/
/* 私有定义     --------------------------------------------------------------*/
/* 私有宏定义   --------------------------------------------------------------*/
/* 私有变量     --------------------------------------------------------------*/
/* 私有函数声明 --------------------------------------------------------------*/

/**
  * @功能
  * @参数
  * @返回值
  */
eMBErrorCode
eMBRegInputCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    static uint8_t flag = 0;

    flag == 0 ? GPIO_SetBits(GPIOC,GPIO_Pin_1) : GPIO_ResetBits(GPIOC,GPIO_Pin_1);
    flag ^= 1;
    return eStatus;
}

eMBErrorCode
eMBRegHoldingCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNRegs, eMBRegisterMode eMode )
{
    eMBErrorCode    eStatus = MB_ENOERR;
    /* 闪灯 */
    static uint8_t flag = 0;

    flag == 0 ? GPIO_SetBits(GPIOC,GPIO_Pin_2) : GPIO_ResetBits(GPIOC,GPIO_Pin_2);
    flag ^= 1;
    /* 加入自己代码 */
    *pucRegBuffer = ( UCHAR ) ( usNRegs * 3 );
    return eStatus;
}

eMBErrorCode
eMBRegCoilsCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNCoils, eMBRegisterMode eMode )
{
    static uint8_t flag = 0;

    flag == 0 ? GPIO_SetBits(GPIOC,GPIO_Pin_3) : GPIO_ResetBits(GPIOC,GPIO_Pin_3);
    flag ^= 1;
    return MB_ENOREG;
}

eMBErrorCode
eMBRegDiscreteCB( UCHAR * pucRegBuffer, USHORT usAddress, USHORT usNDiscrete )
{
    static uint8_t flag = 0;

    flag == 0 ? GPIO_SetBits(GPIOC,GPIO_Pin_4) : GPIO_ResetBits(GPIOC,GPIO_Pin_4);
    flag ^= 1;
    return MB_ENOREG;
}

/**
  * @}
  */


/*******************文件结尾**************************************************/
