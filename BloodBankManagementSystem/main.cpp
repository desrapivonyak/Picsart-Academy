#include <iostream>
#include "BloodBank.hpp"

int main()
{
    Date date{ 25, 7, 2023 };
    Date date1{ 25, 7, 2018 };
    Blood blood{ 5000, "red blood" };
    Blood blood1{ 6000, "red blood" };
    Donor donor{ "Anna", "contact@email", blood };
    Donor donor1{ "Dave", "contact@email", blood1 };
    BloodBank bank;
    bank.donation(&donor, date);
    bank.donation(&donor1, date1);
    bank.utilization(2023);
    bank.search_blood("red blood");
    bank.generate_report();
}