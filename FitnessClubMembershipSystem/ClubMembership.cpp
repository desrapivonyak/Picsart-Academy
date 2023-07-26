#include "ClubMembership.hpp"
#include <iostream>
#include <limits>

int ClubMembership::get_duration() const {
	return m_duration;
}

void ClubMembership::update_duration(const int new_duration) {
	m_duration = new_duration;
}

void ClubMembership::set_level(const MemberShip& level) {
	m_level = level;
}

void ClubMembership::set_fitness() {
	switch (get_level())
	{
	case STANDARD:
		m_fitness = 12;
		break;
	case PREMIUM:
		m_fitness = 24;
		break;
	case ALL_INCLUDED:
		m_fitness = std::numeric_limits<int>::max();
		break;
	default:
		break;
	}
}

void ClubMembership::set_massage() {
	switch (get_level())
	{
	case STANDARD:
		m_massage = 1;
		break;
	case PREMIUM:
		m_massage = 2;
		break;
	case ALL_INCLUDED:
		m_massage = std::numeric_limits<int>::max();
		break;
	default:
		break;
	}
}

void ClubMembership::set_pool() {
	switch (get_level())
	{
	case STANDARD:
		m_pool = 6;
		break;
	case PREMIUM:
		m_pool = 12;
		break;
	case ALL_INCLUDED:
		m_pool = std::numeric_limits<int>::max();
		break;
	default:
		break;
	}
}

void ClubMembership::update_fitness() {
	if (m_fitness > 0) {
		--m_fitness;
	}
	else {
		std::cout << "All fitness entries were used." << std::endl;
	}
}

void ClubMembership::update_massage() {
	if (m_massage > 0) {
		--m_massage;
	}
	else {
		std::cout << "All massage entries were used." << std::endl;
	}
}

void ClubMembership::update_pool() {
	if (m_pool > 0) {
		--m_pool;
	}
	else {
		std::cout << "All pool entries were used." << std::endl;
	}
}

MemberShip ClubMembership::get_level() const {
	return m_level;
}

int ClubMembership::get_fitness() const {
	return m_fitness;
}

int ClubMembership::get_massage() const {
	return m_massage;
}

int ClubMembership::get_pool() const {
	return m_pool;
}