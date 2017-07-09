// Tool.cpp : 定义控制台应用程序的入口点。
//
#include "Tool.h"
#include <cstdlib>
int main()
{
	Log::d("%d %c %s %d", 123, '<', "测试1", 456);
	Log::d("%d %c %s %d", 123, '<', (char*)(L"测试2"), 456);
	system("pause");
    return 0;
}