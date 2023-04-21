#pragma once
#include <Windows.h>
#include <string>
#include <time.h>
#define __FILENAME__ (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1):__FILE__)
#define Log(Leve) Logger::SetColour(Leve);std::cout<<Logger::GetTime()<<"["<<Logger::GetLevel(Leve)<<"/"<<__FILENAME__<<":"<<__LINE__<<"] "
#define Info 0
#define Warning 1
#define Error 2
#define Debug 3
namespace Logger
{
	namespace Level
	{
		const int const_Info = 0;
		const int const_Warning = 1;
		const int const_Error = 2;
		const int const_Debug = 3;
	};
	HWND Init(const char* Title = "Console");
	std::string GetLevel(int LoggerLevel);
	std::string GetTime();
	void SetColour(int LoggerLevel);
}