#pragma once
#include "Blood.hpp"

class Donor
{
public:
	Donor(const std::string&, const std::string&, const Blood&);
	~Donor() = default;
public:
	void set_name(const std::string&);
	std::string get_name() const;
	void set_contact(const std::string&);
	std::string get_contact() const;
	Blood get_blood() const;
private:
	std::string m_name;
	std::string m_contact;
	Blood m_blood;
};

