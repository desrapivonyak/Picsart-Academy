#pragma once
#include <string>
#include <map>
#include <iostream>

class Restaurant
{
public:
	Restaurant(const std::string&, const std::string&, const std::map<std::string, int>&);
	~Restaurant() = default;
public:
	void set_name(const std::string&);
	void set_location(const std::string&);
	void add_food(const std::string&, int);
	std::string get_name() const;
	std::string get_location() const;
	std::map<std::string, int> get_menu() const;
	int get_food_price(const std::string&) const;
	void register_restaurant();
	std::string get_info() const;
private:
	std::string m_name;
	std::string m_location;
	std::map<std::string, int> m_menu;
};

