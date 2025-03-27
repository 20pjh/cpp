// 체커 보드를 보기 좋게 화면에 출력하는 함수 구현
#include "p202_2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int map[5][5];

    randomMap(map);
    printMap(map);
    checkMap(map);

    return 0;
}

void randomMap(int map[5][5]) {
    srand(time(0)); // 랜덤 시드 초기화

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2; // 0 또는 1을 랜덤하게 저장
        }
    }
}

void printMap(int map[5][5]) {
    cout << "  +-----------------+" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i << " | ";
        for (int j = 0; j < 5; j++) {
            cout << (map[i][j] ? "■" : "□") << " ";
        }
        cout << "|" << endl;
    }
    cout << "  +-----------------+" << endl;
    cout << "    0 1 2 3 4" << endl;
}

// 가로, 세로, 대각선이 모두 0이거나 1인지 체크하는 함수
void checkMap(int map[5][5]) {
    bool found = false; // 일치하는 줄이 있는지 여부

    // 가로 줄 확인
    for (int i = 0; i < 5; i++) {
        bool rowSame = true;
        for (int j = 1; j < 5; j++) {
            if (map[i][j] != map[i][0]) {
                rowSame = false;
                break;
            }
        }
        if (rowSame) {
            cout << "가로 줄 " << i << "이(가) 모두 " << map[i][0] << "입니다." << endl;
            found = true;
        }
    }

    // 세로 줄 확인
    for (int j = 0; j < 5; j++) {
        bool colSame = true;
        for (int i = 1; i < 5; i++) {
            if (map[i][j] != map[0][j]) {
                colSame = false;
                break;
            }
        }
        if (colSame) {
            cout << "세로 줄 " << j << "이(가) 모두 " << map[0][j] << "입니다." << endl;
            found = true;
        }
    }

    // 왼쪽 위 -> 오른쪽 아래 대각선 확인
    bool diag1Same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][i] != map[0][0]) {
            diag1Same = false;
            break;
        }
    }
    if (diag1Same) {
        cout << "대각선 (↘)이 모두 " << map[0][0] << "입니다." << endl;
        found = true;
    }

    // 오른쪽 위 -> 왼쪽 아래 대각선 확인
    bool diag2Same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][4 - i] != map[0][4]) {
            diag2Same = false;
            break;
        }
    }
    if (diag2Same) {
        cout << "대각선 (↙)이 모두 " << map[0][4] << "입니다." << endl;
        found = true;
    }

    if (!found) {
        cout << "가로, 세로, 대각선 중 모두 같은 값인 줄이 없습니다." << endl;
    }
}

