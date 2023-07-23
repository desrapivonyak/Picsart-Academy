#include <iostream>
#include "ReservationSystem.hpp"

int main()
{
    Customer customer{ "Daniel", "dany@gmail.com" };
    Table table{ 122, 3 };
    ReservationSystem system;
    Date date{ 15, 8, 2023 };

    system.add_table(&table);
    std::cout << system.search_by_capacity(15) << std::endl;
    system.reserve_table(customer, date, &table);
}