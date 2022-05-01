#pragma once
#include "TextQuery.h"
#include <memory>


class Query_base
{
	friend class Query;
protected:
	virtual ~Query_base() = default;
private:
	virtual QueryResult eval(const TextQuery&) const = 0;
	virtual std::string rep() const = 0;
};

class Query
{
	friend Query operator~(const Query&);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);
public:
	Query(const std::string&);
	QueryResult eval(const TextQuery& t) const {
		return q->eval(t);
	}
	std::string rep() const {
		return q->rep();
	}

private:
	Query(std::shared_ptr<Query_base> query) : q(query) {}
	std::shared_ptr<Query_base> q;
};


Query operator~(const Query&);
Query operator|(const Query&, const Query&);
Query operator&(const Query&, const Query&);

class WordQuery : public Query_base {
	friend class Query;
	WordQuery(const std::string& s) : query_word(s) {}

	QueryResult eval(const TextQuery& t) const override;
	std::string rep() const override { return query_word; }
	std::string query_word;
};

class NotQuery : public Query_base {
	friend Query operator~(const Query&);
	NotQuery(const Query& q) :query(q) {}
	QueryResult eval(const TextQuery& t) const override;
	std::string rep() const  override { return "~(" + query.rep() + ")"; }
	Query query;
};

class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query& l, const Query& r, std::string s) : lhs(l), rhs(r), opSym(s) { }
	std::string rep() const {
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}
	Query lhs, rhs;
	std::string opSym;
};

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);
	AndQuery(const Query& left, const Query& right) : BinaryQuery(left, right, "&") {}
	QueryResult eval(const TextQuery&) const override;
};


class OrQuery : public BinaryQuery {
	friend Query operator | (const Query&, const Query&);
	OrQuery(const Query& left, const Query& right) :
		BinaryQuery(left, right, "|") {}
	QueryResult eval(const TextQuery&) const;
};


inline
std::ostream& operator << (std::ostream& os, const Query& query) {
	return os << query.rep();
}

