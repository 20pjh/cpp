#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 11;
const int MINES = 10;

vector<vector<char>> board(SIZE, vector<char>(SIZE, '0'));
vector<vector<char>> visible(SIZE, vector<char>(SIZE, '.'));
vector<vector<bool>> visited(SIZE, vector<bool>(SIZE, false));

const int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

bool inRange(int x, int y) {
    return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
}

void placeMines() {
    srand(time(0));
    int count = 0;
    while (count < MINES) {
        int r = rand() % SIZE;
        int c = rand() % SIZE;
        if (board[r][c] != '*') {
            board[r][c] = '*';
            count++;
        }
    }
}

void calculateNumbers() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j] == '*') continue;
            int mineCount = 0;
            for (int d = 0; d < 8; ++d) {
                int ni = i + dx[d];
                int nj = j + dy[d];
                if (inRange(ni, nj) && board[ni][nj] == '*')
                    mineCount++;
            }
            board[i][j] = mineCount + '0';
        }
    }
}

void reveal(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [cx, cy] = q.front();
        q.pop();
        visible[cx][cy] = board[cx][cy];

        if (board[cx][cy] == '0') {
            for (int d = 0; d < 8; ++d) {
                int nx = cx + dx[d];
                int ny = cy + dy[d];
                if (inRange(nx, ny) && !visited[nx][ny] && visible[nx][ny] == '.') {
                    visited[nx][ny] = true;
                    if (board[nx][ny] == '0') {
                        q.push({nx, ny});
                    } else {
                        visible[nx][ny] = board[nx][ny];
                    }
                }
            }
        }
    }
}

void printBoard() {
    cout << "     ";
    for (int j = 0; j < SIZE; j++) {
        cout << setw(3) << j;
    }
    cout << "\n";

    for (int i = 0; i < SIZE; i++) {
        cout << setw(3) << i << " |";
        for (int j = 0; j < SIZE; j++) {
            cout << setw(3) << visible[i][j];
        }
        cout << "\n";
    }
    cout << endl; // 입력창 붙는 문제 방지
}

bool checkWin() {
    int revealed = 0;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (visible[i][j] != '.' && visible[i][j] != 'P')
                revealed++;
    return revealed == SIZE * SIZE - MINES;
}

int main() {
    placeMines();
    calculateNumbers();

    while (true) {
        printBoard();
        cout << "행번호 열번호 (깃발을 표시하려면 P 입력): ";

        string input;
        getline(cin, input);

        bool isFlag = false;
        int x, y;

        if (input[0] == 'P' || input[0] == 'p') {
            isFlag = true;
            sscanf(input.c_str() + 1, "%d %d", &x, &y);
        } else {
            sscanf(input.c_str(), "%d %d", &x, &y);
        }

        if (!inRange(x, y)) {
            cout << "범위를 벗어났습니다. 다시 입력해주세요.\n";
            continue;
        }

        if (isFlag) {
            visible[x][y] = (visible[x][y] == 'P') ? '.' : 'P';
        } else if (board[x][y] == '*') {
            cout << "지뢰를 밟았습니다! 게임 오버!\n";
            for (int i = 0; i < SIZE; i++)
                for (int j = 0; j < SIZE; j++)
                    if (board[i][j] == '*') visible[i][j] = '*';
            printBoard();
            break;
        } else {
            reveal(x, y);
            if (checkWin()) {
                cout << "축하합니다! 모든 지뢰를 피해 게임에 승리했습니다!\n";
                printBoard();
                break;
            }
        }
    }

    return 0;
}
