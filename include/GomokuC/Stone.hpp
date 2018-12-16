#pragma once

class Stone final
{
public:
	enum Type
	{
		Empty,
		Black,
		White,
	};

public:
	Stone() noexcept = default;
	Stone(Type type, int turn) noexcept;
	Stone(const Stone& stone) noexcept;
	~Stone() = default;

public:
	Stone& operator=(const Stone& stone) noexcept;
	bool operator==(const Stone& stone) const noexcept;
	bool operator!=(const Stone& stone) const noexcept;

public:
	Type type() const noexcept;
	void type(Type new_type) noexcept;
	int turn() const noexcept;
	void turn(int new_turn) noexcept;

private:
	Type type_ = Empty;
	int turn_ = 0;
};

using StoneType = Stone::Type;