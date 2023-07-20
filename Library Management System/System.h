#pragma once
#include "Book.h"
#include "Member.h"
#include <map>
#include <ctime>

class System
{
public:
	System() {};
	System(const std::vector<Book*>&, const std::vector<Member*>&);
	~System() = default;
public:
	void add_book(Book*);
	void borrow_book(Book*, Member*);
	void add_member(Member*);
	void return_book(Book*, Member*);
	std::map<Book*, Member*> get_borrowed_books() const;
	std::vector<Book*> get_books() const;
	int is_overdue(Book*);
	bool search_book(const std::string&);
	std::string overdue_report();
private:
	std::vector<Book*> m_books;
	std::map<Book*, Member*> m_borrowed_books;
	std::vector<Member*> m_members;
};