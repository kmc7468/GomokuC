#include <GomokuC/Board.hpp>

#include <cassert>
#include <utility>

Board::RowIterator::RowIterator(Board* board, int x) noexcept
	: board_(board), x_(x)
{}
Board::RowIterator::RowIterator(const RowIterator& iterator) noexcept
	: board_(iterator.board_), x_(iterator.x_)
{}

Board::RowIterator& Board::RowIterator::operator=(const RowIterator& iterator) noexcept
{
	board_ = iterator.board_;
	x_ = iterator.x_;

	return *this;
}
bool Board::RowIterator::operator==(const RowIterator& iterator) const noexcept
{
	return board_ == iterator.board_ && x_ == iterator.x_;
}
bool Board::RowIterator::operator!=(const RowIterator& iterator) const noexcept
{
	return board_ != iterator.board_ || x_ != iterator.x_;
}
Stone& Board::RowIterator::operator[](int y) const noexcept
{
	return board_->data()[y * board_->size() + x_];
}
Board::RowIterator Board::RowIterator::operator+(int x) const noexcept
{
	return { board_, x_ + x };
}
Board::RowIterator Board::RowIterator::operator-(int x) const noexcept
{
	return { board_, x_ - x };
}
Board::RowIterator& Board::RowIterator::operator++() noexcept
{
	++x_;
	return *this;
}
Board::RowIterator Board::RowIterator::operator++(int) noexcept
{
	const RowIterator temp = *this;
	return ++x_, temp;
}
Board::RowIterator& Board::RowIterator::operator--() noexcept
{
	--x_;
	return *this;
}
Board::RowIterator Board::RowIterator::operator--(int) noexcept
{
	const RowIterator temp = *this;
	return --x_, temp;
}

Board::RowConstIterator::RowConstIterator(const Board* board, int x) noexcept
	: board_(board), x_(x)
{}
Board::RowConstIterator::RowConstIterator(const RowConstIterator& iterator) noexcept
	: board_(iterator.board_), x_(iterator.x_)
{}

Board::RowConstIterator& Board::RowConstIterator::operator=(const RowConstIterator& iterator) noexcept
{
	board_ = iterator.board_;
	x_ = iterator.x_;

	return *this;
}
bool Board::RowConstIterator::operator==(const RowConstIterator& iterator) const noexcept
{
	return board_ == iterator.board_ && x_ == iterator.x_;
}
bool Board::RowConstIterator::operator!=(const RowConstIterator& iterator) const noexcept
{
	return board_ != iterator.board_ || x_ != iterator.x_;
}
const Stone& Board::RowConstIterator::operator[](int y) const noexcept
{
	return board_->data()[y * board_->size() + x_];
}
Board::RowConstIterator Board::RowConstIterator::operator+(int x) const noexcept
{
	return { board_, x_ + x };
}
Board::RowConstIterator Board::RowConstIterator::operator-(int x) const noexcept
{
	return { board_, x_ - x };
}
Board::RowConstIterator& Board::RowConstIterator::operator++() noexcept
{
	++x_;
	return *this;
}
Board::RowConstIterator Board::RowConstIterator::operator++(int) noexcept
{
	const RowConstIterator temp = *this;
	return ++x_, temp;
}
Board::RowConstIterator& Board::RowConstIterator::operator--() noexcept
{
	--x_;
	return *this;
}
Board::RowConstIterator Board::RowConstIterator::operator--(int) noexcept
{
	const RowConstIterator temp = *this;
	return --x_, temp;
}

Board::ColumnIterator::ColumnIterator(Board* board, int y) noexcept
	: board_(board), y_(y)
{}
Board::ColumnIterator::ColumnIterator(const ColumnIterator& iterator) noexcept
	: board_(iterator.board_), y_(iterator.y_)
{}

Board::ColumnIterator& Board::ColumnIterator::operator=(const ColumnIterator& iterator) noexcept
{
	board_ = iterator.board_;
	y_ = iterator.y_;

	return *this;
}
bool Board::ColumnIterator::operator==(const ColumnIterator& iterator) const noexcept
{
	return board_ == iterator.board_ && y_ == iterator.y_;
}
bool Board::ColumnIterator::operator!=(const ColumnIterator& iterator) const noexcept
{
	return board_ != iterator.board_ || y_ != iterator.y_;
}
Stone& Board::ColumnIterator::operator[](int x) const noexcept
{
	return board_->data()[y_ * board_->size() + x];
}
Board::ColumnIterator Board::ColumnIterator::operator+(int y) const noexcept
{
	return { board_, y_ + y };
}
Board::ColumnIterator Board::ColumnIterator::operator-(int y) const noexcept
{
	return { board_, y_ - y };
}
Board::ColumnIterator& Board::ColumnIterator::operator++() noexcept
{
	++y_;
	return *this;
}
Board::ColumnIterator Board::ColumnIterator::operator++(int) noexcept
{
	const ColumnIterator temp = *this;
	return ++y_, temp;
}
Board::ColumnIterator& Board::ColumnIterator::operator--() noexcept
{
	--y_;
	return *this;
}
Board::ColumnIterator Board::ColumnIterator::operator--(int) noexcept
{
	const ColumnIterator temp = *this;
	return --y_, temp;
}

Board::ColumnConstIterator::ColumnConstIterator(const Board* board, int y) noexcept
	: board_(board), y_(y)
{}
Board::ColumnConstIterator::ColumnConstIterator(const ColumnConstIterator& iterator) noexcept
	: board_(iterator.board_), y_(iterator.y_)
{}

Board::ColumnConstIterator& Board::ColumnConstIterator::operator=(const ColumnConstIterator& iterator) noexcept
{
	board_ = iterator.board_;
	y_ = iterator.y_;

	return *this;
}
bool Board::ColumnConstIterator::operator==(const ColumnConstIterator& iterator) const noexcept
{
	return board_ == iterator.board_ && y_ == iterator.y_;
}
bool Board::ColumnConstIterator::operator!=(const ColumnConstIterator& iterator) const noexcept
{
	return board_ != iterator.board_ || y_ != iterator.y_;
}
const Stone& Board::ColumnConstIterator::operator[](int x) const noexcept
{
	return board_->data()[y_ * board_->size() + x];
}
Board::ColumnConstIterator Board::ColumnConstIterator::operator+(int y) const noexcept
{
	return { board_, y_ + y };
}
Board::ColumnConstIterator Board::ColumnConstIterator::operator-(int y) const noexcept
{
	return { board_, y_ - y };
}
Board::ColumnConstIterator& Board::ColumnConstIterator::operator++() noexcept
{
	++y_;
	return *this;
}
Board::ColumnConstIterator Board::ColumnConstIterator::operator++(int) noexcept
{
	const ColumnConstIterator temp = *this;
	return ++y_, temp;
}
Board::ColumnConstIterator& Board::ColumnConstIterator::operator--() noexcept
{
	--y_;
	return *this;
}
Board::ColumnConstIterator Board::ColumnConstIterator::operator--(int) noexcept
{
	const ColumnConstIterator temp = *this;
	return --y_, temp;
}

Board::Board()
	: stones_(15 * 15)
{}
Board::Board(int size)
	: stones_(size * size), size_(size)
{}
Board::Board(const Board& board)
	: stones_(board.stones_), size_(board.size_), turn_(board.turn_)
{}
Board::Board(Board&& board) noexcept
	: stones_(std::move(board.stones_)), size_(board.size_), turn_(board.turn_)
{
	board.size_ = 0;
	board.turn_ = 0;
}

Board& Board::operator=(const Board& board)
{
	stones_ = board.stones_;
	size_ = board.size_;
	turn_ = board.turn_;

	return *this;
}
Board& Board::operator=(Board&& board) noexcept
{
	stones_ = std::move(board.stones_);
	size_ = board.size_;
	turn_ = board.turn_;

	board.size_ = 0;
	board.turn_ = 0;

	return *this;
}
Board::RowConstIterator Board::operator[](int x) const noexcept
{
	return { this, x };
}
Board::RowIterator Board::operator[](int x) noexcept
{
	return { this, x };
}

const std::vector<Stone>& Board::data() const noexcept
{
	return stones_;
}
std::vector<Stone>& Board::data() noexcept
{
	return stones_;
}
int Board::size() const noexcept
{
	return size_;
}
int Board::turn() const noexcept
{
	return turn_;
}