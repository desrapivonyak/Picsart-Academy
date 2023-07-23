#pragma once
#include <string>

enum Type {
	SINGLE,
	DOUBLE, 
	SUIT
};

class Room
{
public:
	Room() {};
	Room(int, const Type&, int);
	~Room() = default;
public:
	void set_number(int);
	int get_number() const;
	void set_day_cost(int);
	int get_cost() const;
	void set_status(bool);
	bool get_status() const;
	void set_type(const Type&);
	Type get_type() const;
private:
	int m_room_number;
	int m_day_cost;
	bool m_status;
	Type m_type;
};