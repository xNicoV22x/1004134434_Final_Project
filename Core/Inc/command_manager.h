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

#endif /* INC_COMMAND_MANAGER_H_ */
