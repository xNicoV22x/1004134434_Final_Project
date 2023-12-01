/*
 * command_manager.h
 *
 *  Created on: Nov 30, 2023
 *      Author: Nicolas
 */

#ifndef INC_COMMAND_MANAGER_H_
#define INC_COMMAND_MANAGER_H_

#include <stdint.h>
#include "ring_buffer.h"

void command_manager_init(void);
void lock_command_handler(uint8_t *key);

//static inline uint8_t keypad_run(volatile uint16_t *keypad_event) {
//	uint8_t key_pressed = KEY_PRESSED_NONE;
//	if (*keypad_event != KEYPAD_EVENT_NONE){
//		key_pressed = keypad_handler(*keypad_event);
//		*keypad_event = KEYPAD_EVENT_NONE;
//	}
//	return key_pressed;
//}

#endif /* INC_COMMAND_MANAGER_H_ */
