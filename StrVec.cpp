#include "StrVec.h"
#include <iostream>

using std::cout;
using std::endl;

StrVec::StrVec(std::initializer_list<string> il) {
	auto newdata = alloc_n_copy(il.begin(), il.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

void StrVec::push_back(const string& s) {
	chk_n_alloc();
	alloc.construct(first_free++, s);
	cout << "push_back(const string& s)" << endl;
}

void StrVec::push_back(string&& s) {
	chk_n_alloc();
	alloc.construct(first_free++, std::move(s));
	cout << "push_back(string&& s)" << endl;
}

pair<string*, string*> StrVec::alloc_n_copy(const string* b, const string* e) {
	auto data = alloc.allocate(e - b);
	return { data, std::uninitialized_copy(b,e,data) };
}

void StrVec::free() {
	if (elements) {
		for (auto p = first_free; p != elements;) {
			alloc.destroy(--p); //ÄæÐòÉ¾³ý
		}
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
	cout << "StrVec(const StrVec& s)" << endl;
}

StrVec::StrVec(StrVec&& s) noexcept
	: elements(s.elements), first_free(s.first_free), cap(s.cap) {
	s.elements = s.first_free = s.cap = nullptr;
	cout << "StrVec(StrVec&& s)" << endl;
}

StrVec::~StrVec() {
	free();
}

StrVec& StrVec::operator=(const StrVec& rhs) {
	auto newdata = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = newdata.first;
	first_free = cap = newdata.second;
	cout << "StrVec::operator=&" << endl;
	return *this;
}

StrVec& StrVec::operator=(StrVec&& rhs) noexcept {
	if (this != &rhs) {
		free();
		elements = rhs.elements;
		first_free = rhs.first_free;
		cap = rhs.cap;
		rhs.elements = rhs.first_free = rhs.cap = nullptr;
	}
	cout << "StrVec::operator=&&&&&&" << endl;
	return *this;
}

StrVec& StrVec::operator=(std::initializer_list<std::string> rhs){
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	
	free();
	elements = data.first; 
	first_free = cap = data.second;
	return *this;
} 

string& StrVec::operator[](size_t n) {
	return elements[n];
}
const string& StrVec::operator[](size_t n) const {
	return elements[n];
}

void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	auto newdata = alloc.allocate(newcapacity);
	auto dest = std::uninitialized_copy(std::make_move_iterator(begin()), std::make_move_iterator(end()), newdata);
	//auto dest = newdata;
	//auto elem = elements;
	//for (size_t i = 0; i != size(); i++) {
	//	alloc.construct(dest++, std::move(*elem++));
	//}
	free();
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

inline
void StrVec::resize(size_t n) {
	if (n > size()) {
		while (size() < n) {
			push_back("");
		}
	}
	else if (n < size()) {
		while (size() > n) {
			alloc.destroy(--first_free);
		}
	}
}

inline
void StrVec::resize(size_t n, const string& s) {
	if (n > size()) {
		while (size() < n) {
			push_back(s);
		}
	}
}