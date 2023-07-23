#include "Room.h"
#include <iostream>

Room::Room(int number, const Type& type, int cost) : m_room_number{ number }, m_type{ type }, m_day_cost{ cost } {}

void Room::set_number(int num) {
	m_room_number = num;
}

int Room::get_number() const {
	return m_room_number;
}

void Room::set_day_cost(int cost) {
	switch (m_type)
	{
	case Type::SINGLE:
		m_day_cost = cost;
		break;
	case Type::DOUBLE:
		m_day_cost = cost;
		break;
	case Type::SUIT:
		m_day_cost = cost;
		break;
	}
}

int Room::get_cost() const {
	return m_day_cost;
}

void Room::set_status(bool status) {
	m_status = status;
}

bool Room::get_status() const {
	return m_status;
}

void Room::set_type(const Type& type) {
	m_type = type;
}

Type Room::get_type() const {
	return m_type;
}