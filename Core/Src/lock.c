#include "lock.h"
#include "ring_buffer.h"
#include "gui.h"

#include <stdio.h>
#include <string.h>


#define MAX_PASSWORD 12


uint8_t password[MAX_PASSWORD] = "1992";

uint8_t keypad_buffer[MAX_PASSWORD];
ring_buffer_t keypad_rb;


static uint8_t lock_validate_password(void)
{
	uint8_t sequence[MAX_PASSWORD];
	uint8_t seq_len = ring_buffer_size(&keypad_rb);
	for (uint8_t idx = 0; idx < seq_len; idx++) {
		ring_buffer_get(&keypad_rb, &sequence[idx]);
	}
	if (memcmp(sequence, password, 4) == 0) {
		return 1;
	}
	return 0;
}

static void lock_update_password(void)
{
	if (lock_validate_password() != 0) {
		printf("Enter new Password:\r\n");
	} else {
		printf("Password Failed\r\n");
	}
}

static void lock_open_lock(void)
{
	if (lock_validate_password() != 0) {
		printf("Unlocked!\r\n");
	} else {
		printf("Password Failed\r\n");
	}
}

void lock_init(void)
{
	ring_buffer_init(&keypad_rb, keypad_buffer, 12);
	GUI_init();
}

void lock_sequence_handler(uint8_t key)
{
	if (key == '*') {
		lock_update_password();
	} else if (key == '#') {
		lock_open_lock();
	} else {
		ring_buffer_put(&keypad_rb, key);
	}

}
