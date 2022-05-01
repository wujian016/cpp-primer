#include "Query_base.h"

QueryResult NotQuery::eval(const TextQuery& t) const {
	return t.query(""); 
}

