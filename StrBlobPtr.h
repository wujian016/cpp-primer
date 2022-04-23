//#pragma once
//#include "StrBlob.h"
//#include <vector>
//#include <string>
//#include <memory>
//using std::string;
//using std::initializer_list;
//using std::vector;
//using std::make_shared;
//
//class StrBlobPtr
//{
//public: 
//	StrBlobPtr() : curr(0) {};
//	StrBlobPtr(StrBlob &a, size_t sz = 0): wptr(a.data), curr(sz){ };
//	std::string& deref() const;
//	StrBlobPtr& incr();
//
//private: 
//	std::shared_ptr<std::vector<std::string>> check(std::size_t i, const std::string& msg) const;
//	std::weak_ptr<vector<string>> wptr;
//	std::size_t curr;
//};