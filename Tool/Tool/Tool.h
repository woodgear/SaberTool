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

		void d(std::string msg);

	private:
		HANDLE m_hOutputHandle;
		wchar_t buf[1024 * 1024];

		void writeln(std::string msg);
		void write(std::string msg);

		ConsoleLog();
		ConsoleLog(ConsoleLog const&);
		ConsoleLog& operator=(ConsoleLog const&) {};
		~ConsoleLog();
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

		//ConsoleLog::Instance().d(data);
		
		std::ofstream os;
		os.open("C:\\Users\\developer\\Desktop\\log.txt",std::ofstream::app);//T_T
		os<<msg<<std::endl;

	}

}
