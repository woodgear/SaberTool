#pragma once
#include <Windows.h>
#include <shlobj.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
namespace Tool {

	class IWriter {
	public:
		virtual void write(const std::string&) =0;
		virtual ~IWriter() {};
	};

	class SysConsoleWriter :public IWriter {
		// 通过 IWriter 继承
		virtual void write(const std::string &) override;
		~SysConsoleWriter(){}
	};
	
	std::string getDesktopPath();

	class FileWriter:public IWriter {
	public:
		FileWriter() { this->path = getDesktopPath() + "\\log.txt"; }
		FileWriter(std::string path) { this->path = path; };
		virtual void write(const std::string &) override;
		~FileWriter(){}
	private:
		std::string path;
	};

	//同样也可以用策略模式来做 不过既然只是性能上的优化那就先这样吧
	class Trans {
	public:
		static std::string to_string(int);
		static std::string to_string(float);
		static std::string to_string(double);
		static std::string to_string(long);
		static std::string to_string(const wchar_t*);
		static std::wstring to_wstring(const std::string&);
	};
	
	class InputWrapper {
	public:
		static InputWrapper& Instance() {
			static InputWrapper theSingleton;
			return theSingleton;
		}
		InputWrapper() { setWriter(new FileWriter()); };
		InputWrapper(IWriter *writer);
		void setWriter(IWriter *writer);
		~InputWrapper() {};//FIX 何时或者说是否需要?
		InputWrapper& operator << (const std::string&);
		InputWrapper& operator << (const char*);
		InputWrapper& operator << (const wchar_t*);
		InputWrapper& operator << (int);
	private:
		IWriter *writer;
	};
	InputWrapper d();
}