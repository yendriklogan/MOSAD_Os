#pragma once

#include "pch.h"


#if defined(_MSC_VER)
	#ifdef DECISIONAID_LIB_EXPORTS
		#define DECISIONAID_LIB __declspec(dllexport)
	#else
		#define DECISIONAID_LIB __declspec(dllimport)
	#endif
#else
	#define DECISIONAID_LIB
#endif