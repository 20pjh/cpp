// p147_2 정수를 입력받아 각 자리 숫자를 역순으로 만들어 반환하는 함수 reverse()를 작성하라.

#include <iostream>
using namespace std;

// 정수를 뒤집는 함수 정의
int reverse(int num) {
    int reversed = 0; // 뒤집힌 숫자를 저장할 변수

    // 숫자를 뒤집는 과정
    while (num != 0) {
        reversed = reversed * 10 + (num % 10); // 마지막 자릿수를 새로운 숫자의 앞자리에 추가
        num /= 10; // 기존 숫자의 마지막 자릿수를 제거
    }

    return reversed; // 뒤집힌 숫자 반환
}

int main() {
    int num;

    // 사용자로부터 정수 입력 받기
    cout << "정수를 입력하세요: ";
    cin >> num;

    // 정수를 뒤집는 함수 호출 및 출력
    cout << "역순 출력: " << reverse(num) << endl;

    return 0;  // 프로그램 종료
}
