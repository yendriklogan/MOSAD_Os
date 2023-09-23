#pragma once

#include "Set.h"
#include "Solution.h"

#include "../../WindowsRequirements.h"

class Problem;
class Solution;

class DECISIONAID_LIB SolutionSet : public Set {
	private:
		Problem* problem_;
		Solution* elements;
		int MaxElements;
		int num_sol;

	public:
		SolutionSet();
		SolutionSet(int MaxElements, Problem* problem);
		SolutionSet(int MaxElements, int InitialElements, Problem* problem);
		void initialize(int MaxElements, Problem* problem);
		void initialize(int MaxElements, int InitialElements, Problem* problem);

		//overriden methods
		int size() override;
		void add(Solution sol) override;
		void remove_by_last(int pos) override;
		Solution get(int pos) override;
		Solution* getptr(int pos);
		void set(int pos, Solution sol);
		void clear() override;
		
		int dominance_add(Solution sol);
		Problem* getProblem();
		bool contains(Solution o);		

		SolutionSet operator=(const SolutionSet& op);

		static void set_union(SolutionSet D, SolutionSet A, SolutionSet B);
		static void set_concatenate(SolutionSet& D, SolutionSet& S);
		static SolutionSet set_union(SolutionSet A, SolutionSet B);
		static void dominance_union(SolutionSet& A, SolutionSet& B);

		DECISIONAID_LIB friend ostream& operator<<(ostream& os, const SolutionSet& dt);
};