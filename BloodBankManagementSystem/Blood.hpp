#pragma once
#include <string>

class Blood
{
public:
	Blood(const double, const std::string&);
	~Blood() = default;
public:
	void set_count(const double);
	double get_count() const;
	void set_type(const std::string&);
	std::string get_type() const;
private:
	double m_count;
	std::string m_type;
};

