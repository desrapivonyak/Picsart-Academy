#include <iostream>
#include "System.hpp"

int main()
{
    Customer customer{ "Lucy", "contact" };
    Travel travel{ "London", 1800, 5 };
    System system;
    system.add_travel(&travel);
    system.booking(&travel, 3);
    system.booking(&travel, 10);
    system.search_by_price(1500, 5);
}
