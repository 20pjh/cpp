#include <iostream>

// 부모 클래스
class Point {
protected:
    int x, y;
public:
    Point(int xx, int yy) : x(xx), y(yy) { }

    virtual void draw() {
        std::cout << x << "," << y << " 에 점을 그려라.\n";
    }
};

// 자식 클래스
class Rectangle : public Point {
private:
    int width, height;
public:
    Rectangle(int xx, int yy, int w, int h)
        : Point(xx, yy), width(w), height(h) { }

    void draw() override {
        std::cout << x << "," << y << "에 가로 " << width
                  << ", 세로 " << height << "인 사각형을 그려라.\n";
    }
};

// 실행 함수
int main() {
    Rectangle r(2, 3, 100, 200);
    r.draw();

    return 0;
}
//4.Point 클래스의 protected 키워드를 private로 바꾸면 어떻게 되는지 설명하라
//더 이상 자식 클래스인 Rectangle 클래스에서 부모 클래스인 Point 클래스의 멤버들을 사용할 수 없다.