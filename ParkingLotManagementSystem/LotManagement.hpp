#pragma once
#include "User.hpp"
#include <vector>

class LotManagement
{
public:
	LotManagement() = default;
	~LotManagement() = default;
public:
	void add_spaces(Parking*);
	std::vector<Parking*> get_spaces() const;
	std::string get_reciept() const;
	void set_fee(const int);
	int get_fee() const;
	void reserve_space(const User&, const int);
	void calculate_fee(const User&, const int);
	void generate_reciept();
private:
	int m_fee;
	std::string m_reciept;
	std::vector<Parking*> m_parking_spaces;
};

