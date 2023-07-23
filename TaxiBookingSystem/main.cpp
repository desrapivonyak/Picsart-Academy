#include <iostream>
#include "System.hpp"

int main()
{
    User user{ "John", "example@gmail.com" };
    Taxi taxi{ "1250A", "Daniel", COMFORT };
    User user1{ "Jonatan", "example@gmail.com" };
    Taxi taxi1{ "1250B", "David", START };
    User user2{ "Anna", "anna@gmail.com" };
    System system;
    system.add_taxi(&taxi);
    system.add_taxi(&taxi1);
    system.book_taxi(user, 15);
    system.book_taxi(user1, 10);
    system.book_taxi(user2, 3);
}
