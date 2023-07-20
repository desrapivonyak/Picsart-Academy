#pragma once
#include <string>
#include <ctime>

class Book
{
public:
	Book() {};
	Book(const std::string&, const std::string&, const std::string&);
	~Book() = default;
public:
	void set_title(const std::string&);
	void set_author(const std::string&);
	void set_genre(const std::string&);
	void set_status(bool);
	void set_date(time_t&);
	time_t get_date() const;
	std::string get_title() const;
	std::string get_author() const;
	std::string get_genre() const;
	bool get_status() const;
private:
	std::string m_title;
	std::string m_author;
	std::string m_genre;
	bool m_status;
	time_t m_due_date;
};