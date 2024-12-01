#pragma once
#include "board.h"
#include <vector>
#include <memory>

class Player
{
public:
	Player(const std::shared_ptr<Board>& board) :playerboard(board){}
	void init();
	std::vector<int> playerpos();
private:
	std::unique_ptr<ChessColor> chess;
	std::shared_ptr<Board> playerboard;
};
