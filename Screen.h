#pragma once
#include <string>
#include <vector>

class Screen;

class Window_mgr
{
public:
	using ScreenIndex = std::vector<Screen>::size_type;
	void clear(ScreenIndex);
//private:
	//std::vector<Screen> screens{ Screen(24, 80, ' ') };
};

class Screen
{
	friend void Window_mgr::clear(ScreenIndex);
public:
	typedef std::size_t pos;
public:
	Screen()= default;
	Screen(unsigned ht, unsigned wd) : height(ht), width(wd), contents(ht* wd, ' ') {
	}
	Screen(unsigned ht, unsigned wd, char c) : height(ht), width(wd), contents(ht* wd, c){};
public: 
	Screen& move(unsigned r, unsigned c);
	Screen& set(char ch);
	Screen& set(unsigned r, unsigned c, char ch);
	const Screen& disply() const;
	Screen& disply();
	pos size() const;
private:
	unsigned height = 0, width = 0;
	unsigned cursor = 0;
	std::string contents;
	void do_disply(std::ostream& os) const { os << contents; }
	//mutable size_t access_ctr = 0;
};

