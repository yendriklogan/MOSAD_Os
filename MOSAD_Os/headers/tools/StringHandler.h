#pragma once

#include <cstdarg>
#include <cstring>
#include <iostream>
#include <cstdio>

#include "../tools/ParameterValue.h"
#include "../tools/Constantes.h"

#include "../../WindowsRequirements.h"

class DECISIONAID_LIB StringHandler {

private:

public:
	StringHandler();					//configuration file having the values for the requirements

	static int atbegin(const char dest[], const char src[]);
	static int compare(const char src1[], const char src2[]);
	static void copy(char* dest, const char src[]);
	static void concatenate(char* dest, const char src[]);
	static void concatenate(char* dest, long long src);
	static void intToString(int val, char dest[]);
};

