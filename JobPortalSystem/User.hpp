#pragma once
#include <string>
#include <vector>

class User
{
public:
	User(const std::string&, const std::string&, const std::string&, const int);
	~User() = default;
public:
	void set_name(const std::string&);
	void set_contact(const std::string&);
	void set_resume(const std::string&);
	void set_salary(const int);
	void add_notification(const std::string&);
	int get_salaray() const;
	std::string get_name() const;
	std::string get_contact() const;
	std::string get_resume() const;
	std::vector<std::string> get_notifications() const;
private:
	int m_salary_exceptions;
	std::string m_name;
	std::string m_contact;
	std::string m_resume;
	std::vector<std::string> m_notifications;
};