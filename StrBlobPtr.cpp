//#include "StrBlobPtr.h"
//#include <stdexcept>
//
//using std::string;
//using std::initializer_list;
//using std::vector;
//using std::make_shared;
//using std::shared_ptr;
//using std::weak_ptr;
//
//shared_ptr<vector<string>> StrBlobPtr::check(std::size_t i, const string& msg) const {
//	auto ret = wptr.lock();
//	if (!ret) {
//		throw std::runtime_error("unbound StrBlobPtr");
//	}
//	if (i >= ret->size()) {
//		throw std::out_of_range(msg);
//	}
//	return ret;
//}
//
//string& StrBlobPtr::deref() const {
//	auto p = check(curr, "dereference past end");
//	return (*p)[curr];
//}
//
//StrBlobPtr& StrBlobPtr::incr() {
//	check(curr, "Increment past end of StrBlobPtr");
//	++curr;
//	return *this;
//}