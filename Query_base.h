#pragma once
#include "TextQuery.h"
#include <string>
#include "Query.h"

//extern class Query;

class Query_base
{
	friend class Query;
protected:
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

class WordQuery : public Query_base {
	friend class Query;
	WordQuery(const std::string &s): query_word(s){}

	QueryResult eval(const TextQuery& t) const override {
		return t.query(query_word);
	}
	std::string rep() const override { return query_word; }
	std::string query_word;
};

class NotQuery : public Query_base { 
	friend Query operator~(const Query&);
	NotQuery(const Query &q):query(q){}
	QueryResult eval(const TextQuery& t) const override;
	std::string rep() const  override{ return "~(" + query.rep() + ")"; } 
	Query query;
};

inline
Query operator~(const Query& operand) {
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

