#include "p147_6.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    int choice;
    cout << "Choose a game:\n";
    cout << "1: Speed GuguDan (Multiplication)\n";
    cout << "2: Two-Digit Multiplication\n";
    cout << "3~9: N-Digit Addition\n";
    cout << "Enter the number of your choice: ";
    cin >> choice;

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

// 구구단 문제를 출제하는 함수
void PlayGuguOnce() {
    int num1, num2, answer;

    while (true) {
        num1 = rand() % 9 + 1;
        num2 = rand() % 9 + 1;
        cout << num1 << " x " << num2 << " = ? ";
        cin >> answer;

        if (answer == num1 * num2) {
            cout << "Correct!\n";
            break;
        }
        cout << "Wrong. Try again!\n";
    }
}

// 두 자리 수 곱셈 문제를 출제하는 함수
void PlayMultiplication() {
    int num1, num2, answer;

    while (true) {
        num1 = rand() % 90 + 10;
        num2 = rand() % 90 + 10;
        cout << num1 << " x " << num2 << " = ? ";
        cin >> answer;

        if (answer == num1 * num2) {
            cout << "Correct!\n";
            break;
        }
        cout << "Wrong. Try again!\n";
    }
}

// 덧셈 문제를 자릿수에 맞춰 출제하는 함수
void PlayAddition(int digits) {
    int num1, num2, answer;
    int minVal = 1;
    for (int i = 1; i < digits; i++) minVal *= 10;
    int maxVal = minVal * 9;

    while (true) {
        num1 = rand() % (maxVal - minVal) + minVal;
        num2 = rand() % (maxVal - minVal) + minVal;
        cout << num1 << " + " << num2 << " = ? ";
        cin >> answer;

        if (answer == num1 + num2) {
            cout << "Correct!\n";
            break;
        }
        cout << "Wrong. Try again!\n";
    }
}
