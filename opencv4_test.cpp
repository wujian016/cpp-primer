// opencv4_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include <opencv2/opencv.hpp>

#include <vector>
#include <iostream> 
#include "Sales_data.h"
#include "Person.h"
#include "Screen.h"
#include <fstream>
#include <sstream>
#include <list>
#include <deque>
#include <array>
#include <forward_list>
#include <string>
#include <stack>
#include <queue> 
#include <algorithm>
#include <numeric>
#include <iterator>
#include <functional>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include "StrBlob.h"
#include <cstring>
#include <memory>

#include "TextQuery.h"
#include "HasPtr.h"
#include "Message.h"
#include "StrVec.h"
#include "String.h"
#include "PrintString.h"
#include "ReadString.h"
#include "IntCompare.h"
#include "SmallInt.h"
#include "Quote.h"
#include "Basker.h"
#include "Query.h"

using namespace std;

struct NoDerived {
	virtual int f1(int s = 1) const {
		return 1 + s;
	}
};
struct Base : NoDerived {
	int f1(int s = 10) const override {
		return 2 + NoDerived::f1(s);
	}
};

class Animal {
public:
	void show();
protected:
	int prot_mem;
private:
	int i = 0;
};

class Sneaky : private Animal {
	friend void clobber(Sneaky&);
	friend void clobber(Animal&);
public:
	void test() {};
private:
	int j;
protected:
	int x;
};

void fun(Sneaky& s) {
	s.test();
	//s.show();
}

void clobber(Sneaky& s) {
	s.j = s.prot_mem = s.x = 0;
}
void clobber(Animal& b) {
	//b.i = 3;
	//b.prot_mem = 0;
}

//struct Derived : Base {
//	int f1() const {
//		return 2;
//	}
//};

class BaseAnl {
	friend class Pal;
public:
	size_t size() const { return prot_mem; }
protected:
	int prot_mem = 0;
private:
	int prt_mem = 0;
};

class Anl :public BaseAnl {
public:
	using BaseAnl::prot_mem;
protected:
	int j = 0;
};

class Pal {
public:
	int f(BaseAnl b) { return b.prot_mem; }
	int f2(Anl s) { return s.size(); }
	int f3(Anl s) { return s.prot_mem; }
};

class D2 : public Pal {
public:
	int mem(BaseAnl b) {
		return 2;
	}
};

struct B1 {
	B1() :mem(0) {}
	void memfcn() {
		cout << "b1" << endl;
	}
	virtual ~B1() {
		cout << "~B1" << endl;
	}
protected:
	int mem;
};

struct B2 : B1 {
	B2(int i) :mem(i) {}
	int get_mem() { return mem; }
	void memfcn() {
		cout << "b2" << endl;
	}
	using B1::memfcn;
	void memfcn(string par) {
		cout << par << endl;
	}
	~B2() override {
		cout << "~B2" << endl;
	}
protected:
	int mem;
};

void PassQuote(Bulk_quote bq) {
	cout << "PassQuote" << endl;
}

int main(int argc, char* argv[])
{ 

	Query q = Query("fiery") & Query("bird") | Query("wind");
	 
	ifstream in(argv[1]);
	TextQuery file(in);

	auto result = q.eval(file);

	print(cout, result);

	return 0;
}
