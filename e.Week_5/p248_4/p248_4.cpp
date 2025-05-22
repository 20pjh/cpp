#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;

// 게임 보드 크기와 지뢰 수를 저장하는 변수
int SIZE_X;
int SIZE_Y;
int MINES;

// 게임 보드, 가시 보드, 방문 여부를 저장하는 벡터
vector<vector<char>> board;
vector<vector<char>> visible;
vector<vector<bool>> visited;

// 8방향 탐색을 위한 배열
const int dx[8] = {-1,-1,-1, 0, 0, 1, 1, 1};
const int dy[8] = {-1, 0, 1,-1, 1,-1, 0, 1};

// 주어진 좌표가 보드 범위 내에 있는지 확인하는 함수
bool inRange(int x, int y) {
    return x >= 0 && x < SIZE_X && y >= 0 && y < SIZE_Y;
}

// 무작위로 지뢰를 배치하는 함수
void placeMines() {
    srand(time(0));
    int count = 0;
    while (count < MINES) {
        int r = rand() % SIZE_X;
        int c = rand() % SIZE_Y;
        if (board[r][c] != '*') {
            board[r][c] = '*';
            count++;
        }
    }
}

// 지뢰 주변의 숫자를 계산하여 보드에 설정하는 함수
void calculateNumbers() {
    for (int i = 0; i < SIZE_X; ++i) {
        for (int j = 0; j < SIZE_Y; ++j) {
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

// 주어진 좌표를 기준으로 빈 칸을 열고, 연결된 빈 칸도 재귀적으로 여는 함수
void reveal(int x, int y) {
    if (!inRange(x, y) || visited[x][y] || visible[x][y] == 'P') return;

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
                    q.push({nx, ny});
                }
            }
        }
    }
}

// 현재 보드 상태를 출력하는 함수
void printBoard() {
    cout << "     ";
    for (int j = 0; SIZE_Y > j; ++j) {
        cout << setw(3) << j;
    }
    cout << "\n";

    for (int i = 0; SIZE_X > i; ++i) {
        cout << setw(3) << i << " |";
        for (int j = 0; SIZE_Y > j; ++j) {
            cout << setw(3) << visible[i][j];
        }
        cout << "\n";
    }
    cout << endl; // 입력창 붙는 문제 방지
}

// 모든 지뢰가 아닌 칸이 열렸는지 확인하는 함수
bool checkWin() {
    for (int i = 0; SIZE_X > i; ++i) {
        for (int j = 0; SIZE_Y > j; ++j) {
            if (board[i][j] != '*' && visible[i][j] == '.') {
                return false;
            }
        }
    }
    return true;
}

// 모든 지뢰를 가시 보드에 표시하는 함수
void revealMines() {
    for (int i = 0; SIZE_X > i; ++i) {
        for (int j = 0; SIZE_Y > j; ++j) {
            if (board[i][j] == '*') {
                visible[i][j] = '*';
            }
        }
    }
}

int main() {
    // 보드 크기와 지뢰 수를 사용자에게 입력 받음
    while (true) {
        cout << "맵 가로 크기(SIZE_X)를 입력하세요 (최대 80): ";
        cin >> SIZE_X;
        if (SIZE_X > 0 && SIZE_X <= 80) break;
        cout << "잘못된 입력입니다. 가로 크기는 1에서 80 사이여야 합니다.\n";
    }
    
    while (true) {
        cout << "맵 세로 크기(SIZE_Y)를 입력하세요 (최대 40): ";
        cin >> SIZE_Y;
        if (SIZE_Y > 0 && SIZE_Y <= 40) break;
        cout << "잘못된 입력입니다. 세로 크기는 1에서 40 사이여야 합니다.\n";
    }

    while (true) {
        cout << "지뢰 수(MINES)를 입력하세요: ";
        cin >> MINES;
        if (MINES > 0 && MINES < SIZE_X * SIZE_Y) break;
        cout << "잘못된 입력입니다. 지뢰 수는 1에서 " << SIZE_X * SIZE_Y - 1 << " 사이여야 합니다.\n";
    }

    // 보드와 가시 보드, 방문 여부 초기화
    board.resize(SIZE_X, vector<char>(SIZE_Y, '0'));
    visible.resize(SIZE_X, vector<char>(SIZE_Y, '.'));
    visited.resize(SIZE_X, vector<bool>(SIZE_Y, false));

    // 지뢰 배치 및 숫자 계산
    placeMines();
    calculateNumbers();

    cin.ignore(); // 입력 버퍼 비우기

    // 게임 루프
    while (true) {
        printBoard();
        cout << "행번호 열번호 (깃발을 표시하려면 P 입력): ";

        string input;
        getline(cin, input);

        bool isFlag = false;
        int x, y;

        // 깃발 표시 여부와 좌표 입력 받기
        if (input[0] == 'P' || input[0] == 'p') {
            isFlag = true;
            sscanf(input.c_str() + 1, "%d %d", &x, &y);
        } else {
            sscanf(input.c_str(), "%d %d", &x, &y);
        }

        // 입력 좌표가 보드 범위를 벗어나는지 확인
        if (!inRange(x, y)) {
            cout << "범위를 벗어났습니다. 다시 입력해주세요.\n";
            continue;
        }

        // 깃발 표시 혹은 칸 열기
        if (isFlag) {
            visible[x][y] = (visible[x][y] == 'P') ? '.' : 'P';
        } else if (board[x][y] == '*') {
            cout << "지뢰를 밟았습니다! 게임 오버!\n";
            revealMines();
            printBoard();
            break;
        } else if (board[x][y] != '0') {
            visible[x][y] = board[x][y];
            visited[x][y] = true;
        } else {
            reveal(x, y);
        }

        // 승리 조건 확인
        if (checkWin()) {
            cout << "축하합니다! 모든 지뢰를 피해 게임에 승리했습니다!\n";
            printBoard();
            break;
        }
    }

    return 0;
}