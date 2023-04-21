#include <Windows.h>
#include <string>
#include <time.h>
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
	std::string GetLevel(int LoggerLevel)
	{
		switch (LoggerLevel)
		{
		case 0:
			return "Info";
		case 1:
			return "Warning";
		case 2:
			return "Error";
		case 3:
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
	void SetColour(int LoggerLevel)
	{
		switch (LoggerLevel)
		{
		case 0:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			return;
		case 1:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x06);
			return;
		case 2:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x04);
			return;
		case 3:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x0b);
			return;
		default:
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0x07);
			return;
		}
		return;
	}
}