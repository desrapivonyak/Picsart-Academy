#pragma once
#include "Interation.h"
#include "Sale.h"

class Complaint :
    public Interation
{
public:
	Complaint() = default;
	~Complaint() = default;
public:
	void set_description(const std::string&);
	void set_sale(const Sale&);
	std::string get_description() const;
	Sale get_sale() const;
	void register_interation() override;
	std::string inter_info() override;
private:
	std::string m_description;
	Sale m_sale;
};

