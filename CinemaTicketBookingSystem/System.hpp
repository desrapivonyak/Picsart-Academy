#pragma once
#include "Customer.hpp"
#include "Movie.hpp"
#include <vector>

class System
{
public:
	System() = default;
	~System() = default;
public:
	void add_movie(Movie*);
	std::vector<Movie*> get_movies() const;
	void search_movie(const std::string&);
	void booking(Movie*, int);
	void generate_ticket();
private:
	std::string m_ticket;
	std::vector<Movie*> m_movies;
};

