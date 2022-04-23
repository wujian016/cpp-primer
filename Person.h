#pragma once
#include <string>
#include <iostream>

class Person
{
	friend std::istream& read(std::istream& is, Person& per);
	friend std::ostream& print(std::ostream& os, const Person& per);
public:
	Person();
	Person(const std::string& n, const std::string& a) : strName(n), strAddress(a) {
	}
private:
	std::string strName;
	std::string strAddress;
public:
	std::string getName() const { return strName; }
	std::string getAddress() const;
};

