// ToolTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Tool.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout<<"start ToolTest"<<std::endl;
	Tool::d("²âÊÔ1");
	Tool::d("abc");
	Tool::d("²âÊÔ2");

	std::cin.get();
	return 0;
}

