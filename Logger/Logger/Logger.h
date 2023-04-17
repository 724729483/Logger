#pragma once
#include <Windows.h>
#define __FILENAME__ (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1):__FILE__)
#define Log(Leve) std::cout<<Logger::GetTime()<<"["<<Logger::GetLevel(Leve)<<"/"<<__FILENAME__<<":"<<__LINE__<<"] "
namespace Logger
{
	enum Level
	{
		Info,
		Warning,
		Error,
		Debug,
	};
	HWND Init(const char* Title = "Console");
	std::string GetLevel(Logger::Level LoggerLevel);
	std::string GetTime();
}