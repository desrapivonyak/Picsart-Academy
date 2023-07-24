#include <iostream>
#include "LotManagement.hpp"

int main()
{
    User user{ "David", SIZE::COMPACT };
    Parking parking{ 12545, SIZE::COMPACT };
    User user1{ "Anna", SIZE::REGULAR };
    Parking parking1{ 12545, SIZE::REGULAR };
    User user2{ "Dan", SIZE::COMPACT };
    Parking parking2{ 12545, SIZE::REGULAR };

    LotManagement lot;
    lot.add_spaces(&parking);
    lot.reserve_space(user, 15);
    lot.generate_reciept();
    lot.add_spaces(&parking1);
    lot.reserve_space(user1, 20);
    lot.generate_reciept();
    lot.add_spaces(&parking2);
    lot.reserve_space(user2, 15);
}