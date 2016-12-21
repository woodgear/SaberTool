#pragma once
#include <Windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
namespace Tool {

	class ConsoleLog {
	public:

		static ConsoleLog& Instance() {
			static ConsoleLog theSingleton;
			return theSingleton;
		}
		void writeln(std::string msg);
		void write(std::string msg);

	private:
		HANDLE m_hOutputHandle;
		wchar_t buf[1024 * 1024];
		ConsoleLog();
		ConsoleLog(ConsoleLog const&);
		ConsoleLog& operator=(ConsoleLog const&) {};
		~ConsoleLog();
	};

	//TODO 继承 设计模式 共性
	class FileLog {
	public:
		static FileLog& Instance() {
			static FileLog theSingleton;
			return theSingleton;
		}

		void writeln(std::string msg);
		void write(std::string msg);
	private:
		std::string logpath;
		FileLog(std::string path= "C:\\Users\\18754\\Desktop\\log.txt");
		FileLog& operator=(FileLog const&) {};
		~FileLog() {};
	};


	std::wstring s2ws(const std::string& s);
	
	template<typename T>
	void d(T msg) {
		std::string data;
		if (!msg){
			data="NULL";
		}else{
			std::stringstream ss;
			ss<<msg;
			data=ss.str();
		}

		//ConsoleLog::Instance().writeln(data);
		FileLog::Instance().writeln(data);
	}
	template<typename T>
	void d(T msg) {
		std::string data;
		if (!msg){
			data="NULL";
		}else{
			std::stringstream ss;
			ss<<msg;
			data=ss.str();
		}
		//ConsoleLog::Instance().writeln(data);
		FileLog::Instance().writeln(data);
	}
}
