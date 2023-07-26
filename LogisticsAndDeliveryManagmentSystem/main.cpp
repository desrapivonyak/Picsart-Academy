#include <iostream>
#include "Tracking.hpp"

int main()
{
    Date date{ 25, 7, 2023 };
    Deliveries item{ "Shoes", "London", "New York", date };
    Deliveries item1{ "Shirt", "Yerevan", "New York", {21, 12, 2023} };
    Tracking track;
    track.add_deliveries(&item);
    track.add_deliveries(&item1);
    track.generate_receipt();
}