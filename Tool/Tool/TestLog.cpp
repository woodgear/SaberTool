// Tool.cpp : 定义控制台应用程序的入口点。
//

#include "Tool.h"

int main()
{
	Log::d("%d %c %s %d", 123, '<', "测试", 456);
	system("pause");
    return 0;
}

