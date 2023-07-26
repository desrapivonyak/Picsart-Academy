#pragma once

enum MemberShip {
	STANDARD,
	PREMIUM,
	ALL_INCLUDED
};

class ClubMembership {
public:
	ClubMembership(const MemberShip& level) : m_level{ level } {};
	~ClubMembership() = default;
public:
	int get_duration() const;
	void update_duration(const int);
	void set_level(const MemberShip&);
	void set_fitness();
	void set_massage();
	void set_pool();
	void update_fitness();
	void update_massage();
	void update_pool();
	MemberShip get_level() const;
	int get_fitness() const;
	int get_massage() const;
	int get_pool() const;
private:
	int m_duration {30};
	int m_fitness;
	int m_massage;
	int m_pool;
	MemberShip m_level;
};