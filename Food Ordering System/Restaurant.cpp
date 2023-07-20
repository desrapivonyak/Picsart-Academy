#include "Restaurant.h"
#include <iostream>

Restaurant::Restaurant(const std::string& name, const std::string& location, const std::map<std::string, int>& menu) {
	m_name = name;
	m_location = location;
	m_menu = menu; 
}

void Restaurant::set_name(const std::string& name) {
	m_name = name;
}

void Restaurant::set_location(const std::string& location) {
	m_location = location;
}

void Restaurant::add_food(const std::string& food, int price) {
	if (m_menu.find(food) == m_menu.end()) {
		m_menu[food] = price;
	}
	else {
		std::cout << "This food already exists in menu.";
	}
}

std::string Restaurant::get_name() const {
	return m_name;
}

std::string Restaurant::get_location() const {
	return m_location;
}

std::map<std::string, int> Restaurant::get_menu() const {
	return m_menu;
}

int Restaurant::get_food_price(const std::string& food) const {
	auto pos = m_menu.find(food);
	return pos->second;
}

void Restaurant::register_restaurant() {
	std::cout << "Restaurant registeration started.\nEnter restaurant name:\n";
	std::string name;
	std::cin >> name;
	set_name(name);
	std::cout << "Enter location:\n";
	std::string location;
	std::cin >> location;
	set_location(location);
	std::cout << "How many dishes do you want to add right now?\n";
	int count;
	std::cin >> count;
	std::string food_name;
	int food_price;
	while (count) {
		std::cout << "Food name:\n";
		std::cin >> food_name;
		std::cout << "Food price:\n";
		std::cin >> food_price;
		add_food(food_name, food_price);
		--count;
	}
	std::cout << "Registeration finished!\n";
}

std::string Restaurant::get_info() const {
	std::string info;
	info = "Restaurant name: " + get_name();
	info += "\nRestaurant location: " + get_location();
	info += "\nRestaurant main menu:";
	for (auto& food : m_menu) {
		info += "\n - ";
		info += food.first;
		info += " : " + std::to_string(food.second);
	}
	return info;
}