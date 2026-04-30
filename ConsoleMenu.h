#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include <Windows.h>

struct MenuItem
{
	std::string text;
	int16_t id;
};

class ConsoleMenu
{
private:
	// члены класса
	std::vector<MenuItem> items;
	int16_t selected;
	// ставим курсор в нужное место
	void go_to_x_y(int32_t x, int32_t y);
	// рисуем меню целиком
	// добавляем пункты в меню
	// показываем меню и возвращаем id выбранного пункта
};