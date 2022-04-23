#pragma once
#include <iostream>

using std::ostream;
using std::cout;
using std::string;

class PrintString {
public:
	PrintString(ostream& o = cout, char c = ' '):os(o), sep(c){}
	void operator()(const string& s) {
		os << s << sep;
	}

private:
	ostream& os;
	char sep;
};
