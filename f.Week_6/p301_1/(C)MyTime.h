#ifndef MYTIME_H
#define MYTIME_H

#include <iostream>

// MyTime 클래스 정의
class MyTime {
private:
    int hours;   // 시
    int minutes; // 분
    int seconds; // 초

public:
    // 기본 생성자: 시간을 0으로 초기화
    inline MyTime() : hours(0), minutes(0), seconds(0) {}

    // 시, 분, 초를 받아 초기화하는 생성자
    inline MyTime(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // 두 시간을 더하는 메서드 (참조를 통해 결과를 저장)
    inline void add(const MyTime& other, MyTime& result) const {
        int totalSeconds = (hours + other.hours) * 3600 +
                           (minutes + other.minutes) * 60 +
                           (seconds + other.seconds);
        result.hours = totalSeconds / 3600;
        result.minutes = (totalSeconds % 3600) / 60;
        result.seconds = totalSeconds % 60;
    }

    // 시간 데이터를 출력하는 메서드 (std::cout 사용)
    inline void output() const {
        std::cout << hours << "시간 " << minutes << "분 " << seconds << "초" << std::endl;
    }

    // 사용자로부터 시간 데이터를 입력받는 메서드 (std::cin 사용)
    inline void read() {
        std::cout << "시간(시간 분 초 형식으로 입력): ";
        std::cin >> hours >> minutes >> seconds;
    }
};

#endif // MYTIME_H