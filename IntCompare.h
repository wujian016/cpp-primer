#pragma once
class IntCompare {
public:
	IntCompare(int v): val(v){}
	bool operator()(int v) {
		return val == v;
	}
private:
	int val;
};

/*
vector<int> vec = { 1,2,3,2,1 };
	const int newValue = 200;
	IntCompare icmp(2);
	std::replace_if(vec.begin(), vec.end(), icmp, newValue);
*/