// 체커 보드를 보기 좋게 화면에 출력하는 함수 구현
#include "p202_2.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // 5x5 크기의 2차원 배열 선언
    int map[5][5];

    // 0과 1을 랜덤하게 채움
    randomMap(map);

    // 배열을 보기 좋게 출력
    printMap(map);

    // 가로, 세로, 대각선에서 같은 값(0 또는 1)으로 채워진 줄이 있는지 확인
    checkMap(map);

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

// 5x5 배열을 보기 좋게 출력하는 함수
void printMap(int map[5][5]) {
    cout << "  +-----------------+" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i << " | ";  // 행 번호 출력
        for (int j = 0; j < 5; j++) {
            cout << (map[i][j] ? "■" : "□") << " ";  // 1이면 ■, 0이면 □로 표시
        }
        cout << "|" << endl;
    }
    cout << "  +-----------------+" << endl;
    cout << "    0 1 2 3 4" << endl; // 열 번호 출력
}

// 가로, 세로, 대각선이 모두 0이거나 1인지 체크하는 함수
void checkMap(int map[5][5]) {
    bool found = false; // 일치하는 줄이 있는지 여부

    // 1️⃣ 가로 줄(행) 확인
    for (int i = 0; i < 5; i++) {
        bool rowSame = true;
        for (int j = 1; j < 5; j++) {
            if (map[i][j] != map[i][0]) { // 한 줄이 같은 값인지 확인
                rowSame = false;
                break;
            }
        }
        if (rowSame) {
            cout << "가로 줄 " << i << "이(가) 모두 " << map[i][0] << "입니다." << endl;
            found = true;
        }
    }

    // 2️⃣ 세로 줄(열) 확인
    for (int j = 0; j < 5; j++) {
        bool colSame = true;
        for (int i = 1; i < 5; i++) {
            if (map[i][j] != map[0][j]) { // 한 열이 같은 값인지 확인
                colSame = false;
                break;
            }
        }
        if (colSame) {
            cout << "세로 줄 " << j << "이(가) 모두 " << map[0][j] << "입니다." << endl;
            found = true;
        }
    }

    // 3️⃣ 왼쪽 위 → 오른쪽 아래 대각선 확인 (↘)
    bool diag1Same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][i] != map[0][0]) { // 왼쪽 위부터 오른쪽 아래까지 같은 값인지 확인
            diag1Same = false;
            break;
        }
    }
    if (diag1Same) {
        cout << "대각선 (↘)이 모두 " << map[0][0] << "입니다." << endl;
        found = true;
    }

    // 4️⃣ 오른쪽 위 → 왼쪽 아래 대각선 확인 (↙)
    bool diag2Same = true;
    for (int i = 1; i < 5; i++) {
        if (map[i][4 - i] != map[0][4]) { // 오른쪽 위부터 왼쪽 아래까지 같은 값인지 확인
            diag2Same = false;
            break;
        }
    }
    if (diag2Same) {
        cout << "대각선 (↙)이 모두 " << map[0][4] << "입니다." << endl;
        found = true;
    }

    // 5️⃣ 일치하는 줄이 없을 경우 메시지 출력
    if (!found) {
        cout << "가로, 세로, 대각선 중 모두 같은 값인 줄이 없습니다." << endl;
    }
}


