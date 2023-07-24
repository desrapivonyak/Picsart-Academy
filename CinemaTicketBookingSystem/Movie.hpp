#pragma once
#include <string>

struct Date {
	int day{ 1 };
	int month{ 1 };
	int year{ 1990 };
};

struct ShowTime {
	Date date;
	int seats;
};

class Movie
{
public:
	Movie(const std::string&, const int, const int, const ShowTime&);
	~Movie() = default;
public:
	void set_title(const std::string&);
	std::string get_title() const;
	void set_duration(const int);
	int get_duration() const;
	void set_rating(const int);
	int get_rating() const;
	void set_showtime_date(const Date&);
	void set_showtime_seats(const int);
	Date get_showtime_date() const;
	int get_showtime_seats() const;
private:
	std::string m_title;
	int m_duration;
	int m_rating;
	ShowTime m_showtime;
};

