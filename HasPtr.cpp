#include "HasPtr.h"
#include <iostream>

using std::cout;
using std::endl;

//HasPtr& HasPtr::operator=(const HasPtr& rhs) {
//	auto newps = new string(*rhs.ps);
//	delete ps;
//	ps = rhs.ps;
//	i = rhs.i; 
//	return *this;
//}

HasPtr& HasPtr::operator = (HasPtr rhs) {
	swap(*this, rhs);
	return *this;
}

HasPtr& HasPtr::operator=(const string& rhs) {
	*ps = rhs;
	return *this;
}

string& HasPtr::operator*() {
	return *ps;
}

bool HasPtr::operator<(const HasPtr& rhs) const {
	return *ps < *rhs.ps;
}

//inline
void swap(HasPtr& lhs, HasPtr& rhs) {
	cout << "change " << *lhs.ps << " to " << *rhs.ps << endl;
	using std::swap;
	swap(lhs.ps, rhs.ps);
	swap(lhs.i, rhs.i);
}
