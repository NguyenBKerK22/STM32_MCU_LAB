/*
 * lab1.h
 *
 *  Created on: Sep 8, 2024
 *      Author: ADMIN
 */

#ifndef INC_EXERCISE1_H_
#define INC_EXERCISE1_H_

#include "main.h"


#define LED_ON 	1
#define LED_OFF	0
#define LED_RED_GPIO_Port GPIOA
#define LED_YELLOW_GPIO_Port GPIOA
#define LED_RED_Pin GPIO_PIN_5
#define LED_YELLOW_Pin GPIO_PIN_6

void init_exercise1();
void exercise1_run();


#endif /* INC_EXERCISE1_H_ */
