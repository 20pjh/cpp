#include "p147_6.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void PlayGuguOnce() {
    for (int i = 0; i < 10; ++i) {
        int num1 = rand() % 9 + 1; // 1~9까지의 랜덤 숫자
        int num2 = rand() % 9 + 1; // 1~9까지의 랜덤 숫자
        int answer;
        
        cout << num1 << " x " << num2 << " = ? ";
        cin >> answer;
        if (answer == num1 * num2) {
            cout << "Correct!" << endl;
        } else {
            cout << "Wrong. The correct answer is " << num1 * num2 << endl;
        }
    }
}

void PlayMultiplication() {
    for (int i = 0; i < 10; ++i) {
        int num1 = rand() % 90 + 10;  // 두 자리 수 랜덤
        int num2 = rand() % 90 + 10;  // 두 자리 수 랜덤
        int answer;

        cout << num1 << " x " << num2 << " = ? ";
        cin >> answer;

        if (answer == num1 * num2) {
            cout << "Correct!" << endl;
        } else {
            cout << "Wrong. The correct answer is " << num1 * num2 << endl;
        }
    }
}

void PlayAddition(int digits) {
    for (int i = 0; i < 10; ++i) {
        int num1, num2;
        
        // 자릿수에 맞는 랜덤 덧셈 문제 생성
        if (digits == 3) {
            num1 = rand() % 900 + 100;  // 3자리 수 랜덤
            num2 = rand() % 900 + 100;  // 3자리 수 랜덤
        } else if (digits == 4) {
            num1 = rand() % 9000 + 1000;  // 4자리 수 랜덤
            num2 = rand() % 9000 + 1000;  // 4자리 수 랜덤
        } else if (digits == 5) {
            num1 = rand() % 90000 + 10000;  // 5자리 수 랜덤
            num2 = rand() % 90000 + 10000;  // 5자리 수 랜덤
        } else if (digits == 6) {
            num1 = rand() % 900000 + 100000;  // 6자리 수 랜덤
            num2 = rand() % 900000 + 100000;  // 6자리 수 랜덤
        } else if (digits == 7) {
            num1 = rand() % 9000000 + 1000000;  // 7자리 수 랜덤
            num2 = rand() % 9000000 + 1000000;  // 7자리 수 랜덤
        } else if (digits == 8) {
            num1 = rand() % 90000000 + 10000000;  // 8자리 수 랜덤
            num2 = rand() % 90000000 + 10000000;  // 8자리 수 랜덤
        } else if (digits == 9) {
            num1 = rand() % 900000000 + 100000000;  // 9자리 수 랜덤
            num2 = rand() % 900000000 + 100000000;  // 9자리 수 랜덤
        }
        
        int answer;
        cout << num1 << " + " << num2 << " = ? ";
        cin >> answer;

        if (answer == num1 + num2) {
            cout << "Correct!" << endl;
        } else {
            cout << "Wrong. The correct answer is " << num1 + num2 << endl;
        }
    }
}

int main() {
    srand(time(0));  // 랜덤 시드 초기화

    int choice;
    cout << "Choose a game:\n";
    cout << "1: Speed GuguDan (Multiplication)\n";
    cout << "2: Two-Digit Multiplication\n";
    cout << "3: Three-Digit Addition\n";
    cout << "4: Four-Digit Addition\n";
    cout << "5: Five-Digit Addition\n";
    cout << "6: Six-Digit Addition\n";
    cout << "7: Seven-Digit Addition\n";
    cout << "8: Eight-Digit Addition\n";
    cout << "9: Nine-Digit Addition\n";
    cout << "Enter the number of your choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            PlayGuguOnce();
            break;
        case 2:
            PlayMultiplication();
            break;
        case 3:
            PlayAddition(3);
            break;
        case 4:
            PlayAddition(4);
            break;
        case 5:
            PlayAddition(5);
            break;
        case 6:
            PlayAddition(6);
            break;
        case 7:
            PlayAddition(7);
            break;
        case 8:
            PlayAddition(8);
            break;
        case 9:
            PlayAddition(9);
            break;
        default:
            cout << "Invalid choice!" << endl;
            break;
    }

    return 0;
}