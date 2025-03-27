// 가로나 세로 또는 대각선이 모두 0이거나 1인 부분을 찾아 화면으로 출력하는 함수 구현
#include "p202_2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int map[5][5];

    randomMap(map);
    printMap(map);

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
    cout << "  +-----------------+" << endl; // 윗 테두리
    for (int i = 0; i < 5; i++) {
        cout << i << " | "; // 행 번호 출력
        for (int j = 0; j < 5; j++) {
            cout << (map[i][j] ? "■" : "□") << " "; // 1은 ■, 0은 □ 출력
        }
        cout << "|" << endl;
    }
    cout << "  +-----------------+" << endl; // 아래 테두리
    cout << "    0 1 2 3 4" << endl; // 열 번호 출력
}

