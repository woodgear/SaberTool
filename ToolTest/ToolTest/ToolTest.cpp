// ToolTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Tool.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout<<"start ToolTest"<<std::endl;
	Tool::d("����1");
	Tool::d("abc");
	Tool::d("����2");

	std::cin.get();
	return 0;
}

