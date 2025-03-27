// 가로나 세로 또는 대각선이 모두 0이거나 1인 부분을 찾아 화면으로 출력하는 함수 구현
#include "p202_2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std; // std 네임스페이스 사용

// 함수 선언
void randomMap(int map[5][5]); // 5x5 배열을 0과 1로 랜덤하게 채우는 함수
void printMap(int map[5][5]);  // 5x5 배열을 보기 좋게 출력하는 함수

int main() {
    int map[5][5]; // 5x5 크기의 2차원 배열 선언

    randomMap(map); // 배열을 0과 1로 랜덤하게 채움
    printMap(map);  // 배열을 보기 좋게 출력

    return 0; // 프로그램 정상 종료
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

// 5x5 배열을 보기 좋게 출력하는 함수
void printMap(int map[5][5]) {
    cout << "  +-----------------+" << endl; // 윗 테두리 출력
    for (int i = 0; i < 5; i++) {
        cout << i << " | "; // 행 번호 출력
        for (int j = 0; j < 5; j++) {
            cout << (map[i][j] ? "■" : "□") << " "; // 1이면 ■, 0이면 □ 출력
        }
        cout << "|" << endl;
    }
    cout << "  +-----------------+" << endl; // 아래 테두리 출력
    cout << "    0 1 2 3 4" << endl; // 열 번호 출력
}


