#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdarg.h>
#include <shlobj.h>
#include <iostream>
#include <fstream>
#include <string>

namespace Trans{
	std::wstring s2w(const std::string str)
{// stringתwstring
	unsigned len = str.size() * 2;// Ԥ���ֽ���
	setlocale(LC_CTYPE, "");     //������ô˺���
	wchar_t *p = new wchar_t[len];// ����һ���ڴ���ת������ַ���
	mbstowcs(p,str.c_str(),len);// ת��
	std::wstring str1(p);
	delete[] p;// �ͷ�������ڴ�
	return str1;
}

std::string w2s(const std::wstring& ws)
{// wstringתstring
	std::string curLocale = setlocale(LC_ALL, NULL);        // curLocale = "C";
	setlocale(LC_ALL, "chs");
	const wchar_t* _Source = ws.c_str();
	size_t _Dsize = 2 * ws.size() + 1;
	char *_Dest = new char[_Dsize];
	memset(_Dest, 0, _Dsize);
	wcstombs(_Dest, _Source, _Dsize);
	std::string result = _Dest;
	delete[]_Dest;
	setlocale(LC_ALL, curLocale.c_str());
	return result;
}

}
namespace Log {
	
	 std::string getCurrentDir() {
		 char buffer[MAX_PATH];
		 GetModuleFileNameA(NULL, buffer, MAX_PATH);
		 std::string::size_type pos = std::string(buffer).find_last_of("\\/");
		 return std::string(buffer).substr(0, pos);
	 }
	 std::string getLogPath() {
		 return getCurrentDir() + "\\Log.txt";
	 }
	 std::wofstream out();
	void write(const char*msg, const std::string path) {
		std::cout << path << " a \n";

		std::ofstream os;
		os.open(path, std::ofstream::app);//T_T
		os << msg << std::endl;
	}

	void write_w(const wchar_t*msg, const std::string path) {
		std::cout << path << " w \n";
		std::wofstream os;
		os.open(path, std::ofstream::app);//T_T
		os << msg << std::endl;
	}

	 void d(const char*format, ...) {
		va_list args;
		int len;
		char * buffer;
		va_start(args, format);
		len = _vscprintf(format, args) + 1;
		buffer = (char*)malloc(len * sizeof(char));
		vsprintf_s(buffer, len, format, args);
		write(buffer, getLogPath());
		free(buffer);
	}

	 void d(const wchar_t*format, ...) {
		va_list args;
		std::cout << "=================  " << std::endl;

		int len;
		wchar_t * buffer;
		va_start(args, format);
		len = _vscwprintf(format, args) + 1;
		std::cout << len<<"\n";
		buffer = (wchar_t*)malloc(len * sizeof(wchar_t));
		vswprintf_s(buffer, len, format, args);
		std::wcout << buffer << "\n";
		write_w(buffer, getLogPath());
		free(buffer);
	}
}