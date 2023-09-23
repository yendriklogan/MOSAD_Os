#pragma once

#include "../../WindowsRequirements.h"

class Solution;

class DECISIONAID_LIB Set {
	public:
		//virtual ~Set();
		virtual int size() = 0;
		virtual void add(Solution sol) = 0;
		virtual void remove_by_last(int pos) = 0;
		virtual Solution get(int pos) = 0;
		virtual void set(int pos, Solution sol) = 0;
		virtual void clear() = 0;
};
