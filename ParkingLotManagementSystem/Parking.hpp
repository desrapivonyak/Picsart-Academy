#pragma once

enum SIZE {
	COMPACT = 1,
	REGULAR = 2,
	LARGE = 5
};

class Parking
{
public:
	Parking(int, const SIZE&);
	~Parking() = default;
public:
	void set_status(const bool);
	bool get_status() const;
	void set_number(const int);
	int get_number() const;
	void set_size(const SIZE&);
	SIZE get_size() const;
private:
	bool m_status;
	int m_number;
	SIZE m_size;
};