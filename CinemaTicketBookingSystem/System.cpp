#include "System.hpp"
#include <iostream>
#include <fstream>

void System::add_movie(Movie* movie) {
	m_movies.push_back(movie);
}

std::vector<Movie*> System::get_movies() const {
	return m_movies;
}

void System::search_movie(const std::string& title) {
	for (auto movie : get_movies()) {
		if (movie->get_title() == title) {
			std::cout << "Movie found.\nShowtime date is on " << std::to_string(movie->get_showtime_date().day);
			std::cout << "/" << std::to_string(movie->get_showtime_date().month);
			std::cout << "/" << std::to_string(movie->get_showtime_date().year) << std::endl;
			return;
		}
	}
	std::cout << "Movie was not found." << std::endl;
}

void System::booking(Movie* movie, int tic_num) {
	for (auto m : get_movies()) {
		if (m->get_title() == movie->get_title() && m->get_showtime_seats() >= tic_num) {
			m_ticket = "Movie: " + m->get_title() + "\nShowtime: " + std::to_string(m->get_showtime_date().day) + "/" + std::to_string(m->get_showtime_date().month);
			m_ticket += "/" + std::to_string(m->get_showtime_date().year) + "\nDuration: " + std::to_string(m->get_duration()) + " minutes";
			m_ticket += "\nSeats: " + std::to_string(tic_num) + "\n";
			generate_ticket();
			m->set_showtime_seats(m->get_showtime_seats() - tic_num);
			return;
		}
	}
	std::cout << "The movie showtime seats all are booked." << std::endl;
}

void System::generate_ticket() {
	std::cout << m_ticket << std::endl;
	std::ofstream output("ticket.txt");
	if (output.is_open()) {
		output << m_ticket << std::endl;
		output.close();
		std::cout << "Ticket created." << std::endl;
	}
	else {
		std::cout << "Failed to create ticket." << std::endl;
	}
}