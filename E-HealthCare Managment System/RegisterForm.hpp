#pragma once
#include <string>
class RegisterForm
{
public:
	void			set_name(const std::string&);
	void			set_contact(unsigned int);
	std::string		get_name() const;
	std::string		get_contact() const;
	virtual void	registeration() = 0;
private:
	std::string		m_name;
	unsigned int	m_contact;
};

