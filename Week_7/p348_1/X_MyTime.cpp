#include "List_X_MyTime.h"  // MyTime 헤더파일 포함

int main() {
    MyTime t1, t2, result;

    // 첫 번째 시간 입력
    std::cout << "첫 번째 시간을 입력하세요." << std::endl;
    t1.read();

    // 두 번째 시간 입력
    std::cout << "두 번째 시간을 입력하세요." << std::endl;
    t2.read();

    // 두 시간을 더하고 결과를 저장
    t1.add(t2, result);

    // 덧셈 결과 출력
    std::cout << "두 시간의 합: ";
    result.output();

    return 0;
}