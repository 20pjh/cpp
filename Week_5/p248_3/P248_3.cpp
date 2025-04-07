#include <iostream>
#include "MyTime.h"

using namespace std;

// 메인 함수 - addtime 함수들을 테스트
int main() {
    MyTime t1 = {10, 45, 30};  // 첫 번째 시간
    MyTime t2 = {3, 20, 40};   // 두 번째 시간

    // 반환 값을 사용하는 함수 테스트
    MyTime t3 = addtime(t1, t2);
    cout << "반환 값을 사용하는 결과: " << t3.hours << "시간 " << t3.minutes << "분 " << t3.seconds << "초" << endl;

    // 참조를 사용하는 함수 테스트
    MyTime t4;
    addtime(t1, t2, t4);
    cout << "참조를 사용하는 결과: " << t4.hours << "시간 " << t4.minutes << "분 " << t4.seconds << "초" << endl;

    // 포인터를 사용하는 함수 테스트
    MyTime t5;
    addtime(t1, t2, &t5);
    cout << "포인터를 사용하는 결과: " << t5.hours << "시간 " << t5.minutes << "분 " << t5.seconds << "초" << endl;

    return 0;
}

// 두 MyTime 구조체를 더하고 새로운 MyTime 구조체를 반환하는 함수
MyTime addtime(MyTime t1, MyTime t2) {
    int total_seconds = t1.seconds + t2.seconds;
    int total_minutes = t1.minutes + t2.minutes + total_seconds / 60;
    int total_hours = t1.hours + t2.hours + total_minutes / 60;
    
    MyTime result;
    result.hours = total_hours % 24;
    result.minutes = total_minutes % 60;
    result.seconds = total_seconds % 60;
    return result;
}

// 두 MyTime 구조체를 더하고 결과를 참조로 MyTime 구조체에 저장하는 함수
void addtime(MyTime t1, MyTime t2, MyTime& t3) {
    int total_seconds = t1.seconds + t2.seconds;
    int total_minutes = t1.minutes + t2.minutes + total_seconds / 60;
    int total_hours = t1.hours + t2.hours + total_minutes / 60;
    
    t3.hours = total_hours % 24;
    t3.minutes = total_minutes % 60;
    t3.seconds = total_seconds % 60;
}

// 두 MyTime 구조체를 더하고 결과를 포인터로 MyTime 구조체에 저장하는 함수
void addtime(MyTime t1, MyTime t2, MyTime* t3) {
    if (t3 != nullptr) {
        int total_seconds = t1.seconds + t2.seconds;
        int total_minutes = t1.minutes + t2.minutes + total_seconds / 60;
        int total_hours = t1.hours + t2.hours + total_minutes / 60;
        
        t3->hours = total_hours % 24;
        t3->minutes = total_minutes % 60;
        t3->seconds = total_seconds % 60;
    }
}