// 시간 더하기 함수들을 위한 헤더 파일

#ifndef MYTIME_H
#define MYTIME_H

// 시간을 나타내는 구조체 정의
typedef struct {
    int hours;   // 시간
    int minutes; // 분
    int seconds; // 초
} MyTime;

// 시간 더하기 함수들의 프로토타입 선언
MyTime addtime(MyTime t1, MyTime t2);                   // 두 시간을 더하고 결과를 반환하는 함수
void addtime(MyTime t1, MyTime t2, MyTime& t3);         // 두 시간을 더하고 결과를 참조로 반환하는 함수
void addtime(MyTime t1, MyTime t2, MyTime* t3);         // 두 시간을 더하고 결과를 포인터로 반환하는 함수

#endif // MYTIME_H