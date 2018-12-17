#pragma once

#include <cstdint>
#include <string>
#include <WinSock2.h>

enum class AddressFamily : ADDRESS_FAMILY
{
	None,
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
	void connect(const std::string& address, std::uint16_t port);
	void disconnect() noexcept;
	void send(const void* buffer, int size);
	int receive(void* buffer, int size);

public:
	SOCKET data() noexcept;
	AddressFamily address_family() const noexcept;

private:
	SOCKET socket_ = INVALID_SOCKET;
	AddressFamily address_family_ = AddressFamily::None;
};