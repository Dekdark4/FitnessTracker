#include "ConsoleMenu.h"

// ставим курсор в нужное место
void ConsoleMenu::go_to_x_y(int32_t x, int32_t y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
