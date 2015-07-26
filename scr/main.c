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
#include <stdio.h>
#include "stm32f10x.h"
#include "mb.h"

/* 私有数据类型 --------------------------------------------------------------*/
/* 私有定义     --------------------------------------------------------------*/
/* 私有宏定义   --------------------------------------------------------------*/
#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */
/* 私有变量     --------------------------------------------------------------*/
/* 私有函数声明 --------------------------------------------------------------*/
void LED_Config(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);

    GPIO_InitStructure.GPIO_Pin     = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;
    GPIO_InitStructure.GPIO_Mode    = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed   = GPIO_Speed_50MHz;

    GPIO_Init(GPIOC,&GPIO_InitStructure);
}


/**
  * @brief  Configure the nested vectored interrupt controller.
  * @param  None
  * @retval : None
  */
void NVIC_Configuration(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;

  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);

  /* Enable the TIM2 gloabal Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 2;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;

  NVIC_Init(&NVIC_InitStructure);
}

/**
  * @功能
  * @参数
  * @返回值
  */
int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    NVIC_Configuration();
    LED_Config();

    /*       模式 从机地址 端口 波特率 校验位*/
    eMBInit( MB_RTU, 0x02, 0, 9600, MB_PAR_NONE );

    /* Enable the Modbus Protocol Stack. */
    eMBEnable(  );

    for( ;; )
    {
     ( void )eMBPoll(  );
     /* Here we simply count the number of poll cycles. */
//     usRegInputBuf[0]++;
    }
}

/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */

  /* Loop until the end of transmission */
  while (USART_GetFlagStatus(USART1, USART_FLAG_TC) == RESET)
  {}
  /* e.g. write a character to the USART */
  USART_SendData(USART1, (uint8_t) ch);

  return ch;
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif
/**
  * @}
  */


/*******************************文件结尾**************************************/
