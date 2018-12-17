#pragma once

#include <GomokuC/Socket.hpp>

#include <cstdint>
#include <string>
#include <WinSock2.h>

class Client final
{
public:
	Client() = default;
	explicit Client(AddressFamily af);
	Client(const Client& client) = delete;
	Client(Client&& client) noexcept;
	~Client() = default;

public:
	Client& operator=(const Client& client) = delete;
	Client& operator=(Client&& client) noexcept;
	bool operator==(const Client& client) = delete;
	bool operator!=(const Client& client) = delete;

public:
	void connect(const std::string& address, std::uint16_t port);
	void disconnect();

private:
	Socket socket_;
	std::uint32_t id_ = 0;
};