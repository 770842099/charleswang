#pragma once
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <limits>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cassert>
#include <queue>
#include "linked_list.h"
#include "TrieTree.h"
//#include <list>
using namespace std;


class LibHelper
{
public:
	template< typename... Args >
	std::string static string_sprintf(const char* format, Args... args) {
		int length = std::snprintf(nullptr, 0, format, args...);
		assert(length >= 0);

		char* buf = new char[length + 1];
		std::snprintf(buf, length + 1, format, args...);

		std::string str(buf);
		delete[] buf;
		return str;
	}

	std::string static replace_string(std::string subject, const std::string& search,
		const std::string& replace) {
		size_t pos = 0;
		while ((pos = subject.find(search, pos)) != std::string::npos) {
			subject.replace(pos, search.length(), replace);
			pos += replace.length();
		}
		return subject;
	}
};

struct Trible
{
	int first;
	int second;
	int three;

	Trible(int _first, int _second, int _three)
	{
		first = _first;
		second = _second;
		three = _three;
	}
};




