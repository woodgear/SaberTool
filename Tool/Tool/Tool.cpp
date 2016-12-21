#include "Tool.h"
std::wstring Tool::s2ws(const std::string & s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}



Tool::ConsoleLog::ConsoleLog()
{
	AllocConsole();
	m_hOutputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}
Tool::ConsoleLog::~ConsoleLog()
{
	FreeConsole();
}


void Tool::ConsoleLog::writeln(std::string msg)
{
	write(msg);
	write("\n");
}
void Tool::ConsoleLog::write(std::string msg)
{
	DWORD nRet = 0;
	std::wstring stemp = s2ws(msg);
	wcscpy_s(buf, stemp.c_str());
	WriteConsoleW(m_hOutputHandle, buf, lstrlenW(buf), &nRet, NULL);
}

void Tool::FileLog::writeln(std::string msg)
{
	this->write(msg);
	this->write("\n");
}

void Tool::FileLog::write(std::string msg)
{
	std::ofstream os;
	os.open(this->logpath, std::ofstream::app);//T_T
	os << msg;
}

Tool::FileLog::FileLog(std::string path)
{
	this->logpath = path;
}
