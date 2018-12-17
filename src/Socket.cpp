#include <GomokuC/Socket.hpp>

#include <WS2tcpip.h>

#include <cassert>
#include <stdexcept>

Socket::Socket()
	: Socket(AddressFamily::IPv4)
{}
Socket::Socket(AddressFamily af)
	: address_family_(af)
{
	assert(af == AddressFamily::IPv4 || af == AddressFamily::IPv6);

	socket_ = socket(static_cast<ADDRESS_FAMILY>(af), SOCK_STREAM, IPPROTO_TCP);
	
	if (socket_ == INVALID_SOCKET)
		throw std::runtime_error("Failed to create a socket.");
}
Socket::Socket(Socket&& socket) noexcept
	: socket_(socket.socket_), address_family_(socket.address_family_)
{
	socket.socket_ = INVALID_SOCKET;
	socket.address_family_ = AddressFamily::None;
}
Socket::~Socket()
{
	disconnect();
}

Socket& Socket::operator=(Socket&& socket) noexcept
{
	socket_ = socket.socket_;
	socket.socket_ = INVALID_SOCKET;
	socket.address_family_ = AddressFamily::None;

	return *this;
}

void Socket::connect(const std::string& address, std::uint16_t port)
{
	assert(socket_ == INVALID_SOCKET);
	assert(!address.empty());

	ADDRINFO hint, *info = nullptr;
	hint.ai_family = static_cast<ADDRESS_FAMILY>(address_family_);
	hint.ai_socktype = SOCK_STREAM;

	const std::string port_str = std::to_string(port);
	if (getaddrinfo(address.data(), port_str.data(), &hint, &info))
		throw std::runtime_error("Failed to call getaddrinfo function.");

	SOCKET socket = INVALID_SOCKET;

	for (ADDRINFO* iter = info; iter; iter = iter->ai_next)
	{
		socket = ::socket(iter->ai_family, iter->ai_socktype, iter->ai_protocol);
		if (socket == INVALID_SOCKET) continue;
		if (::connect(socket, iter->ai_addr, static_cast<int>(iter->ai_addrlen)) != SOCKET_ERROR) break;

		closesocket(socket);
	}

	freeaddrinfo(info);
	if (socket == INVALID_SOCKET)
		throw std::runtime_error("Failed to connect to the server.");

	socket_ = socket;
}
void Socket::disconnect() noexcept
{
	if (socket_ != INVALID_SOCKET)
	{
		closesocket(socket_);

		socket_ = INVALID_SOCKET;
		address_family_ = AddressFamily::None;
	}
}

SOCKET Socket::data() noexcept
{
	return socket_;
}
AddressFamily Socket::address_family() const noexcept
{
	return address_family_;
}