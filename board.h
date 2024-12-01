#pragma once
#include <map>
#include <vector>
#include <unordered_map>
#include <mutex>
using namespace std;

class Board {
public:
	Board() :chessboard(15, std::vector<int>(15, 0)) {} //��ʼ�������������������ͱ���һ��
	const vector<vector<int>>& GetChessboard() const;//������ģ����Է���chessboard
	void SetBoard();
	void Counting();
	std::vector<int> CheckPos(int x,int y);
	bool CheckWin(int x,int y,int type);
private:
	std::vector<std::vector<int>> chessboard;
	mutable std::mutex mtx;
	std::unordered_map<int, int> xpos;
	std::unordered_map<int, int> ypos;
};
typedef enum {
	whiteChess = -1,blackChess=1
}chessKind;
class ChessColor {
public:
	void BlackChess(int x, int y);
	void WhiteChess(int x, int y);
};




