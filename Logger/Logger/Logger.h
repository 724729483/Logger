#pragma once
#include <Windows.h>
#define __FILENAME__ (strrchr(__FILE__, '\\') ? (strrchr(__FILE__, '\\') + 1):__FILE__)
#define Log(Leve) Logger::SetColour(Leve);std::cout<<Logger::GetTime()<<"["<<Logger::GetLevel(Leve)<<"/"<<__FILENAME__<<":"<<__LINE__<<"] "
constexpr int Info = 0;
constexpr int Warning = 1;
constexpr int Error = 2;
constexpr int Debug = 3;
namespace Logger
{
	HWND Init(const char* Title = "Console");
	std::string GetLevel(int LoggerLevel);
	std::string GetTime();
	void SetColour(int LoggerLevel);
}