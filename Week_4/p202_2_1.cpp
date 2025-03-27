// 5 X 5크기의 2차원 배열에 0과 1을 임의로 채우는 함수 구현
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
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

