#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>
using namespace std;

// 시간 정보를 다루는 MyTime 클래스 정의
class MyTime {
private:
    // 시간 정보: 시, 분, 초
    int hours;
    int minutes;
    int seconds;

public:
    // 기본 생성자: 0시 0분 0초로 초기화
    MyTime();

    // 3개 값으로 초기화하는 생성자
    MyTime(int h, int m, int s);

    // 시간 정보를 출력하는 함수 (cout 사용)
    void print() const {
        cout << hours << "시간 " << minutes << "분 " << seconds << "초" << endl;
    }

    // 참조로 결과를 반환하는 시간 덧셈 함수
    void add(const MyTime& t, MyTime& result) const {
        int h = hours + t.hours;
        int m = minutes + t.minutes;
        int s = seconds + t.seconds;

        // 초와 분에 대한 자리올림 처리
        m += s / 60;
        s %= 60;
        h += m / 60;
        m %= 60;

        // 덧셈 결과를 result에 저장
        result = MyTime(h, m, s);
    }
};

#endif // MYTIME_H