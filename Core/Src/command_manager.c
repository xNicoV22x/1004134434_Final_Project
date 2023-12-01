/*
 * command_manager.c
 *
 *  Created on: Nov 30, 2023
 *      Author: Nicolas
 */

#include "command_manager.h"
#include "ring_buffer.h"
#include "main.h"
#include "gui.h"

#include <stdio.h>
#include <string.h>


#define MAX_PASSWORD 5


//uint8_t password[MAX_PASSWORD] = "1992";
uint8_t block[MAX_PASSWORD] = "block";
uint8_t open[MAX_PASSWORD] = "start";
//
//uint8_t keypad_buffer[MAX_PASSWORD];
//ring_buffer_t keypad_rb;

//uint8_t failed_counter = 0;

//uint8_t rx_data;
uint8_t rx_buffer[MAX_PASSWORD];
ring_buffer_t command_rb;

extern volatile uint8_t received[6];

static void turn_on_light(void)
{
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);
}

static void turn_off_light(void)
{
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);
}

static void error_command(void)
{
	GUI_error_access_system();
	HAL_Delay(1000);
	GUI_empty();
	HAL_Delay(1000);
	GUI_error_access_system();
	HAL_Delay(1000);
	GUI_empty();
	HAL_Delay(1000);
}
static void open_system(void)
{
	GUI_open_access_system();
	HAL_Delay(3*1000);
	turn_on_light();
}

static void blocked_system(void)
{
	GUI_blocked_access_system();
	HAL_Delay(3*1000);
	turn_off_light();
}

void command_manager_init(void)
{
	GUI_init();
}

void lock_command_handler(uint8_t *key)
{
	if (memcmp(block, key, 5) == 0){
		blocked_system();
	}
	else if (memcmp(open, key, 5) == 0){
		open_system();
		GUI_locked();
	}
	 else {
		 error_command();
	}
}


//	for (uint8_t idx = 0; idx < 7; idx++) {
//		ring_buffer_get(&rx_rb, &received_id[idx]);
//	}
//	if (memcmp(expected_id, received_id, 7) == 0) {
//		/* 3.1 -> Show "Success" if the string is correct */
//		print_string("Success");
//		failed_counter = 0; // reset the failure counter if success
//		HAL_Delay(3*1000);
//	} else {
//		failed_counter++;
//		if (failed_counter < 3) {
//			/* 3.2 -> Show "Failed" if the string is incorrect */
//			print_string("Failed ");
//			HAL_Delay(3*1000);
//		} else {
//			/* 4 -> Show "Blocked" if the string is incorrect 3 times */
//			print_string("Blocked");
//			failed_counter = 0;
//			HAL_Delay(10*1000);
//		}
//	}
//}
