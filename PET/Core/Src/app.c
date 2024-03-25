/*
 * app.c
 *
 *  Created on: Mar 21, 2024
 *      Author: cc
 */

#include "app.h"
#include <stdio.h>

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
#else
#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
#endif /* __GNUC__ */


PUTCHAR_PROTOTYPE
{
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}


void MainTask()
{
	printf("  We are in boot \r \n");
	HAL_Delay(500);

	Deinit();
	jumpToApp(APP2_START);

}

void jumpToApp(const uint32_t address)
{
    uint32_t stack_addr = *((uint32_t *)address);
    void (*func_p)(void) = *((void (**)(void))(address + sizeof(uint32_t)));

    /* Jump, used asm to avoid stack optimization */
    asm("msr msp, %0; bx %1;" : : "r"(stack_addr), "r"(func_p));
}

void Deinit()
{
	HAL_UART_DeInit(&huart2);
	  __HAL_RCC_GPIOC_CLK_DISABLE();
	  __HAL_RCC_GPIOA_CLK_DISABLE();
	HAL_DeInit();
}
