#pragma once
#include <string>

struct Date {
	int day{ 1 };
	int month{ 1 };
	int year{ 1900 };
};

class Flight {
public:
	Flight(const int, const int, const std::string&, const std::string&, const Date&);
	~Flight() = default;
public:
	void set_flight_number(const int);
	void set_seats(const int);
	void set_origin(const std::string&);
	void set_destination(const std::string&);
	void set_date(const Date&);
	int get_flight_number() const;
	int get_available_seats() const;
	std::string get_origin() const;
	std::string get_destination() const;
	Date get_date() const;
private:
	int m_flight_num;
	int m_available_seats;
	std::string m_origin;
	std::string m_destination;
	Date m_date;
};