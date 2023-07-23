#pragma once
#include <string>

class User{
public:
	User(const std::string&, const std::string&);
	~User() = default;
public:
	void set_name(const std::string&);
	std::string get_name() const;
	void set_contact(const std::string&);
	std::string get_contact() const;
private:
  std::string m_name;
  std::string m_contact;
};