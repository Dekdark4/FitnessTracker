#pragma once
//#include <iostream>
#include <string>
#include <vector>

struct MenuItem
{
	std::string name = "Unknown";
	int16_t id = 0;
};

class Menu
{
private:
	std::vector<MenuItem> items;
public:
	Menu() = default;

	Menu(const Menu&) = delete;
	Menu& operator=(const Menu&) = delete;
	
	void add_item(const std::string& name, const int16_t id);

	size_t size() const;
};