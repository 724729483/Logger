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
			return "Info";
		case Level::Warning:
			return "Warning";
		case Level::Error:
			return "Error";
		case Level::Debug:
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
	void SetColour(Logger::Level LoggerLevel)
	{
		switch (LoggerLevel)
		{
		case Level::Info:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			return;
		case Level::Warning:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			return;
		case Level::Error:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			return;
		case Level::Debug:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
			return;
		default:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			return;
		}
		return;
	}
}