#pragma once
#include <string>
#include <iostream>

using std::string;
using std::size_t;
using std::ostream;
using std::endl;
using std::cout;

class Quote

{
public:
	Quote() = default;
	Quote(const string& bookNo, double price) :bookNo(bookNo), price(price) {}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const {
		return n * price;
	}
	virtual void debug() const {
		cout << "bookNo=" << bookNo << " price=" << price << endl;
	}
private:
	string bookNo;
protected:
	double price = 0.0;
};

class Disc_quote :public Quote {
public:
	Disc_quote() = default;
	Disc_quote(const string& bookNo, double price, size_t qty, double disc) :
		Quote(bookNo, price), quantity(qty), discount(disc) {
	}
	double net_price(size_t) const = 0;
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	Bulk_quote(const string& bookNo, double price, size_t min_qty, double discount) :
		Disc_quote(bookNo, price, min_qty, discount)
	{}
	double net_price(size_t n) const override {
		if(n >= min_qty)
		return n * price * (1- discount);

		return n * price;
	}
	void debug() const override final{
		Quote::debug();
		cout << "min_qty=" << min_qty << " discount=" << discount << endl;
	}
private:
	size_t min_qty = 0;
	double discount = 0.0;
};

class Limited_quote : public Disc_quote {
public: 
	Limited_quote(const string& bookNo = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0)
	: Disc_quote(bookNo, sales_price, qty, disc_rate) {
	}
	double net_price(size_t cnt) const override {
		if (cnt <= quantity) {
			return cnt * (1 - discount) * price;
		}
		else {
			return quantity * (1 - discount) * price + (cnt - quantity) * price;
		}
	}
};
 

double print_total(ostream& os, const Quote& item, size_t n);

