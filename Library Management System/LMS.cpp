#include <iostream>
#include "System.h"

int main()
{
    Book* book = new Book("Alchemist", "Paolo", "Novel");
    std::vector<Book*> books{ book };
    Member* member = new Member("Tatev", "37444728828");
    std::vector<Member*> members{ member };
    System library{ books, members };
    library.borrow_book(book, member);
    std::cout << library.search_book("Austin") << std::endl;
    for (auto l : library.get_books()) {
        std::cout << l->get_status() << std::endl;
    }
    for (auto& m : library.get_borrowed_books()) {
        std::cout << m.first->get_author() << " " << m.second->get_name() << std::endl;
    }
    std::cout << library.is_overdue(book) << std::endl;
    return 0;
}