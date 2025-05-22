#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

class MyTime {
private:
    int hours;
    int minutes;
    int seconds;
    int milliseconds;

public:
    // 기본 생성자 (멤버 초기화 리스트 사용)
    MyTime() : hours(0), minutes(0), seconds(0), milliseconds(0) {}

    // 시, 분, 초, 밀리초를 받아 초기화하는 생성자
    MyTime(int h, int m, int s, int ms) : hours(h), minutes(m), seconds(s), milliseconds(ms) {}

    // 총 밀리초로 초기화하는 생성자
    MyTime(int ms) {
        hours = ms / 3600000;
        minutes = (ms % 3600000) / 60000;
        seconds = (ms % 60000) / 1000;
        milliseconds = ms % 1000;
    }

    // 두 시간을 더하는 메서드
    void add(const MyTime& other, MyTime& result) const {
        int totalMs = (hours + other.hours) * 3600000 +
                      (minutes + other.minutes) * 60000 +
                      (seconds + other.seconds) * 1000 +
                      milliseconds + other.milliseconds;
        result = MyTime(totalMs);  // 생성자에서 밀리초로 변환하여 전달
    }

    // 시간 데이터를 출력하는 메서드
    void output() const {
        std::cout << hours << "시간 " << minutes << "분 "
                  << seconds << "초 " << milliseconds << "밀리초" << std::endl;
    }

    // 사용자로부터 시간 데이터를 입력받는 메서드
    void read() {
        std::cout << "시간(시간 분 초 밀리초 형식으로 입력): ";
        std::cin >> hours >> minutes >> seconds >> milliseconds;
    }
};

#endif // MYTIME_H
