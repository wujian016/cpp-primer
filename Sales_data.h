#pragma once 
#include <string>
#include <iostream>

using std::ostream;
using std::istream;
using std::string;
using std::cout; 

class Sales_data
{
	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
	friend std::ostream& print(std::ostream& os, const Sales_data& item);
	friend std::istream& read(std::istream& is, Sales_data& item);
	friend std::ostream& operator<<(std::ostream& os, const Sales_data& item);
	friend std::istream& operator>>(std::istream& is, Sales_data& item);
	friend Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs);
	friend bool operator==(const Sales_data& lhs, const Sales_data& rhs);
	friend bool operator!=(const Sales_data& lhs, const Sales_data& rhs); 
public:
	Sales_data() : Sales_data("", 0, 0,0) {
		std::cout << "Sales_data()" << std::endl;
	};
	explicit Sales_data(const std::string& book) :Sales_data(book, 0, 0, 0)
	{
		std::cout << "Sales_data(const std::string& book)" << std::endl;
	}
	Sales_data(const std::string& book, const unsigned num, const double sellp, const double salep);
	explicit Sales_data(std::istream& is):Sales_data() {
		std::cout << "Sales_data(std::istream& is)" << std::endl;
		read(is, *this);
	}

	std::string isbn() const { return bookNo; }
	Sales_data& combine(const Sales_data& rhs) {
		units_sold += rhs.units_sold;
		saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
		if (sellingprice != 0) {
			discount = saleprice / sellingprice;
		}
		return *this;
	}
	double avg_price() const {
		if (units_sold) {
			return revenue / units_sold;
		}
		else
		{
			return 0;
		}
	}

	Sales_data& operator-=(const Sales_data& rhs); 
	explicit operator string() const {
		return bookNo;
	}
	operator  double() const {
		return sellingprice;
	}

private:
	std::string bookNo;
	unsigned units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
	double revenue = 0.0;
};
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream& print(std::ostream&, const Sales_data&);
std::istream& read(std::istream&, Sales_data&);