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
	Quote(const string& bookNo, double price) :bookNo(bookNo), price(price) {
		cout << "Quote constructor is running" << endl;
	}
	//Quote(const Quote& rhs) {
	//	bookNo = rhs.bookNo;
	//	price = rhs.price;
	//	cout << "Quote copy constructor is running" << endl;
	//}
	Quote& operator=(const Quote& rhs) { 
		bookNo = rhs.bookNo;
		price = rhs.price;
		cout << "Quote copy operator is running" << endl;
		return *this;
	}
	string isbn() const { return bookNo; }
	virtual double net_price(size_t n) const {
		return n * price;
	}
	virtual void debug() const {
		cout << "bookNo=" << bookNo << " price=" << price << endl;
	}
	virtual Quote* clone() const& {
		return new Quote(*this);
	}
	virtual Quote* clone()&& {
		return new Quote(std::move(*this));
	}
	virtual ~Quote() {
		cout << "Quote destructor is running" << endl;
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
		cout << "Disc_quote constructor is running" << endl;
	}
	Disc_quote(const Disc_quote& rhs): Quote(rhs) {
		quantity = rhs.quantity;
		discount = rhs.discount;
		cout << "Disc_quote copy constructor is running" << endl;
	}
	Disc_quote& operator=(const Disc_quote& rhs) {
		Quote::operator=(rhs);
		quantity = rhs.quantity;
		discount = rhs.discount;
		cout << "Disc_quote copy operator is running" << endl;
		return *this;
	}
	double net_price(size_t) const = 0;
	~Disc_quote() {
		cout << "Disc_quote destructor is running" << endl;
	}
protected:
	size_t quantity = 0;
	double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
	Bulk_quote() = default;
	using Disc_quote::Disc_quote;
	/*Bulk_quote(const string& bookNo, double price, size_t min_qty, double discount) :
		Disc_quote(bookNo, price, min_qty, discount)
	{
		cout << "Bulk_quote constructor is running" << endl;
	}*/
	Bulk_quote& operator=(const Bulk_quote& rhs) {
		Disc_quote::operator=(rhs);
		cout << "Bulk_quote copy operator is running" << endl;
		return *this;
	}
	double net_price(size_t n) const override {
		if (n >= min_qty)
			return n * price * (1 - discount / 100.0);

		return n * price;
	}
	void debug() const override final {
		Quote::debug();
		cout << "min_qty=" << min_qty << " discount=" << discount << endl;
	}
	Bulk_quote* clone() const& override{
		return new Bulk_quote(*this);
	}
	Bulk_quote* clone()&& override {
		return new Bulk_quote(std::move(*this));
	}
	~Bulk_quote() {
		cout << "Bulk_quote destructor is running" << endl;
	}
private:
	size_t min_qty = 0;
	//double discount = 0.0;
};

class Limited_quote : public Disc_quote {
public:
	Limited_quote(const string& bookNo = "", double sales_price = 0.0, size_t qty = 0, double disc_rate = 0.0)
		: Disc_quote(bookNo, sales_price, qty, disc_rate) {
		cout << "Limited_quote constructor is running" << endl;
	}
	double net_price(size_t cnt) const override {
		if (cnt <= quantity) {
			return cnt * (1 - discount) * price;
		}
		else {
			return quantity * (1 - discount) * price + (cnt - quantity) * price;
		}
	}
	~Limited_quote() {
		cout << "Limited_quote destructor is running" << endl;
	}
};


double print_total(ostream& os, const Quote& item, size_t n);

