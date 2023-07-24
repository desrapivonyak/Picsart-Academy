#include <iostream>
#include "System.hpp"

int main()
{
    Customer customer{ "Lucy", "contact" };
    Date date{ 15, 8, 2023 };
    Movie movie{ "Oppenheimer", 180, 5, {date, 120} };
    System system;
    system.add_movie(&movie);
    system.booking(&movie, 15);
    system.booking(&movie, 110);
    system.search_movie("Game of thrones");
}
