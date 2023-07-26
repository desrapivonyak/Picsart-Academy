#pragma once
#include "ClubMembership.hpp"
#include "Member.hpp"
#include <iostream>
#include <vector>
#include <fstream>

class System
{
public:
	System() = default;
	~System() = default;
public:
	void add_members(Member*);
	void use_fitness(Member*);
	void use_pool(Member*);
	void use_massage(Member*);
	bool check_membership_duration(Member*);
	void upgrade_level(Member*);
	void downgrade_level(Member*);
	void add_stats(const Member&);
	void generate_monthly_stats();
private:
	std::vector<Member*> m_members;
	std::vector<std::string> m_stats;
};