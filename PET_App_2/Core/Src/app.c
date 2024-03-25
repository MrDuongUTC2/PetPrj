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
	printf("We are in App 2 \r\n");
	HAL_Delay(500);
}
