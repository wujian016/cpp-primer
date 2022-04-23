#include "StrBlob.h"
#include <stdexcept>

using std::string;
using std::initializer_list;
using std::vector;
using std::make_shared;
using std::shared_ptr;
using std::weak_ptr;

StrBlob::StrBlob() :data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}
void StrBlob::check(size_type i, const string& msg) const {
	if (i >= data->size()) {
		throw std::out_of_range(msg);
	}
}
const string& StrBlob::front() const {
	check(0, "front on empty StrBlob");
	return data->front();
}
string& StrBlob::front() {
	check(0, "front on empty StrBlob");
	return data->front();
}
const string& StrBlob::back() const {
	check(0, "back on empty StrBlob");
	return data->back();
}
string& StrBlob::back() {
	check(0, "back on empty StrBlob");
	return data->back();
}
void StrBlob::pop_back() {
	check(0, "pop_back on empty StrBlob");
	data->pop_back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::begin() const { return StrBlobPtr(*this); }
StrBlobPtr StrBlob::end() {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}
StrBlobPtr StrBlob::end() const {
	auto ret = StrBlobPtr(*this, data->size());
	return ret;
}

shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i, const string& msg) const {
	auto ret = wptr.lock();
	if (!ret) {
		throw std::runtime_error("unbound StrBlobPtr");
	}
	if (i >= ret->size()) {
		throw std::out_of_range(msg);
	}
	return ret;
}

string& StrBlobPtr::deref() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

StrBlobPtr& StrBlobPtr::incr() {
	check(curr, "Increment past end of StrBlobPtr");
	++curr;
	return *this;
}

StrBlobPtr& StrBlobPtr::decr() {
	--curr;
	//check(-1, "decrement past beging of StBlobPtr");
	return *this;
}

inline
bool eq(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r) {
		return (!r || lhs.curr == rhs.curr);
	}
	else {
		return false;
	}
}
 
bool neq(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	return !eq(lhs, rhs);
} 

StrBlobPtr& StrBlobPtr::operator++() {
	return incr();
}

StrBlobPtr& StrBlobPtr::operator--() {
	return decr();
}

StrBlobPtr StrBlobPtr::operator++(int) {
	StrBlobPtr ret = *this;
	incr();
	return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
	StrBlobPtr ret = *this;
	decr();
	return ret;
}

string& StrBlobPtr::operator*() const {
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

string* StrBlobPtr::operator->() const {
	return &this->operator*();
}

bool operator==(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	return eq(lhs, rhs);
}

bool operator!=(const StrBlobPtr& lhs, const StrBlobPtr& rhs) {
	return !(lhs == rhs);
}

ostream& operator<<(ostream& os, const StrBlobPtr& s) {
	os << s.deref();
	return os;
}