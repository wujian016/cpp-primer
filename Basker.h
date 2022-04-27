#pragma once
#include "Quote.h"
#include <set>

class Basker
{
public:
	void add_item(Quote& sale);
	void add_item(Quote&& sale);
	double total_receipt(std::ostream&) const;

private:
	static bool compare(const std::shared_ptr<Quote>& lhs, const std::shared_ptr<Quote>& rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

