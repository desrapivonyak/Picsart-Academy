#include "System.h"
#include <iostream>

System::System(const std::vector<Book*>& books, const std::vector<Member*>& members) : m_books{ books }, m_members{ members } {}

void System::add_book(Book* book) {
	m_books.push_back(book);
}

void System::add_member(Member* member) {
	m_members.push_back(member);
}

std::vector<Book*> System::get_books() const {
	return m_books;
}

std::map<Book*, Member*> System::get_borrowed_books() const {
	return m_borrowed_books;
}

void System::borrow_book(Book* book, Member* member) {
	m_borrowed_books[book] = member;
	book->set_status(false);
	member->add_borrowed(book);
	time_t current = time(0);
	current -= static_cast<time_t>(7 * 24 * 360);
	book->set_date(current);
}

void System::return_book(Book* book, Member* member) {
	m_borrowed_books.erase(book);
	book->set_status(true);
	member->return_borrowed(book);
}

bool System::search_book(const std::string& author) {
	bool ans = false;
	for (auto l : m_books) {
		if (author == l->get_author() || author == l->get_genre() || author == l->get_title()) {
			ans = true;
		}
	}
	return ans;
}

int System::is_overdue(Book* book) {
	time_t current_date = time(0);
	return (book->get_date() > current_date) ? 0 : (current_date - book->get_date()) / (static_cast<long long>(24 * 360));
}