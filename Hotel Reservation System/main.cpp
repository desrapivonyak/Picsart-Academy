#include <iostream>
#include "BookingSystem.h"

int main()
{
    Customer customer{ "John", "john@gmail.com" };
    Customer customer1{ "Ivan", "ivan@gmail.com" };
    Customer customer2{ "Anna", "anna@gmail.com" };

    Room single { 120520, Type::SINGLE, 10000 };
    Room double_{ 120521, Type::DOUBLE, 15000 };
    Room suit{ 1205222, Type::SUIT, 25000 };

    BookingSystem booking(&single);

    booking.add_room(&double_);
    booking.add_room(&suit);

    booking.book_single(&customer, 10);
    booking.bill_to_console();

    booking.book_double(&customer1, 12);
    booking.bill_to_console();

    booking.book_suit(&customer2, 7);
    booking.bill_to_console();
}