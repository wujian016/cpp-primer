#include "Person.h"
std::string Person::getAddress() const {
	return strAddress;
}

Person::Person() = default;

std::istream& read(std::istream& is, Person& per) {
	is >> per.strName >> per.strAddress;
	return is;
}

std::ostream& print(std::ostream& os, const Person& per) {
	os << per.getName() << per.getAddress();
	return os;
}
