#include "Tool.h"

Tool::InputWrapper::InputWrapper(IWriter * writer)
{
	setWriter(writer);
}
void Tool::InputWrapper::setWriter(IWriter * writer)
{
	this->writer = writer;
}

Tool::InputWrapper & Tool::InputWrapper::operator<<(const std::string &msg)
{
	this->writer->write(msg);
	return *this;
}

Tool::InputWrapper & Tool::InputWrapper::operator<<(const char *msg)
{
	this->writer->write(msg);
	return *this;
}

Tool::InputWrapper & Tool::InputWrapper::operator<<(const wchar_t *msg)
{
	this->writer->write(Trans::to_string(msg));
	return *this;
}

Tool::InputWrapper & Tool::InputWrapper::operator<<(int msg)
{
	this->writer->write(Trans::to_string(msg));
	return *this;
}

void Tool::SysConsoleWriter::write(const std::string &msg)
{
	std::cout << msg;
}

std::string Tool::Trans::to_string(int data)
{
	std::stringstream ss;
	ss << data;
	return ss.str();
}

std::string Tool::Trans::to_string(float data)
{
	std::stringstream ss;
	ss << data;
	return ss.str();
}

std::string Tool::Trans::to_string(double data)
{
	std::stringstream ss;
	ss << data;
	return ss.str();

}

std::string Tool::Trans::to_string(long data)
{
	std::stringstream ss;
	ss << data;
	return ss.str();
}

std::string Tool::Trans::to_string(const wchar_t *data)
{
	int nLen = WideCharToMultiByte(CP_ACP, 0, data, -1, NULL, 0, NULL, NULL);

	if (nLen <= 0) return std::string("");

	char* pszDst = new char[nLen];
	if (NULL == pszDst) return std::string("NULL");

	WideCharToMultiByte(CP_ACP, 0, data, -1, pszDst, nLen, NULL, NULL);
	pszDst[nLen - 1] = 0;

	std::string strTemp(pszDst);
	delete[] pszDst;
	return strTemp;
}

std::wstring Tool::Trans::to_wstring(const std::string &data)
{
	int len;
	int slength = (int)data.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, data.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, data.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

std::string Tool::getDesktopPath()
{
	static char path[MAX_PATH + 1];
	if (SHGetSpecialFolderPathA(HWND_DESKTOP, path, CSIDL_DESKTOP, FALSE))
		return path;
	else
		return "ERROR";
}

Tool::InputWrapper Tool::d()
{
	return InputWrapper::Instance();
}

void Tool::FileWriter::write(const std::string &data)
{
	std::ofstream os;
	os.open(this->path, std::ofstream::app);//T_T
	os << data;
}