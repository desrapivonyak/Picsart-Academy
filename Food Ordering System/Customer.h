#pragma once
#include <string>

enum class PaymentMethod {
	CASH,
	CARD
};

class Customer
{
public:
	Customer() {};
	Customer(const std::string&, const std::string&);
	~Customer() = default;
public:
	void set_name(const std::string&);
	void set_contact(const std::string&);
	void set_payment(const PaymentMethod&);
	std::string get_name() const;
	std::string get_contact() const;
	PaymentMethod get_payment() const;
private:
	std::string m_name;
	std::string m_contact;
	PaymentMethod m_payment;
};