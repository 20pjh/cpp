#include "Du_MyTime.h"  // MyTime 헤더파일 포함

int main() {
    double duration1, duration2;

    // 첫 번째 실수형 시간 입력
    std::cout << "첫 번째 시간을 입력하세요(초 단위, 실수): ";
    std::cin >> duration1;

    // 두 번째 실수형 시간 입력
    std::cout << "두 번째 시간을 입력하세요(초 단위, 실수): ";
    std::cin >> duration2;

    // 각각 밀리초 단위로 변환 (정수로)
    int ms1 = static_cast<int>(duration1 * 1000 + 0.5); // 반올림
    int ms2 = static_cast<int>(duration2 * 1000 + 0.5);

    // MyTime 객체 생성
    MyTime t1(ms1);
    MyTime t2(ms2);
    MyTime result;

    // 두 시간을 더하고 결과를 저장
    t1.add(t2, result);

    // 덧셈 결과 출력
    std::cout << "두 시간의 합: ";
    result.output();

    return 0;
}