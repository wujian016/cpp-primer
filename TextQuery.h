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
	//typedef std::vector<std::string>::size_type line_no;
	typedef std::set<line_no>::const_iterator line_it;
	QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f) : sought(s), lines(p), file(f) {}
	std::set<line_no>::size_type size() const { return lines->size(); }
	line_it begin() const { return lines->cbegin(); }
	line_it end() const { return lines->cend(); }
	std::shared_ptr<std::vector<std::string>> get_file() { return file; }
private:
	string sought;
	shared_ptr<set<line_no>> lines;
	shared_ptr<vector<string>> file;
};
