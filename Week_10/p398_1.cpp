#include <iostream>
#include <cstring>

class Sample {
    char* name;
    static int count; // 정적 변수 선언

public:
    // 기본 생성자
    Sample() {
        name = nullptr;
        ++count;
    }

    // 생성자
    Sample(const char* name) {
        this->name = new char[strlen(name) + 1];
        strcpy(this->name, name);
        ++count;
    }

    // 복사 생성자
    Sample(const Sample& other) {
        if (other.name) {
            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
        } else {
            name = nullptr;
        }
        ++count;
    }

    // 소멸자
    ~Sample() {
        delete[] name;
    }

    // 정적 함수
    static void printCount() {
        std::cout << "Object count: " << count << std::endl;
    }
};

// 정적 변수 정의
int Sample::count = 0;

// 메인 함수
int main() {
    Sample a("sample");
    Sample b(a);

    Sample::printCount(); // 객체 개수 출력
    return 0;
}
