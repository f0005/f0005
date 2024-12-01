#include "AI.h"
#include "board.h"
#include <string>
#include <vector>
using namespace std;


constexpr auto MAX_SCORE = (10000000);
constexpr auto MIN_SCORE = (-10000000);
int DEPTH = 5;
struct Pattern {
    std::vector<int> pattern;
    int score;
};
std::vector<Pattern> patterns = {
        { {1, 1, 1, 1, 1}, 50000 },
        { {0, 1, 1, 1, 1, 0}, 4320 },
        { {0, 1, 1, 1, 0, 0}, 720 },
        { {0, 0, 1, 1, 1, 0}, 720 },
        { {0, 1, 1, 0, 1, 0}, 720 },
        { {0, 1, 0, 1, 1, 0}, 720 },
        { {1, 1, 1, 1, 0}, 720 },
        { {0, 1, 1, 1, 1}, 720 },
        { {1, 1, 0, 1, 1}, 720 },
        { {1, 0, 1, 1, 1}, 720 },
        { {1, 1, 1, 0, 1}, 720 },
        { {0, 0, 1, 1, 0, 0}, 120 },
        { {0, 0, 1, 0, 1, 0}, 120 },
        { {0, 1, 0, 1, 0, 0}, 120 },
        { {0, 0, 0, 1, 0, 0}, 20 },
        { {0, 0, 1, 0, 0, 0}, 20 }
};//各种不同情况的权重评分

void AI::init()
{
    aipos[0] = 0, aipos[1] = 0;
}

void AI::aiPos()
{
}

int AI::Evaluate(bool ai)
{
    return 0;
}

int AI::DirectionScore(int x,int y, int x_decrict, int y_derice, std::vector<ScoreShape>& score_all_arr)
{
    int add_score = 0;
    ScoreShape max_scoreshape{ 0,{} };
    for (const auto& item : score_all_arr) {
        for (const auto& pt : item.points) {
            if (x == pt.first && y == pt.second && x_decrict == item.points[0].first - item.points[1].first && y_derice == item.points[0].second - item.points[1].second) {
                return 0;
            }
        }
    }
    for (int offset = -5; offset < 1; offset++) {
        std::vector<int> pos;
        for (int i = 0; i < 6; i++) {
            std::pair<int, int> new_pos = { x + (i + offset) * x_decrict, y + (i + offset) * y_derice };
            if (new_pos.first >= 0 && new_pos.first < 15 && new_pos.second >= 0 && new_pos.second < 15) {
                int type = chessboard[new_pos.first][new_pos.second];
                if (type == -1) {
                    pos.push_back(2);
                }
                else if (type == 1) {
                    pos.push_back(1);
                }
                else {
                    pos.push_back(0);
                }
            }
        }
    }

    return 0;
}

int AI::negMax(bool ai, int alpha, int beta, int depth, const Board& board)
{
    if (depth == 0) return Evaluate(ai);
    int score;
    if (ai) {
        score = MIN_SCORE;
    }
    else {
        score = MAX_SCORE;
    }

    return 0;
}
