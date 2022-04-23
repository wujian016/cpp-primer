#pragma once
#include <string>

using std::string;
using std::size_t;

class HasPtr {
	friend void swap(HasPtr&, HasPtr&);
public:
	HasPtr(const string& s = string()) : ps(new string(s)), i(0) {
	}
	HasPtr(const HasPtr& ptr) : ps(ptr.ps), i(ptr.i) {
			ps = new string(*ptr.ps);
			i = ptr.i;
		//++* use;
	}
	//HasPtr& operator = (const HasPtr& rhs);
	HasPtr& operator = (HasPtr rhs);
	HasPtr& operator=(const string&);
	string& operator*();
	bool operator<(const HasPtr&) const;
	//HasPtr(HasPtr&&) = delete;
	~HasPtr() {
	/*	if (-- * use == 0)
		{*/
			delete ps;
	/*		delete use;
		}*/
	}
private:
	string* ps;
	int i;
	//size_t* use;
};


