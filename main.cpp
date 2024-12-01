#include <graphics.h>  
#include <conio.h>     
#include <Windows.h>
#include <iostream>
#include <vector>
#include <string>
#include <memory> //引入智能指针
#include "board.h"
#include "Player.h"
using namespace std;

int main() {
    Board board;
    initgraph(1000, 700);
      
    setbkcolor(WHITE);
    cleardevice();
    
    setcolor(BLACK);
   
    board.SetBoard();
    auto player = std::make_unique<Player>(std::make_shared<Board>(board));
    player->init();
    while (true) {
        std::vector<int>xy= player->playerpos();
        if (!xy.empty()) {
            /*std::string x = std::to_string(xy[0]);
            outtextxy(700, 400, x.c_str());
            std::string y = std::to_string(xy[1]);
            outtextxy(720, 400, y.c_str());*/
            if (board.CheckWin(xy[0], xy[1], 1)) break;
        }
        else continue;
    }
    outtextxy(700, 500, "end");
    _getch();
   
    closegraph();
    return 0;
}
