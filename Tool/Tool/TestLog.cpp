// Tool.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "Tool.h"
#include <cstdlib>
int main()
{
	Log::d("%d %c %s %d", 123, '<', "����1", 456);
	Log::d("%d %c %s %d", 123, '<', (char*)(L"����2"), 456);
	system("pause");
    return 0;
}