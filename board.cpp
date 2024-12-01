#include "board.h"
#include <graphics.h> 
#include <conio.h>
#include <vector>
#include <unordered_map>
#include <string>
#include <iostream>
#include <mutex>
using namespace std;

const vector<vector<int>>& Board::GetChessboard() const
{
	lock_guard<mutex> lock(mtx);
	return chessboard;
}

void Board::SetBoard()
{
	for (int i = 1; i <=15; i++) {
		int point = 40 * i;
		line(point, 40, point, 600);
		line(40, point, 600, point);
		for (int j = 1; j <=15; j++) {
			xpos.insert({ j * 40,j - 1 });
		}
		ypos.insert({ i * 40,i - 1 });
	}
}
void Board::Counting()
{

}
std::vector<int> Board::CheckPos(int x, int y)
{
		int x1 = (x - 20) / 40;
		int y1 = (y - 20) / 40;
		std::string message = std::to_string(x1);
		outtextxy(650,20,message.c_str());
		message = std::to_string(y1);
		outtextxy(650, 40, message.c_str());
		if (x1 >= 0 && x1 < 15 && y1 >= 0 && y1 < 15) {
			if (chessboard[x1][y1] == 0) {
				int x2 = x1 * 40 + 40;
				int y2 = y1 * 40 + 40;
				std::vector<int> xy = { x2,y2,x1,y1 };
				return xy;
			}
		}
		return {};
}
bool Board::CheckWin(int x,int y,int type)
{
	chessboard[x][y] = type;
	int i, j;
	int score = 0;
	i = x-1, j = x+1;
	//std::string bo = std::to_string(chessboard[x][y]);
	//outtextxy(800, 350, bo.c_str());
	while(i>=0&& chessboard[i][y] == type) score++, i--;
	//std::string sc = std::to_string(i);
	//outtextxy(700, 350, sc.c_str());
	while (j<=14 && chessboard[j][y] == type) score++, j++;
	//sc = std::to_string(score);
	//outtextxy(700, 300, sc.c_str());
	if (score >= 4) return true;

	score = 0, i = y - 1, j = y + 1;
	while (i >= 0 && chessboard[x][i] == type) score++, i--;
	while (j <= 14 && chessboard[x][j] == type) score++, j++;
	if (score >= 4) return true;

	int mi = min(x, y);
	int ma = 14-max(x, y);
	score = 0, i = 1, j = 1;
	while (i <= mi && chessboard[x-i][y-i] == type) score++, i++;
	while (j <= ma && chessboard[x+j][y+j] == type) score++, j++;
	if (score >= 4) return true;

	score = 0, i = 1, j = 1;
	mi = min(x, 14 - y);
	ma = min(14 - x, y);
	while (i <= mi && chessboard[x - i][y + i] == type) score++, i++;
	while (j <= ma && chessboard[x + j][y - j] == type) score++, j++;
	if (score >= 4) return true;

	return false;
}
void ChessColor::BlackChess(int x, int y)
{
	setcolor(BLACK);
	setfillcolor(BLACK);
	fillcircle(x, y, 20);
}
void ChessColor::WhiteChess(int x, int y)
{
	setcolor(BLACK);
	setfillcolor(WHITE);
	fillcircle(x, y, 20);
}

