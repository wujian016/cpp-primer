#pragma once
#include <stdexcept>

class SmallInt {
public:
	SmallInt(int i = 0) : val(i) {
		if (i < 0 || i> 255)
			throw std::out_of_range("Bad smallint value");
	}
	explicit operator std::size_t() const {
		return val;
	}
	
	private:
		std::size_t val;
};