#include <GomokuC/Client.hpp>

#include <GomokuC/Application.hpp>
#include <GomokuC/Exception.hpp>

#include <cstddef>
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

	// 버전 정보 송신
	std::uint64_t buffer64 = 0;
	*reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::uint8_t*>(&buffer64)) = htons(GOMOKUC_MAJOR);
	*reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::uint8_t*>(&buffer64) + 2) = htons(GOMOKUC_MINOR);
	*reinterpret_cast<std::uint16_t*>(reinterpret_cast<std::uint8_t*>(&buffer64) + 4) = htons(GOMOKUC_PATCH);
	socket_.send(&buffer64, sizeof(buffer64));

	// 프로토콜 호환 여부 수신
	std::uint32_t buffer32 = 0;
	socket_.receive(&buffer32, sizeof(buffer32));
	buffer32 = ntohl(buffer32);

	if (buffer32 == 0xFFFF0000 || buffer32 == 0xFFFF0001)
	{
		socket_.disconnect();
		throw NoCompatibleProtocol("Outdated client.");
	}

	// TODO
}
void Client::disconnect()
{
	// TODO: 데이터 교환

	socket_.disconnect();
	id_ = 0;
}