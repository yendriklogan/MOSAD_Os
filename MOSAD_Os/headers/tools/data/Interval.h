#pragma once

#include <iostream>
#include <cmath>

#include "../../../WindowsRequirements.h"

using namespace std;

class DECISIONAID_LIB Interval {
	public:
		static const int ENTERO = 0x01;
		static const int DECIMAL = 0x03;
		static const int INTERVALO = 0x07;

	private:
		int order_relation(double L, double U);


	public:
		double PossGTE;
		double PossSTE;

		double L;
		double U;

		Interval();
		Interval(double d);
		Interval(double L, double U);
		~Interval();

		Interval operator +(const Interval& val);
		Interval operator +(const double& val);
		Interval operator -(const Interval& val);
		Interval operator -(const double& val);
		Interval operator *(const Interval& val);
		Interval operator *(const double& val);
		Interval operator /(const Interval& val);
		Interval operator /(const double& val);

		bool operator >(const Interval& val);
		bool operator >(const double& val);
		bool operator >=(const Interval& val);
		bool operator >=(const double& val);
		bool operator <(const Interval& val);
		bool operator <(const double& val);
		bool operator <=(const Interval& val);
		bool operator <=(const double& val);
		bool operator ==(const Interval& val);
		bool operator ==(const double& val);

		Interval operator %(const double& op);
		
		Interval operator =(const double& val);

		DECISIONAID_LIB friend ostream& operator<<(ostream& os, const Interval& dt);
		DECISIONAID_LIB friend Interval pow(Interval op1, double op2);
		DECISIONAID_LIB friend Interval pow(Interval op1, Interval op2);
		DECISIONAID_LIB friend Interval exp(Interval op);
		DECISIONAID_LIB friend Interval sqrt(Interval op);
		DECISIONAID_LIB friend Interval sqrt(Interval op);
		DECISIONAID_LIB friend Interval iabs(Interval op);
		DECISIONAID_LIB friend Interval acos(Interval op);
		//----------operadores agregados JMVM--------
		DECISIONAID_LIB friend Interval log(Interval op);
		DECISIONAID_LIB friend Interval abs(Interval op);
		//------------------------------------------
};