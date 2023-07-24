#pragma once
#include <string>

class Job
{
public:
	Job(const std::string&, const std::string&, const std::string&, const std::string&, const int);
	~Job() = default;
public:
	void set_title(const std::string&);
	void set_description(const std::string&);
	void set_requirments(const std::string&);
	void set_company(const std::string&);
	void set_status(const bool);
	void set_salary(const int);
	bool get_status() const;
	int get_salary() const;
	std::string get_title() const;
	std::string get_description() const;
	std::string get_requirments() const;
	std::string get_company() const;
private:
	bool m_status;
	int m_salary;
	std::string m_title;
	std::string m_description;
	std::string m_requirments;
	std::string	m_company;
};

