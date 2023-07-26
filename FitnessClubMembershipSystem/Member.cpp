#include "Member.hpp"
#include <iostream>

Member::Member(const std::string& name, const std::string& contact, ClubMembership* membership) :
	m_name(name), m_contact(contact), m_membership(membership) {}

void Member::set_name(const std::string& name) {
	m_name = name;
}

void Member::set_contact(const std::string& contact) {
	m_contact = contact;
}

void Member::set_membership(ClubMembership* level) {
	m_membership->set_level(level->get_level());
	m_membership->set_fitness();
	m_membership->set_massage();
	m_membership->set_pool();
}

std::string Member::get_name() const {
	return m_name;
}

std::string Member::get_contact() const {
	return m_contact;
}

ClubMembership* Member::get_membership() const {
	return m_membership;
}