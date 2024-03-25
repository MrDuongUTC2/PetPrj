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

void MainTask();
void jumpToApp(const uint32_t address);
void Deinit();

#endif /* INC_APP_H_ */
