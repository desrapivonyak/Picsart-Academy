#include <iostream>
#include "Finder.hpp"

int main()
{
    Recipe recipe{ "Cook1", {"ingr1", "ing2", "ing3"}, "Cooking instruction" };
    Finder finder;
    finder.add_recipe(recipe);
    std::cout << finder.search_recipes({ "ingr1", "ingr2" })[0].get_name() << std::endl;
    finder.consol_app();
}