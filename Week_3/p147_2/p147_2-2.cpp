// p147_2 정수를 입력받아 각 자리 숫자를 역순으로 만들어 반환하는 함수 reverse()를 작성하라.

#include <iostream>  
#include <algorithm>  
#include <string>  

using namespace std;  // std 네임스페이스 사용

// reverseNumber 함수 선언: 정수를 역순으로 바꾸는 함수
int reverseNumber(int);

int main() 
{
    int num = 12345;  // 변수 num에 12345 할당
    cout << "Original: " << num << "\n";  // 원본 숫자 출력
    cout << "Reversed: " << reverseNumber(num) << "\n";  // 역순으로 변환된 숫자 출력
    return 0;  // 프로그램 정상 종료
}

// reverseNumber 함수 정의: 주어진 숫자를 역순으로 변환하여 반환하는 함수
int reverseNumber(int num) 
{
    string str = to_string(num);  // 숫자 num을 문자열로 변환 (예: 12345 -> "12345")
    reverse(str.begin(), str.end());  // 문자열의 처음과 끝을 바꿔서 전체 문자열을 뒤집음 (예: "12345" -> "54321")
    return stoi(str);  // 뒤집어진 문자열을 다시 정수로 변환하여 반환 (예: "54321" -> 54321)
}