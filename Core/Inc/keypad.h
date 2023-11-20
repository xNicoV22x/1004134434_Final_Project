
#ifndef __KEYPAD_
#define __KEYPAD_

#include <stdint.h>


#define KEYPAD_EVENT_NONE 0xFF
#define KEY_PRESSED_NONE 0xFF


void keypad_init(void);
uint8_t keypad_handler(uint16_t column_to_evaluate);

#endif /* __KEYPAD_ */
