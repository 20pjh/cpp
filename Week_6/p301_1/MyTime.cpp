#include "(C)MyTime.h"

// ---- MyTime 클래스 생성자 정의 ----

// 기본 생성자: 시간을 0으로 초기화
MyTime::MyTime() : hours(0), minutes(0), seconds(0) {}

// 시, 분, 초를 받아 초기화하는 생성자
MyTime::MyTime(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}


// ---- main 함수 ----

int main() {
    // 첫 번째 시간 객체 생성 (1시간 40분 50초)
    MyTime t1(1, 40, 50);

    // 두 번째 시간 객체 생성 (2시간 30분 20초)
    MyTime t2(2, 30, 20);

    // 덧셈 결과를 저장할 객체
    MyTime result;

    // t1과 t2를 더해서 result에 저장 (참조 방식 사용)
    t1.add(t2, result);

    // 덧셈 결과 출력
    result.print();  // 결과: 4시간 11분 10초

    return 0;
}
//+------------------------+
//|        MyTime          |
//+------------------------+
//| - hours: int           |
//| - minutes: int         |
//| - seconds: int         |
//+------------------------+
//| +MyTime()              |
//| +MyTime(h: int, m: int, s: int) |
//| +print(): void // uses cout        | 
//| +add(t: MyTime, result: MyTime&): void |
//+------------------------+