#pragma once
#include <Windows.h>
#include <shlobj.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
namespace Tool {
	//log path ==desktop path
	static const std::string  getLogPath() {
		static char path[MAX_PATH + 1];
		if (SHGetSpecialFolderPathA(HWND_DESKTOP, path, CSIDL_DESKTOP, FALSE))
			return path;
		else
			return "C:\\log";
	}
	
	class Trans {
	public:

		static std::string to_string(const std::string &msg) {
			return msg;
		}

		static std::string to_string(int msg) {
			return std::to_string(msg);
		}

		static std::string to_string(unsigned int  msg) {
			return std::to_string(msg);
		}

		static std::string to_string(long msg) {
			return std::to_string(msg);
		}

		static std::string to_string(unsigned long  msg) {
			return std::to_string(msg);
		}

		static std::string to_string(long long msg) {
			return std::to_string(msg);
		}

		static std::string to_string(unsigned long long  msg) {
			return std::to_string(msg);
		}

		static std::string to_string(float msg) {
			return std::to_string(msg);
		}

		static std::string to_string(double msg) {
			return std::to_string(msg);
		}

		static std::string to_string(long double msg) {
			return std::to_string(msg);
		}

		static std::string to_string(const wchar_t * msg) {
			int nLen = WideCharToMultiByte(CP_ACP, 0, msg, -1, NULL, 0, NULL, NULL);

			if (nLen <= 0) return std::string("");

			char* pszDst = new char[nLen];
			if (NULL == pszDst) return std::string("NULL");

			WideCharToMultiByte(CP_ACP, 0, msg, -1, pszDst, nLen, NULL, NULL);
			pszDst[nLen - 1] = 0;

			std::string strTemp(pszDst);
			delete[] pszDst;
			return strTemp;

		}

		static std::wstring to_wstring(const std::string &msg) {
			int len;
			int slength = (int)msg.length() + 1;
			len = MultiByteToWideChar(CP_ACP, 0, msg.c_str(), slength, 0, 0);
			wchar_t* buf = new wchar_t[len];
			MultiByteToWideChar(CP_ACP, 0, msg.c_str(), slength, buf, len);
			std::wstring wmsg(buf);
			delete[] buf;
			return wmsg;
		}

	};

	template<typename T> void d(T data) {
		std::string path = getLogPath() + "\\log.txt";
		std::ofstream out(path,std::ofstream::app);
		out << Trans::to_string(data) << std::endl;
		out.close();
	}
}