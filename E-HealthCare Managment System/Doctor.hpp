#pragma once
#include "RegisterForm.hpp"

class Doctor : public RegisterForm
{
public:
	void set_specalization(const std::string& specalization);
	void set_yearsofexperience(unsigned int years);
	std::string get_specialization() const;
	unsigned int get_yearsofexperience() const;
	void registeration() override;
private:
	std::string		m_specalization;
	unsigned int	m_yearsofexperience;
};

