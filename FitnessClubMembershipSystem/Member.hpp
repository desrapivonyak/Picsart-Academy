#pragma once
#include<string>
#include <vector>
#include "ClubMembership.hpp"

class Member
{
public:
	Member(const std::string&, const std::string&, ClubMembership*);
	~Member() = default;
public:
	void set_name(const std::string&);
	void set_contact(const std::string&);
	void set_membership(ClubMembership*);
	std::string get_name() const;
	std::string get_contact() const;
	ClubMembership* get_membership() const;
private:
	std::string m_name;
	std::string m_contact;
	ClubMembership* m_membership;
};