#pragma once

#include "OutrankingModel.h"
#include "../../tools/Dominance.h"
#include "../../instances/Instance_PDTLZ1.h"
#include "../../problems/standard/preference/PDTLZ1.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB FDEA_Outranking : public OutrankingModel {

private:
	int* coalition;		 //identifica las coaliciones, 1 - coalicion de concordancia, -1 - coalicion de discordancia, 0 - neutro
	int size_coalition;

	Interval last_cxy;	//credibility index
	Interval last_cyx;	//credibility index

	Interval concordance_XY;
	Interval concordance_YX;

	bool xPy;
	bool yPx;

	Interval concordance_index(bool* hay_discordancia, Interval s1[], Interval s2[], int num_objs);

public:
	FDEA_Outranking();
	FDEA_Outranking(Problem* problem_, Parameters* param);

	void initialize(Requirements* config) override;

	int outranking(Interval o1[], Interval o2[]) override;
	int outranking(Solution* o1, Solution* o2) override;
	Interval getLastCredibilityIndex_XY() override;
	Interval getLastCredibilityIndex_YX() override;

	Interval getCredibilityThreshold() override;

	virtual bool getStrictPreference_XY();
	virtual bool getStrictPreference_YX();

	virtual Interval getConcordanceIndex_XY();
	virtual Interval getConcordanceIndex_YX();
};
