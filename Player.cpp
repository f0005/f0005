#include "Player.h"
#include "board.h"
#include <graphics.h> 
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <vector>

void Player::init()
{
	chess=std::make_unique<ChessColor>();
}

std::vector<int> Player::playerpos()
{
	MOUSEMSG msg;
	msg = GetMouseMsg();
	if (msg.uMsg == WM_LBUTTONDOWN) {
		std::vector<int> xy=playerboard->CheckPos(msg.x, msg.y);
		if (!xy.empty()) {
			chess->BlackChess(xy[0], xy[1]);
			return std::vector<int>(xy.end() - 2, xy.end());
		}
		else cout << "empty vector" << endl;
	}
	return {};
}
