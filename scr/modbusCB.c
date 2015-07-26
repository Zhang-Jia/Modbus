/**
  ******************************************************************************
  * @�ļ�
  * @����
  * @�汾
  * @����
  * @��Ҫ
  ******************************************************************************
  * @ע������
  *
  *
  *
  ******************************************************************************
  */

/* ͷ�ļ�       --------------------------------------------------------------*/
#include "mb.h"
#include "stdio.h"
/* ˽���������� --------------------------------------------------------------*/
/* ˽�ж���     --------------------------------------------------------------*/
/* ˽�к궨��   --------------------------------------------------------------*/
/* ˽�б���     --------------------------------------------------------------*/
/* ˽�к������� --------------------------------------------------------------*/

/**
  * @����
  * @����
  * @����ֵ
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
    /* ���� */
    static uint8_t flag = 0;

    flag == 0 ? GPIO_SetBits(GPIOC,GPIO_Pin_2) : GPIO_ResetBits(GPIOC,GPIO_Pin_2);
    flag ^= 1;
    /* �����Լ����� */
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


/*******************�ļ���β**************************************************/
