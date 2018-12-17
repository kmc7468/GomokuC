#include <GomokuC/Application.hpp>

#include <WinSock2.h>

bool Application::run()
{
	WSADATA data;
	return WSAStartup(MAKEWORD(2, 2), &data) == 0;
}
void Application::exit()
{
	WSACleanup();
}