#pragma once

#include <WinSock2.h>

enum class AddressFamily
{
	IPv4 = AF_INET,
	IPv6 = AF_INET6,
};

class Socket final
{
public:
	Socket();
	explicit Socket(AddressFamily af);
	Socket(const Socket& socket) = delete;
	Socket(Socket&& socket) noexcept;
	~Socket();

public:
	Socket& operator=(const Socket& socket) = delete;
	Socket& operator=(Socket&& socket) noexcept;
	bool operator==(const Socket& socket) = delete;
	bool operator!=(const Socket& socket) = delete;

public:
	void disconnect() noexcept;

public:
	SOCKET data() noexcept;

private:
	SOCKET socket_ = INVALID_SOCKET;
};