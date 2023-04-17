#include <iostream>
#include"Logger/Logger.h"
using namespace std;
int main()
{
    Logger::Init();
	Log(Logger::Debug) << "text" << std::endl;
	Log(Logger::Error) << "text" << std::endl;
	Log(Logger::Warning) << "text" << std::endl;
	Log(Logger::Info) << "text" << std::endl;
}