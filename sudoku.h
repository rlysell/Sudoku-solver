#include<vector>

struct Position {
    int x, y;
    Position (int x_, int y_) : x (x_), y (y_) { }
};

class Solver {
private:
    int rows = 0;
    int cols = 0;
    std::vector<std::vector<int>> board;

public:

    Solver (std::vector<std::vector<int>> &board_);
    void solve();
    Position findEmpty();
    const bool isEmpty(const int, const int);
    void set (int , int , int);
    const bool isInRow (const int, const int);
    const bool isInCol (const int, const int);
    const bool isInBox (const int, const int, const int);
    const bool isValid (const int, const int, const int);
    bool canfill ();
    const void printBoard ();
};