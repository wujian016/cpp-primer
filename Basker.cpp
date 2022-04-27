#include "Basker.h"

double Basker::total_receipt(std::ostream& os) const {
	double sum = 0.0;
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl;
	return sum;
}

void Basker::add_item(Quote& sale){
	items.insert(std::shared_ptr<Quote>(sale.clone()));
}

void Basker::add_item(Quote&& sale) {
	items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
}
