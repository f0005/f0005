#pragma once
#include <graphics.h>
#include <vector>
#include <string>
#include "board.h"

using namespace std;

class AI {
public:
	void init();
	void aiPos();
	int Evaluate(bool ai);
	int DirectionScore(int x,int y, int x_decrict,int y_derice, std::vector<ScoreShape>& score_all_arr);
    int negMax(bool ai, int alpha, int beta, int depth,const Board &board);
private:
    int aipos[2];
	const Board& board;
	const std::vector<std::vector<int>>& chessboard = board.GetChessboard();
	std::vector<ScoreShape> score_all_arr;
};

struct ScoreShape //存储棋盘中所有棋局
{
	int score;
	std::vector<std::pair<int, int>> points;
};
