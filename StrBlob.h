#pragma once
#include <vector>
#include <string>
#include <memory>
#include <iostream>

using std::string;
using std::initializer_list;
using std::vector;
using std::make_shared;
using std::cout;
using std::ostream;

class StrBlobPtr;

class StrBlob
{
	friend class StrBlobPtr;
public:
	typedef std::vector<std::string>::size_type size_type;
	StrBlob();
	StrBlob(std::initializer_list<std::string> il);
	size_type size() const { return data->size(); }
	bool empty() const { return data->empty(); }
	void push_back(const std::string& t) { data->push_back(t); }
	void pop_back();
	std::string& front();
	const string& front() const;
	std::string& back();
	const string& back() const;

	StrBlobPtr begin();
	StrBlobPtr begin() const;
	StrBlobPtr end();
	StrBlobPtr end() const;

private:
	std::shared_ptr<std::vector<std::string>> data;
	void check(size_type i, const std::string& msg) const;
};

class StrBlobPtr
{
	friend bool eq(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator==(const StrBlobPtr&, const StrBlobPtr&);
	friend bool operator!=(const StrBlobPtr&, const StrBlobPtr&);
	friend ostream& operator<<(ostream&, const StrBlobPtr&);
public:
	StrBlobPtr() : curr(0) {};
	StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) { };
	StrBlobPtr(const StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) { };
	std::string& deref() const;
	StrBlobPtr& incr();
	StrBlobPtr& decr();

	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);

	string& operator*() const;
	string* operator->() const;

private:
	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
	std::weak_ptr<vector<string>> wptr;
	std::size_t curr;
};

bool neq(const StrBlobPtr& lhs, const StrBlobPtr& rhs);
