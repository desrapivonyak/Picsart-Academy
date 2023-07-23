#pragma once
#include <string>

enum Class {
	START,
	COMFORT,
	BUISINESS
};

class Taxi
{
public:
	Taxi(const std::string&, const std::string&, const Class&);
	~Taxi() = default;
public:
	void set_number(const std::string&);
	std::string get_number() const;
	void set_driver(const std::string&);
	std::string get_driver() const;
	void set_status(const bool);
	bool get_status() const;
	void set_class(const Class&);
	Class get_class() const;
	void set_coefficient();
	double get_coefficient() const;
private:
	std::string m_taxi_number;
	std::string m_driver_name;
	bool m_status;
	Class m_class;
	double m_coefficient;
};

