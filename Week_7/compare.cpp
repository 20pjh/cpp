#include <iostream>
using namespace std;

class Complex {
public:
    double real, imag;

    // 생성자
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 1. 일반 함수 void + 참조 전달
    void add(const Complex& other, Complex& result) const {
        result.real = real + other.real;
        result.imag = imag + other.imag;
    }

    // 2. 일반 함수 return + 값 전달
    Complex add(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 3. 멤버 함수 void + 참조 전달
    void add(const Complex& other, Complex& result) {
        result.real = real + other.real;
        result.imag = imag + other.imag;
    }

    // 4. 멤버 함수 return + 참조 반환
    Complex addAndReturnResult(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // 5. 연산자 오버로딩
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex a(1, 2), b(3, 4), c;

    // 1. 일반 함수 void + 참조 전달
    a.add(b, c);  // a 객체의 add 함수 호출
    cout << "1: "; c.display();

    // 2. 일반 함수 return + 값 전달
    c = a.add(b);  // a 객체의 add 함수 호출
    cout << "2: "; c.display();

    // 3. 멤버 함수 void + 참조 전달
    a.add(b, c);  // a 객체의 add 함수 호출
    cout << "3: "; c.display();

    // 4. 멤버 함수 return + 참조 반환
    c = a.addAndReturnResult(b);  // a 객체의 addAndReturnResult 함수 호출
    cout << "4: "; c.display();

    // 5. 연산자 오버로딩
    c = a + b;  // a.operator+(b) 호출됨
    cout << "5: "; c.display();

    return 0;
}
