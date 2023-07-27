#include "Finder.hpp"
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iostream>

void Finder::add_recipe(const Recipe& recipe) {
	m_recipes.push_back(recipe);
}

std::vector<Recipe> Finder::get_recipes() const {
	return m_recipes;
}

std::vector<Recipe> Finder::search_recipes(const std::vector<std::string>& ingredients) {
    std::vector<Recipe> matching_recipes;
    for (const auto& recipe : m_recipes) {
        const std::vector<std::string>& recipeIngredients = recipe.get_ingredients();

        bool allIngredientsFound = true;
        for (const std::string& ingredient : ingredients) {
            if (std::find(recipeIngredients.begin(), recipeIngredients.end() - 1, ingredient) == recipeIngredients.end()) {
                allIngredientsFound = false;
                break;
            }
        }

        if (allIngredientsFound) {
            matching_recipes.push_back(recipe);
        }
    }
    return matching_recipes;
}

Recipe* Finder::find_recipe_by_name(const std::string& recipeName) {
    Recipe* p = nullptr;
    for (auto& recipe : m_recipes) {
        if (recipe.get_name() == recipeName) {
            p = &recipe;
        }
    }
    return p;
}

void Finder::save_recipes_to_file(const std::string& filename) {
    std::ofstream output(filename + ".txt", std::ios::app);
    if (output.is_open()) {
        for (auto& recipe : get_recipes()) {
            output << "Name : " << recipe.get_name();
            output << "\nIngredients : ";
            for (auto& ingredient : recipe.get_ingredients())
            {
                output << ingredient << " ";
            }
            output << "\nInstructions : " << recipe.get_instuction() << std::endl;
        }
        output.close();
    }
    else {
        std::cout << "Error: Unable to save recipes to file.\n";
    }
}

void Finder::consol_app() {
    while (true) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. View Recipe Details\n";
        std::cout << "2. Add New Recipe\n";
        std::cout << "3. Save and Exit\n";
        std::cout << "Enter your choice (1/2/3): ";

        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::cout << "Enter the recipe name: ";
            std::string recipeName;
            std::cin >> recipeName;
            Recipe* recipe = find_recipe_by_name(recipeName);
            if(recipe != nullptr){
                std::cout << recipe->get_instuction() << " ";
                std::cout << recipe->get_name();
            }
            else {
                std::cout << "Recipe not found.\n" << std::endl;
            }
        }
        else if (choice == 2) {
            std::cin.ignore();
            std::cout << "Enter the recipe name: ";
            std::string name;
            std::getline(std::cin, name);
            std::cout << "How many ingredients do you want to add? ";
            int count;
            std::cin >> count;
            std::vector<std::string> ingredients;
            while (count != 0) {
                std::cout << "Enter the ingredient: ";
                std::string input;
                std::cin >> input;
                ingredients.push_back(input);
                count--;
            }
            std::cout << "Enter the cooking instructions: ";
            std::string instructions;
            std::cin.ignore();
            std::getline(std::cin, instructions);
            Recipe newRecipe (name, ingredients, instructions);
            this->add_recipe(newRecipe);
            std::cout << "Recipe added successfully!\n";
        }
        else if (choice == 3) {
            save_recipes_to_file("recipes");
            std::cout << "Recipes saved to file. Exiting...\n";
            break;
        }
        else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}