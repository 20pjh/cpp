// 구구단 게임, 두 자릿수 곱셈 게임, n자릿수 덧셈 게임(1-9자릿수) 중에 하나를 골라서 맞힐 때까지 푸는 프로그램

#include "p147_6.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // 랜덤 시드 초기화

    int choice;
    // 사용자에게 게임 선택 안내
    cout << "Choose a game:\n";
    cout << "1: Speed GuguDan (Multiplication)\n";
    cout << "2: Two-Digit Multiplication\n";
    cout << "3~9: N-Digit Addition\n";
    cout << "Enter the number of your choice: ";
    cin >> choice;

    // 선택한 게임 실행
    switch (choice) {
        case 1:
            PlayGuguOnce();
            break;
        case 2:
            PlayMultiplication();
            break;
        case 3 ... 9:
            PlayAddition(choice);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}

// 🔹 구구단 게임 함수
void PlayGuguOnce() {
    int num1, num2, answer;

    while (true) {  // 정답을 맞힐 때까지 반복
        num1 = rand() % 9 + 1;  // 1~9 사이의 랜덤 숫자 생성
        num2 = rand() % 9 + 1;
        
        cout << num1 << " x " << num2 << " = ? ";
        cin >> answer;

        if (answer == num1 * num2) {  // 정답 확인
            cout << "Correct!\n";
            break;  // 맞히면 종료
        }
        cout << "Wrong. Try again!\n";  // 틀리면 새로운 문제 출제
    }
}

// 🔹 두 자리 수 곱셈 게임 함수
void PlayMultiplication() {
    int num1, num2, answer;

    while (true) {  // 정답을 맞힐 때까지 반복
        num1 = rand() % 90 + 10;  // 10~99 사이의 랜덤 숫자 생성
        num2 = rand() % 90 + 10;
        
        cout << num1 << " x " << num2 << " = ? ";
        cin >> answer;

        if (answer == num1 * num2) {  // 정답 확인
            cout << "Correct!\n";
            break;  // 맞히면 종료
        }
        cout << "Wrong. Try again!\n";  // 틀리면 새로운 문제 출제
    }
}

// 🔹 N자리 수 덧셈 게임 함수
void PlayAddition(int digits) {
    int num1, num2, answer;
    int minVal = 1;

    // 자릿수에 맞는 최소값 설정 (예: 3자리수 → 100, 4자리수 → 1000)
    for (int i = 1; i < digits; i++) minVal *= 10;
    int maxVal = minVal * 9;  // 최대값 설정 (예: 3자리수 → 999, 4자리수 → 9999)

    while (true) {  // 정답을 맞힐 때까지 반복
        num1 = rand() % (maxVal - minVal) + minVal;  // 랜덤 숫자 생성
        num2 = rand() % (maxVal - minVal) + minVal;
        
        cout << num1 << " + " << num2 << " = ? ";
        cin >> answer;

        if (answer == num1 + num2) {  // 정답 확인
            cout << "Correct!\n";
            break;  // 맞히면 종료
        }
        cout << "Wrong. Try again!\n";  // 틀리면 새로운 문제 출제
    }
}
