#include <GomokuC/Client.hpp>

#include <stdexcept>
#include <utility>

Client::Client(AddressFamily af)
	: socket_(af)
{}
Client::Client(Client&& client) noexcept
	: socket_(std::move(client.socket_)), id_(client.id_)
{
	client.id_ = 0;
}

Client& Client::operator=(Client&& client) noexcept
{
	socket_ = std::move(client.socket_);
	id_ = client.id_;

	client.id_ = 0;

	return *this;
}

void Client::connect(const std::string& address, std::uint16_t port)
{
	socket_.connect(address, port);

	// TODO: 데이터 교환
}
void Client::disconnect()
{
	// TODO: 데이터 교환

	socket_.disconnect();
	id_ = 0;
}