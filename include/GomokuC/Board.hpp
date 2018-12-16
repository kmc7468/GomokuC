#pragma once

#include <GomokuC/Stone.hpp>

#include <vector>

class Board final
{
public:
	class RowIterator final
	{
	public:
		RowIterator(Board* board, int x) noexcept;
		RowIterator(const RowIterator& iterator) noexcept;
		~RowIterator() = default;

	public:
		RowIterator& operator=(const RowIterator& iterator) noexcept;
		bool operator==(const RowIterator& iterator) const noexcept;
		bool operator!=(const RowIterator& iterator) const noexcept;
		Stone& operator[](int y) const noexcept;
		RowIterator operator+(int x) const noexcept;
		RowIterator operator-(int x) const noexcept;
		RowIterator& operator++() noexcept;
		RowIterator operator++(int) noexcept;
		RowIterator& operator--() noexcept;
		RowIterator operator--(int) noexcept;

	private:
		Board* board_;
		int x_;
	};
	class RowConstIterator final
	{
	public:
		RowConstIterator(const Board* board, int x) noexcept;
		RowConstIterator(const RowConstIterator& iterator) noexcept;
		~RowConstIterator() = default;

	public:
		RowConstIterator& operator=(const RowConstIterator& iterator) noexcept;
		bool operator==(const RowConstIterator& iterator) const noexcept;
		bool operator!=(const RowConstIterator& iterator) const noexcept;
		const Stone& operator[](int y) const noexcept;
		RowConstIterator operator+(int x) const noexcept;
		RowConstIterator operator-(int x) const noexcept;
		RowConstIterator& operator++() noexcept;
		RowConstIterator operator++(int) noexcept;
		RowConstIterator& operator--() noexcept;
		RowConstIterator operator--(int) noexcept;

	private:
		const Board* board_;
		int x_;
	};
	class ColumnIterator final
	{
	public:
		ColumnIterator(Board* board, int y) noexcept;
		ColumnIterator(const ColumnIterator& iterator) noexcept;
		~ColumnIterator() = default;

	public:
		ColumnIterator& operator=(const ColumnIterator& iterator) noexcept;
		bool operator==(const ColumnIterator& iterator) const noexcept;
		bool operator!=(const ColumnIterator& iterator) const noexcept;
		Stone& operator[](int x) const noexcept;
		ColumnIterator operator+(int x) const noexcept;
		ColumnIterator operator-(int x) const noexcept;
		ColumnIterator& operator++() noexcept;
		ColumnIterator operator++(int) noexcept;
		ColumnIterator& operator--() noexcept;
		ColumnIterator operator--(int) noexcept;

	private:
		Board* board_;
		int y_;
	};
	class ColumnConstIterator final
	{
	public:
		ColumnConstIterator(const Board* board, int y) noexcept;
		ColumnConstIterator(const ColumnConstIterator& iterator) noexcept;
		~ColumnConstIterator() = default;

	public:
		ColumnConstIterator& operator=(const ColumnConstIterator& iterator) noexcept;
		bool operator==(const ColumnConstIterator& iterator) const noexcept;
		bool operator!=(const ColumnConstIterator& iterator) const noexcept;
		const Stone& operator[](int x) const noexcept;
		ColumnConstIterator operator+(int x) const noexcept;
		ColumnConstIterator operator-(int x) const noexcept;
		ColumnConstIterator& operator++() noexcept;
		ColumnConstIterator operator++(int) noexcept;
		ColumnConstIterator& operator--() noexcept;
		ColumnConstIterator operator--(int) noexcept;

	private:
		const Board* board_;
		int y_;
	};

public:
	Board();
	explicit Board(int size);
	Board(const Board& board);
	Board(Board&& board) noexcept;
	~Board() = default;

public:
	Board& operator=(const Board& board);
	Board& operator=(Board&& board) noexcept;
	bool operator==(const Board& board) = delete;
	bool operator!=(const Board& board) = delete;
	RowConstIterator operator[](int x) const noexcept;
	RowIterator operator[](int x) noexcept;

public:
	const std::vector<Stone>& data() const noexcept;
	std::vector<Stone>& data() noexcept;
	int size() const noexcept;
	int turn() const noexcept;

private:
	std::vector<Stone> stones_;
	int size_ = 15;
	int turn_ = 0;
};