#include <iostream>
#include <cstdlib>
#include <ctime>

class Samplelist {
    int list[100];
public:
    Samplelist() {
        srand((unsigned)time(nullptr));  // 시드 초기화 (실행마다 다른 난수)
        for (int x = 0; x < 100; x++)
            list[x] = rand() % 1000;    // 0~999 임의 숫자
    }

    // 1. 인덱스 연산자 [] : 참조 반환
    int& operator[](int index) {
        return list[index];
    }

    // 2. 함수 호출 연산자 (인덱스 하나)
    int& operator()(int index) {
        return list[index];
    }

    // 3. 함수 호출 연산자 (두 숫자의 곱 위치)
    int& operator()(int a, int b) {
        return list[a * b];
    }
};

int main() {
    Samplelist sample;

    std::cout << "sample[10] = " << sample[10] << "\n";
    sample[10] = 555;
    std::cout << "sample[10] after modification = " << sample[10] << "\n";

    std::cout << "sample(20) = " << sample(20) << "\n";
    sample(20) = 666;
    std::cout << "sample(20) after modification = " << sample(20) << "\n";

    int a = 3, b = 4;
    std::cout << "sample(" << a << ", " << b << ") = " << sample(a, b) << "\n";
    sample(a, b) = 777;
    std::cout << "sample(" << a << ", " << b << ") after modification = " << sample(a, b) << "\n";

    return 0;
}
