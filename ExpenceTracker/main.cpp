#include <iostream>
#include "Tracker.hpp"

int main()
{
    Expense expense{ 15000, "Bills", "Home bills", {20, 8, 2023} };
    Expense expense1{ 7000, "Insurance", "Home bills", {15, 7, 2023} };
    Expense expense2{ 18000, "Bills", "Home bills", {20, 7, 2023} };
    Expense expense3{ 5700, "Insurance", "Home bills", {20, 5, 2023} };
    Tracker track;

    track.add_expense(expense);
    track.add_expense(expense1);
    track.add_expense(expense2);
    track.add_expense(expense3);

    track.save_report_to_file();
}