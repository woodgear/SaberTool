#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdarg.h>
#include <shlobj.h>

namespace Log {
	inline void write(const char*msg) {
		std::ofstream os;
		os.open("C:\\Users\\18754\\Desktop\\log.txt", std::ofstream::app);//T_T
		os << msg << std::endl;
	}

	inline void d(const char*format, ...) {
		va_list args;
		int len;
		char * buffer;
		va_start(args, format);
		len = _vscprintf(format, args)+ 1;
		buffer = (char*)malloc(len * sizeof(char));
		vsprintf_s(buffer, len, format, args);
		write(buffer);
		free(buffer);
	}
}