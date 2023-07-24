#include <iostream>
#include "Portal.hpp"

int main()
{
    User user{ "Anna", "contact@email.com", "Accountant", 350000 };
    Job job{ "Accountant", "Job description", "Job requirments", "Somewhere", 350000 };
    User user1{ "Sonya", "contact@email.com", "Developer", 400000 };
    Job job1{ "Developer", "Job description", "Job requirments", "Somewhere", 400000 };
    Portal portal;
    portal.add_user(&user);
    portal.add_user(&user1);
    portal.add_jobs(&job);
    portal.add_jobs(&job1);
    for (auto job : portal.get_jobs()) {
        std::cout << job->get_title() << std::endl;
    }
    std::cout << "After job filling." << std::endl;
    portal.job_fill(user1);
    for (auto job : portal.get_jobs()) {
        std::cout << job->get_title() << std::endl;
    }
}
