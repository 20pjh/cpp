// p147_2 정수를 입력받아 각 자리 숫자를 역순으로 만들어 반환하는 함수 reverse()를 작성하라.

#include "p147_2_5.h"  // 헤더 파일을 포함 (reverseNumber 함수 선언이 있을 것으로 예상)
#include <iostream>  
#include <algorithm>  
#include <string>  

using namespace std;  

int main() 
{
    int num;  // 사용자 입력을 받을 정수 변수 num
    cout << "Enter an integer: ";  // 사용자에게 정수를 입력하라는 메시지를 출력
    cin >> num;  // 사용자로부터 정수 입력 받음
    
    cout << "Original: " << num << "\n";  // 원본 숫자 출력
    cout << "Reversed: " << reverseNumber(num) << "\n";  // 역순으로 변환된 숫자 출력
    
    return 0;  // 프로그램 정상 종료
}

// reverseNumber 함수 정의: 주어진 정수 num을 역순으로 변환하는 함수
int reverseNumber(int num) 
{
    string str = to_string(num);  // 입력된 정수 num을 문자열로 변환
    reverse(str.begin(), str.end());  // 문자열을 뒤집음
    return stoi(str);  // 뒤집은 문자열을 다시 정수로 변환하여 반환
}


