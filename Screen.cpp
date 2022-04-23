#include "Screen.h"
#include <iostream>

Screen& Screen::move(unsigned r, unsigned c) {
	cursor = r * width + c;
	return *this;
}
Screen& Screen::set(char ch) {
	contents[cursor] = ch;
	return *this;
}
Screen& Screen::set(unsigned r, unsigned c, char ch) {
	contents[r * width + c] = ch;
	return *this;
}
const Screen& Screen::disply() const{
	do_disply(std::cout);
	//access_ctr++;
	return *this;
}

Screen& Screen::disply() {
	do_disply(std::cout);
	return *this;
}

Screen::pos Screen::size() const
{
	return height * width;
}

void Window_mgr::clear(ScreenIndex i)
{
	Screen myScreen(10, 20, 'u');
	std::cout << myScreen.contents << std::endl;
	//Screen& s = screens[i];
	//s.contents = std::string(s.height * s.width, ' ');
}
