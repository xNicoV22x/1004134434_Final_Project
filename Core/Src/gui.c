#include "gui.h"

#include "ssd1306.h"
#include "ssd1306_fonts.h"


extern const uint8_t locked[];


void GUI_init(void)
{
	ssd1306_Init();
	ssd1306_Fill(Black);
	ssd1306_SetCursor(20, 5);
	ssd1306_WriteString("Locked", Font_16x26, White);
	ssd1306_DrawBitmap(50, 35, locked, 30, 30, White);
	ssd1306_UpdateScreen();
}

