#include "Recipe.hpp"

Recipe::Recipe(const std::string& name, const std::vector<std::string>& ingredients, const std::string& instruction)
	: m_name{ name }
	, m_ingredients{ ingredients }
	, m_instruction{ instruction }
{
}

void Recipe::set_name(const std::string& name) {
	m_name = name;
}

std::string Recipe::get_name() const {
	return m_name;
}

void Recipe::set_ingredients(const std::string& ingredient) {
	m_ingredients.push_back(ingredient);
}

std::vector<std::string> Recipe::get_ingredients() const {
	return m_ingredients;
}

void Recipe::set_instruction(const std::string& instruction) {
	m_instruction = instruction;
}

std::string Recipe::get_instuction() const {
	return m_instruction;
}