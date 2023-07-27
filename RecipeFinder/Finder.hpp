#pragma once
#include "Recipe.hpp"

class Finder
{
public:
	Finder() = default;
	~Finder() = default;
public:
	void add_recipe(const Recipe&);
	std::vector<Recipe> get_recipes() const;
	std::vector<Recipe> search_recipes(const std::vector<std::string>&);
	Recipe* find_recipe_by_name(const std::string&);
	void save_recipes_to_file(const std::string&);
	void consol_app();
private:
	std::vector<Recipe> m_recipes;
};