#pragma once
#include <string>
 

// return the plural version of word if ctr is greater than 1
inline
string make_plural(size_t ctr, const string& word,
	const string& ending)
{
	return (ctr > 1) ? word + ending : word;
}
