#pragma warning(disable: 4996)
#include "OrderSystem.h"
#include <vector>
#include <map>
#include <chrono>
#include <fstream>

OrderSystem::OrderSystem(const Customer& customer) : m_custom{ customer } {}

void OrderSystem::set_orderNumber(int num) {
	m_orderNumber = num;
}

int OrderSystem::get_order_number() const {
	return m_orderNumber;
}

std::pair<std::string, int> OrderSystem::placeOrder(const Restaurant& restaurant) {
	int price{ 0 };
	std::string order;
	std::cout << "Place your order:\n";
	for (auto& m : restaurant.get_menu()) {
		int k;
		std::cout << "Input how many " + m.first + "s do you want to order or 0 if none:\n";
		std::cin >> k;
		if (k > 0) {
			order += "* " + m.first;
			price += m.second * k;
			order += " x " + std::to_string(k) + " - " + std::to_string(m.second * k) + " AMD\n";
		}
	}
	if (price == 0) {
		return std::make_pair("Failed order!", 0);
	}
	order += "Order price: " + std::to_string(price) + " AMD\n";
	std::cout << "Choose your payment method (0 - if with cash or 1 - if with a card): ";
	PaymentMethod pay;
	int p;
	std::cin >> p;
	if (p) pay = PaymentMethod::CARD;
	else pay = PaymentMethod::CASH;
	switch (pay) {
	case PaymentMethod::CASH:
		order += "Payed by cash\n";
		break;
	case PaymentMethod::CARD:
		order += "Payed by card\n";
		break;
	}
	std::cout << "Order number: ";
	set_orderNumber(price*753);
	std::cout << std::to_string(get_order_number()) << std::endl;
	return std::make_pair(order, get_order_number());
}

std::string OrderSystem::bill_generation(const std::string& order_str, const Restaurant& restaurant) {
	std::string order = "--------------------------------------------\n";
	order += "Resident: " + restaurant.get_name() + "\nOrder items:\n";
	order += order_str;
	return order;
}

void OrderSystem::trackOrder(int num) {
	if (num > 0) {
		std::cout << "Your order is on its way." << std::endl;
	}
	else {
		std::cout << "There is no order with that order number." << std::endl;
	}
}

void OrderSystem::report_to_console(const std::string& str) {
	std::cout << str << std::endl;
}

std::string OrderSystem::get_current_time() {
	auto now = std::chrono::system_clock::now();
	std::time_t current_time = std::chrono::system_clock::to_time_t(now);
	std::tm* localtime = std::localtime(&current_time);
	char buffer[10];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d", localtime);
	return std::string(buffer);
}

void OrderSystem::report_to_txt(const std::string& str) {
	std::string file_name = m_custom.get_name() + "_" + get_current_time() + ".txt";
	std::ofstream output(file_name);
	if (output.is_open()) {
		output << str << "\n";
		std::cout << "Bill generated succesfully!" << std::endl;
		output.close();
	}
	else {
		std::cout << "Biil generation failed!" << std::endl;
	}
}
