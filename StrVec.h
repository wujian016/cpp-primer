#pragma once
#include <memory>
#include <string>
#include <utility>

using std::string;
using std::allocator;
using std::pair;

class StrVec
{
public:
	StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr){}
	StrVec(std::initializer_list<string>);
	StrVec(const StrVec&);
	StrVec(StrVec&&) noexcept;
	StrVec& operator=(const StrVec&);
	StrVec& operator=(StrVec&&) noexcept;
	StrVec& operator=(std::initializer_list<string>);
	string& operator[](size_t n);
	const string& operator[](size_t n) const;
	~StrVec();
	void push_back(const string&);
	void push_back(string&&);
	size_t size() const {
		return first_free - elements;
	}
	size_t capacity() const {
		return cap - elements;
	}
	string* begin() const {
		return elements;
	}
	string* end() const {
		return first_free;
	}
	void resize(size_t n);
	void resize(size_t n,const string &s);
private:
	 std::allocator<std::string> alloc;
	void chk_n_alloc() {
		if (size() == capacity()) {
			reallocate();
		}
	}
	pair<string*, string*> alloc_n_copy(const string*, const string*);
	void free();
	void reallocate();
	string* elements;
	string* first_free;
	string* cap;
};

