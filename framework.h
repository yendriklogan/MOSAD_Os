#pragma once

#define WIN32_LEAN_AND_MEAN             // Excluir material rara vez utilizado de encabezados de Windows
// Archivos de encabezado de Windows
#define NOMINMAX

#if defined(_WIN64) 
	#include <windows.h>
#else
	#if defined(_WIN32)
		#include <windows.h>
	#endif
#endif 
