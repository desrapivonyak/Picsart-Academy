#pragma once
#include "Job.hpp"
#include "User.hpp"
#include <fstream>
#include <iostream>

class Portal
{
public:
	Portal() = default;
	~Portal() = default;
public:
	void add_jobs(Job*);
	std::vector<Job*> get_jobs() const;
	void add_user(User*);
	std::vector<User*> get_users() const;
	void job_fill(const User&);
	void search_by_title(const std::string&);
	void search_by_company(const std::string&);
	void search_by_salary(const int);
private:
	std::vector<Job*> m_jobs;
	std::vector<User*> m_users;
};