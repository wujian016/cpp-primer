#pragma once
#include <vector>
#include <string>
#include <memory>
#include <istream>
#include <fstream>
#include <map>
#include <set> 

using std::vector;
using std::string;
using std::shared_ptr;
using std::ifstream;
using std::map;
using std::set;
using std::ostream;

using line_no = vector<string>::size_type;

class QueryResult;

class TextQuery
{
public:
	TextQuery(ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> wm;
};

class QueryResult {
	friend ostream& print(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};
