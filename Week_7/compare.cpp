#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;

    // 생성자: 실수부와 허수부 초기화
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 복소수 출력 함수
    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }

    // 3. 멤버 함수: void + 참조 전달
    // 두 복소수를 더한 결과를 result 객체에 저장
    void add(const Complex& other, Complex& result) const {
        result.real = real + other.real;
        result.imag = imag + other.imag;
    }

    // 4. 멤버 함수: return + 값 전달
    // 두 복소수를 더한 새로운 복소수 객체를 반환
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 5. 연산자 오버로딩: 복소수 더하기 연산자
    // 두 복소수를 더한 새로운 복소수 객체를 반환
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }
};

// 1. 일반 함수: void + 참조 전달
// 두 복소수를 더한 결과를 result 객체에 저장
void add(const Complex& a, const Complex& b, Complex& result) {
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
}

// 2. 일반 함수: return + 값 전달
// 두 복소수를 더한 새로운 복소수 객체를 반환
Complex add(const Complex& a, const Complex& b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    Complex a(1, 2), b(3, 4), c;

    // 1. 일반 함수: void + 참조 전달
    // a와 b의 합을 c에 저장
    add(a, b, c);
    cout << "1: "; c.display();

    // 2. 일반 함수: return + 값 전달
    // a와 b의 합을 c에 저장 (값 반환 방식)
    c = add(a, b);
    cout << "2: "; c.display();

    // 3. 멤버 함수: void + 참조 전달
    // a와 b의 합을 c에 저장
    a.add(b, c);
    cout << "3: "; c.display();

    // 4. 멤버 함수: return + 값 전달
    // a와 b의 합을 c에 저장 (값 반환 방식)
    c = a.add(b);
    cout << "4: "; c.display();

    // 5. 연산자 오버로딩: 복소수 더하기
    // a와 b의 합을 c에 저장 (연산자 오버로딩 방식)
    c = a + b;
    cout << "5: "; c.display();

    return 0;
}
