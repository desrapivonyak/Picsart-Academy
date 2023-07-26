#pragma once
#include <string>

struct Date {
	int day{ 1 };
	int month{ 1 };
	int year{ 1900 };
};

enum TRACKING {
	PICKUP,
	ON_TRANSIT,
	DELIVERED
};

class Deliveries
{
public:
	Deliveries(const std::string&, const std::string&, const std::string&, const Date&);
	~Deliveries() = default;
public:
	void set_item(const std::string&);
	std::string get_item() const;
	void set_origin(const std::string&);
	std::string get_origin() const;
	void set_destination(const std::string&);
	std::string get_destination() const;
	void set_register_time(const Date&);
	Date get_register_time() const;
	void set_status(const TRACKING&);
	TRACKING get_status() const;
private:
	std::string m_item;
	std::string m_origin;
	std::string m_destination;
	Date m_date;
	TRACKING m_status;
};