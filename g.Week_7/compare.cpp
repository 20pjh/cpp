#include <iostream>

class Complex {
public:
    double real, imag;

    Complex(double r = 0, double i = 0) : real(r), imag(i) {}

    // 방법 3: 멤버 함수 (void, 참조 전달)
    void add(Complex& a, Complex& b) {
        real = a.real + b.real;
        imag = a.imag + b.imag;
    }

    // 방법 4: 멤버 함수 (return, 참조 전달)
    Complex add(Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // 방법 5: 연산자 오버로딩
    Complex operator+(Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    void print() {
        std::cout << real << " + " << imag << "i" << std::endl;
    }
};

// 방법 1: 일반 함수 (void, 참조 전달)
void add(Complex& a, Complex& b, Complex& result) {
    result.real = a.real + b.real;
    result.imag = a.imag + b.imag;
}

// 방법 2: 일반 함수 (return, 값 전달)
Complex add(Complex a, Complex b) {
    return Complex(a.real + b.real, a.imag + b.imag);
}

int main() {
    Complex a(1, 2); 
    Complex b(3, 4); 
    Complex c;       

    // 방법 1: 일반 함수 (void, 참조 전달)
    std::cout << "1: ";
    add(a, b, c);
    std::cout << c.real << " + " << c.imag << "i" << std::endl; 

    // 방법 2: 일반 함수 (return, 값 전달)
    std::cout << "2: ";
    c = add(a, b);
    std::cout << c.real << " + " << c.imag << "i" << std::endl; 

    // 방법 3: 멤버 함수 (void, 참조 전달) 
    std::cout << "3: ";
    c.add(a, b);
    std::cout << c.real << " + " << c.imag << "i" << std::endl; 

    // 방법 4: 멤버 함수 (return, 참조 전달)
    std::cout << "4: ";
    c = a.add(b);
    std::cout << c.real << " + " << c.imag << "i" << std::endl; 

    // 방법 5: 연산자 오버로딩
    std::cout << "5: ";
    c = a + b;
    std::cout << c.real << " + " << c.imag << "i" << std::endl; 

    return 0;
}
