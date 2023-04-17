#include <iostream>
#include <Windows.h>
#include "Logger.h"
namespace Logger
{
	FILE* stdin_stream;
	FILE* stdout_stream;
	FILE* stderr_stream;
	HWND Init(const char* Title)
	{
		AllocConsole();
		freopen_s(&stdin_stream, "CONIN$", "r", stdin);
		freopen_s(&stdout_stream, "CONOUT$", "w", stdout);
		freopen_s(&stderr_stream, "CONOUT$", "w", stderr);
		SetConsoleTitleA(Title);
		ShowWindow(GetConsoleWindow(), SW_SHOW);
		return GetConsoleWindow();
	}
	std::string GetLevel(Logger::Level LoggerLevel)
	{
		switch (LoggerLevel)
		{
		case Level::Info:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			return "Info";
		case Level::Warning:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			return "Warning";
		case Level::Error:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			return "Error";
		case Level::Debug:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
			return "Debug";
		default:
			return "";
		}
	}
	std::string GetTime()
	{
		time_t Time = time(0);
		struct tm _Tm;
		char TimeText[1024];
		localtime_s(&_Tm, &Time);
		strftime(TimeText, sizeof(TimeText), "[%Y-%m-%d %H:%M:%S]", &_Tm);
		return TimeText;
	}
}