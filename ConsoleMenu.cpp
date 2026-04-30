#include "ConsoleMenu.h"

// ставим курсор в нужное место
void ConsoleMenu::go_to_x_y(int32_t x, int32_t y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void ConsoleMenu::draw()
{
	system("cls");

	std::cout << "\t=== Your tracker ===\n\n";

	for (size_t i = 0; i < items.size(); ++i)
	{
		if (i == selected) {
			// Подсветка выбранного пункта: белый текст на синем фоне
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x70); // Код цвета
			std::cout << "  > " << items[i].text << " \n";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07); // Сбрасываем на стандартный
		}
		else {
			std::cout << "    " << items[i].text << " \n";
		}
	}
}

void ConsoleMenu::add_item(const std::string& text, int16_t id)
{
	items.push_back({ text, id });
}

int16_t ConsoleMenu::show()
{
    // Прячем стандартный ввод
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD mode;
    GetConsoleMode(hStdin, &mode);
    SetConsoleMode(hStdin, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT));

    while (true) {
        draw(); // Рисуем

        int key = _getch(); // Ждём клавишу

        // Если это стрелка (они состоят из двух кодов: -32 и сама стрелка)
        if (key == 224) {
            key = _getch(); // Читаем второй код
            if (key == 72) { // Вверх
                selected = static_cast<int16_t>((selected - 1 + items.size()) % items.size());
            }
            else if (key == 80) { // Вниз
                selected = static_cast<int16_t>((selected + 1) % items.size());
            }
        }
        // Если Enter
        else if (key == 13) {
            SetConsoleMode(hStdin, mode); // Возвращаем консоль как было
            return items[selected].id;
        }
        // Если 'q'
        else if (key == 'q' || key == 'Q') {
            SetConsoleMode(hStdin, mode);
            return -1; // Сигнал "выход"
        }
    }
}
