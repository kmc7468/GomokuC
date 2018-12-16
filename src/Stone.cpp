#include <GomokuC/Stone.hpp>

Stone::Stone(Type type, int turn) noexcept
	: type_(type), turn_(turn)
{}
Stone::Stone(const Stone& stone) noexcept
	: type_(stone.type_), turn_(stone.turn_)
{}

Stone& Stone::operator=(const Stone& stone) noexcept
{
	type_ = stone.type_;
	turn_ = stone.turn_;
	return *this;
}
bool Stone::operator==(const Stone& stone) const noexcept
{
	return type_ == stone.type_ && turn_ == stone.turn_;
}
bool Stone::operator!=(const Stone& stone) const noexcept
{
	return type_ != stone.type_ && turn_ != stone.turn_;
}

Stone::Type Stone::type() const noexcept
{
	return type_;
}
void Stone::type(Type new_type) noexcept
{
	type_ = new_type;
}
int Stone::turn() const noexcept
{
	return turn_;
}
void Stone::turn(int new_turn) noexcept
{
	turn_ = new_turn;
}