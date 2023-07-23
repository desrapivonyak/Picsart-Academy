#include <iostream>
#include "AirlineReservationSystem.hpp"

int main()
{
    Date date{ 12, 8, 2023 };
    Flight fl{ 125, 10, "Yerevan", "London", date };
    User us{ "Aram", "aram@gmail.com" };
    
    AirlineReservationSystem res;
    res.add_flight(&fl);
    res.book_flight(us, &fl);
    std::cout << fl.get_available_seats() << std::endl;
}