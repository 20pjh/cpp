// 5 X 5크기의 2차원 배열에 0과 1을 임의로 채우는 함수 구현
#include "p202_2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // 5x5 크기의 2차원 배열 선언
    int map[5][5];

    // 배열을 랜덤한 0과 1로 채우는 함수 호출
    randomMap(map);

    // 배열을 화면에 출력하는 함수 호출
    printMap(map);

    return 0; // 프로그램 종료
}

// 5x5 배열을 0과 1로 랜덤하게 채우는 함수
void randomMap(int map[5][5]) {
    srand(time(0)); // 난수 생성을 위한 시드 설정 (현재 시간을 기반으로 함)

    // 2차원 배열을 순회하며 0 또는 1을 랜덤하게 저장
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            map[i][j] = rand() % 2; // 0 또는 1을 랜덤하게 할당
        }
    }
}

// 5x5 배열을 출력하는 함수
void printMap(int map[5][5]) {
    for (int i = 0; i < 5; i++) {      // 행 반복
        for (int j = 0; j < 5; j++) {  // 열 반복
            cout << map[i][j] << " ";  // 값 출력 (공백 포함)
        }
        cout << endl; // 한 행 출력 후 줄 바꿈
    }
}

