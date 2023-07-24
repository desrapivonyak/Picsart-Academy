#include "Movie.hpp"

Movie::Movie(const std::string& title, const int duartion, const int rating, const ShowTime& show)
	: m_title{ title }, m_duration{ duartion }, m_rating{ rating } {
	m_showtime.date.day = show.date.day;
	m_showtime.date.month = show.date.month;
	m_showtime.date.year = show.date.year;
	m_showtime.seats = show.seats;
}

void Movie::set_title(const std::string& title) {
	m_title = title;
}

std::string Movie::get_title() const {
	return m_title;
}

void Movie::set_duration(const int duration) {
	m_duration = duration;
}

int Movie::get_duration() const {
	return m_duration;
}

void Movie::set_rating(const int rating) {
	m_rating += rating;
}

int Movie::get_rating() const {
	return m_rating;
}

void Movie::set_showtime_date(const Date& date) {
	m_showtime.date.day = date.day;
	m_showtime.date.month = date.month;
	m_showtime.date.year = date.year;
}

Date Movie::get_showtime_date() const {
	return m_showtime.date;
}

void Movie::set_showtime_seats(const int seats) {
	m_showtime.seats = seats;
}

int Movie::get_showtime_seats() const {
	return m_showtime.seats;
}