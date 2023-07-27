#pragma once
#include <string>
#include <vector>

class Recipe
{
public:
	Recipe(const std::string&, const std::vector<std::string>&, const std::string&);
	~Recipe() = default;
public:
	void set_name(const std::string&);
	std::string get_name() const;
	void set_instruction(const std::string&);
	std::string get_instuction() const;
	void set_ingredients(const std::string&);
	std::vector<std::string> get_ingredients() const;
private:
	std::string m_name;
	std::vector<std::string> m_ingredients;
	std::string m_instruction;
};

