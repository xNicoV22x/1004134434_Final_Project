/*
 * gui.h
 *
 *  Created on: Nov 20, 2023
 *      Author: saaci
 */

#ifndef INC_GUI_H_
#define INC_GUI_H_

#include <stdint.h>

void GUI_Wait(void);
void GUI_init(void);
void GUI_locked(void);
void GUI_unlocked(void);
void GUI_update_password_init(void);
void GUI_update_password(uint8_t *password);
void GUI_update_password_success(void);
void GUI_blocked_access_system(void);
void GUI_open_access_system(void);
void GUI_error_access_system(void);
void GUI_empty(void);

#endif /* INC_GUI_H_ */
