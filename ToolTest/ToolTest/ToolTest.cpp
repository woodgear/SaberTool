// ToolTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tool.h"
int _tmain(int argc, _TCHAR* argv[])
{
	int b = 100;
	std::string str = "123";
	Tool::d() << b << " " << str << " " << NULL << "²âÊÔ" << "\n";
	return 0;
}

