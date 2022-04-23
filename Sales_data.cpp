#include "Sales_data.h"
//std::string isbn() const { return bookNo; }
//Sales_data& Sales_data::combine(const Sales_data& data) {
//	data.revenue
//}

Sales_data::Sales_data(const std::string& book, const unsigned num, const double sellp, const double salep) {
	std::cout << "Sales_data(Sales_data(const std::string& book, const unsigned num, const double sellp, const double salep))" << std::endl;
	bookNo = book;
	units_sold = num;
	sellingprice = sellp;
	saleprice = salep;
	if (sellingprice != 0) {
		discount = saleprice / sellingprice;
	}
}

Sales_data& Sales_data::operator-=(const Sales_data& rhs) {
	units_sold -= rhs.units_sold;
	revenue -= rhs.revenue;
	return *this;
}

Sales_data add(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sum = lhs;
	sum.combine(rhs);
	return sum;
}

std::ostream& print(std::ostream& os, const Sales_data& item) {
	os << item.isbn() << " " << item.units_sold << " " << item.sellingprice << " " << item.saleprice << " " << item.discount;
	return os;
}

std::ostream& operator<<(std::ostream& os, const Sales_data& item) {
	return print(os, item);
}

std::istream& read(std::istream& is, Sales_data& item) {
	is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
	if (!is) {
		item = Sales_data();
	}
	return is;
}

std::istream& operator>>(std::istream& is, Sales_data& item) {
	return read(is, item);
}

Sales_data operator-(const Sales_data& lhs, const Sales_data& rhs) {
	Sales_data sub = lhs;
	sub -= rhs;
	return sub;
}

bool operator==(const Sales_data& lhs, const Sales_data& rhs) {
	return lhs.isbn() == rhs.isbn() &&
		lhs.units_sold == rhs.units_sold &&
		lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data& lhs, const Sales_data& rhs) {
	return !(lhs == rhs);
}