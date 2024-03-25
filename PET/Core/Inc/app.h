/*
 * app.h
 *
 *  Created on: Mar 21, 2024
 *      Author: cc
 */

#ifndef INC_APP_H_
#define INC_APP_H_

#include "main.h"

#define APP2_START (0x804B000)

typedef void (application_t)(void);

typedef struct
{
    uint32_t		stack_addr;     // Stack Pointer
    application_t*	func_p;        // Program Counter
} JumpStruct;

void MainTask();
void jumpToApp(const uint32_t address);
void Deinit();

#endif /* INC_APP_H_ */
