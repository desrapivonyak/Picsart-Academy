#include "System.hpp"
#include <fstream>

void System::add_members(Member* member) {
	m_members.push_back(member);
}

void System::use_fitness(Member* member) {
	if (check_membership_duration(member) == false) {
		std::cout << "Your membership expired." << std::endl;
		return;
	}
	member->get_membership()->update_fitness();
}

void System::use_pool(Member* member) {
	if (check_membership_duration(member) == false) {
		std::cout << "Your membership expired." << std::endl;
		return;
	}
	member->get_membership()->update_pool();
}

void System::use_massage(Member* member) {
	if (check_membership_duration(member) == false) {
		std::cout << "Your membership expired." << std::endl;
		return;
	}
	member->get_membership()->update_massage();
}

bool System::check_membership_duration(Member* member) {
	if (member->get_membership()->get_duration() == 0) {
		return false;
	}
	return true;
}

void System::upgrade_level(Member* member) {
	if (member->get_membership()->get_level() == STANDARD) {
		member->get_membership()->set_level(PREMIUM);
	}
	else if(member->get_membership()->get_level() == PREMIUM) {
		member->get_membership()->set_level(ALL_INCLUDED);
	}
}

void System::downgrade_level(Member* member) {
	if (member->get_membership()->get_level() == ALL_INCLUDED) {
		member->get_membership()->set_level(PREMIUM);
	}
	else if (member->get_membership()->get_level() == PREMIUM) {
		member->get_membership()->set_level(STANDARD);
	}
}

void System::add_stats(const Member& member) {
	std::string stat = member.get_name();
	stat += " used:\n";
	if (member.get_membership()->get_level() == STANDARD) {
		stat += std::to_string(12 - member.get_membership()->get_fitness()) + " fitness entries";
		stat += "\n" + std::to_string(6 - member.get_membership()->get_pool()) + " pool entries";
		stat += "\n" + std::to_string(1 - member.get_membership()->get_massage()) + " massage entries";
	}
	else if (member.get_membership()->get_level() == PREMIUM) {
		stat += std::to_string(24 - member.get_membership()->get_fitness()) + " fitness entries";
		stat += "\n" + std::to_string(12 - member.get_membership()->get_pool()) + " pool entries";
		stat += "\n" + std::to_string(2 - member.get_membership()->get_massage()) + " massage entries";
	}
	else if (member.get_membership()->get_level() == ALL_INCLUDED) {
		stat += std::to_string(std::numeric_limits<int>::max() - member.get_membership()->get_fitness()) + " fitness entries";
		stat += "\n" + std::to_string(std::numeric_limits<int>::max() - member.get_membership()->get_pool()) + " pool entries";
		stat += "\n" + std::to_string(std::numeric_limits<int>::max() - member.get_membership()->get_massage()) + " massage entries";
	}
	m_stats.push_back(stat);
}

void System::generate_monthly_stats() {
	for (auto& stat : m_stats) {
		std::string filename;
		for (auto s : stat) {
			if (s == ' ') break;
			filename += s;
		}
		std::ofstream output(filename + ".txt");
		if (output.is_open()) {
			output << stat << std::endl;
			output.close();
		}
		std::cout << stat << std::endl;
	}
}