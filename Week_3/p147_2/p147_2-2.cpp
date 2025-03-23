// p147_2 정수를 입력받아 각 자리 숫자를 역순으로 만들어 반환하는 함수 reverse()를 작성하라.
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int reverseNumber(int);

int main() 
{
    int num = 12345;
    cout << "Original: " << num << "\n";
    cout << "Reversed: " << reverseNumber(num) << "\n";
    return 0;
}

int reverseNumber(int num) 
{
    string str = to_string(num); // 숫자를 문자열로 변환
    reverse(str.begin(), str.end());  // 문자열을 뒤집음
    return stoi(str); // 다시 숫자로 변환하여 반환
}
