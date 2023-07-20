#include <iostream>
#include "Book.h"
#include "Customer.h"
#include "BookStore.h"

int main() {
	Book book("Alchemist", "Paolo", 3500, 30);
	Customer customer("Tatev", "tatevsr@gmail.com");
	BookStore store;

	customer.add_to_cart(&book, 5);
	customer.purchase(&book, 4);
	store.add_books(&book);
	store.add_customers(&customer);
	store.history_to_txt();
}