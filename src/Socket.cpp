#include <GomokuC/Socket.hpp>

#include <stdexcept>

Socket::Socket()
	: Socket(AddressFamily::IPv4)
{}
Socket::Socket(AddressFamily af)
	: socket_(socket(static_cast<int>(af), SOCK_STREAM, IPPROTO_TCP))
{
	if (socket_ == INVALID_SOCKET)
		throw std::runtime_error("Failed to create a socket.");
}
Socket::Socket(Socket&& socket) noexcept
	: socket_(socket.socket_)
{
	socket.socket_ = INVALID_SOCKET;
}
Socket::~Socket()
{
	disconnect();
}

Socket& Socket::operator=(Socket&& socket) noexcept
{
	socket_ = socket.socket_;
	socket.socket_ = INVALID_SOCKET;

	return *this;
}

void Socket::disconnect() noexcept
{
	if (socket_ != INVALID_SOCKET)
	{
		closesocket(socket_);
	}
}

SOCKET Socket::data() noexcept
{
	return socket_;
}