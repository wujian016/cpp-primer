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
#include "Template_func.h"

using namespace std;

template <typename T>
int compare(const T& v1, const T& v2) {
	if (v1 < v2) return -1;
	if (v1 > v2) return 1;
	return 0;
}

template <typename T, class U> T calc(const T&, const U&);

template<unsigned N, unsigned M>
int compare2(const char(&p1)[N], const char(&p2)[M]) {
	return strcmp(p1, p2);
}

template <typename T>
T foo(T* p) {
	T tmp = *p;
	return tmp;
}

template<typename T> constexpr T man(const T&, const T&);

template<typename I, typename T>
I find2(I b, I e, const T& v) {
	while (b != e && *b != v) {
		b++;
	}
	return b;
}




int main(int argc, char* argv[])
{
	//cout << compare2("h1", "mom") << endl;
	//cout << compare2("h1", "h1") << endl;
	//cout << compare2("mom", "hi") << endl;

	//Sales_data data1, data2;
	//cout << compare(data1, data2) << endl;

	//vector<int> vi = { 0 ,2, 4,6,8,10 };
	//list<string> ls = { "Hello", "world","!" };
	//auto iter = find2(vi.begin(), vi.end(), 6);
	//cout << iter - vi.begin() << endl;

	//auto iter2 = find2(ls.begin(), ls.end(), "world");
	//cout << (iter2 == ls.end()) << endl;

	int a[6] = { 0,2,8,90,7,10 };
	string vs[3] = { "Hello","world","!!!" };
	print2(a);
	print2(vs);
	print_arr(a);

	return 0;
}
