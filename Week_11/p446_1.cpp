// 부모클래스와 자식클래스를 활용하여 어떻게 상속이 이뤄지는지 설명

#include <iostream>  // 입출력을 위한 헤더 파일

// 부모 클래스: 좌표를 나타내는 Point 클래스
class Point {
protected:
    int x, y;  // 점의 x좌표와 y좌표
public:
    // 생성자: 좌표 값을 초기화
    Point(int xx, int yy) : x(xx), y(yy) { }

    // 가상 함수: 점을 그리는 기능 (자식 클래스에서 재정의 가능)
    virtual void draw() {
        std::cout << x << "," << y << " 에 점을 그려라.\n";
    }
};

// 자식 클래스: 사각형을 표현하는 Rectangle 클래스
class Rectangle : public Point {
private:
    int width, height;  // 사각형의 너비와 높이
public:
    // 생성자: 좌표와 너비, 높이를 초기화. 부모 클래스 생성자 호출 포함
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) { }

    // draw 함수 재정의: 사각형을 그리는 동작 출력
    void draw() override {
        std::cout << x << "," << y << "에 가로 " << width
                  << ", 세로 " << height << "인 사각형을 그려라.\n";
    }
};

// 실행 함수
int main() {
    Rectangle r(2, 3, 100, 200);  // 좌표 (2,3)에 너비 100, 높이 200인 사각형 생성
    r.draw();  // 사각형 그리기 함수 호출

    return 0;  // 프로그램 종료
}

//4.Point 클래스의 protected 키워드를 private로 바꾸면 어떻게 되는지 설명하라
//더 이상 자식 클래스인 Rectangle 클래스에서 부모 클래스인 Point 클래스의 멤버들을 사용할 수 없다.