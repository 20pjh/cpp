#include <iostream>
#include <iomanip>
using namespace std;

class TimeMS {
    int hour, min, sec;
public:
    TimeMS(int h=0, int m=0, int s=0) : hour(h), min(m), sec(s) {
        normalize();
    }

    void normalize() {
        int totalSec = hour * 3600 + min * 60 + sec;
        if (totalSec < 0) totalSec = 0;
        hour = totalSec / 3600;
        min = (totalSec % 3600) / 60;
        sec = totalSec % 60;
    }

    // + 연산자 오버로딩
    TimeMS operator+(const TimeMS& t) const {
        return TimeMS(hour + t.hour, min + t.min, sec + t.sec);
    }

    // - 연산자 오버로딩
    TimeMS operator-(const TimeMS& t) const {
        int totalSec1 = hour * 3600 + min * 60 + sec;
        int totalSec2 = t.hour * 3600 + t.min * 60 + t.sec;
        return TimeMS(0, 0, totalSec1 - totalSec2);
    }

    // == 연산자 오버로딩
    bool operator==(const TimeMS& t) const {
        return hour == t.hour && min == t.min && sec == t.sec;
    }

    // != 연산자 오버로딩
    bool operator!=(const TimeMS& t) const {
        return !(*this == t);
    }

    // 전위 ++ (1시간 증가)
    TimeMS& operator++() {
        hour++;
        return *this;
    }

    // 전위 -- (1시간 감소)
    TimeMS& operator--() {
        if (hour > 0) hour--;
        return *this;
    }

    // 후위 ++ (1초 증가)
    TimeMS operator++(int) {
        TimeMS temp = *this;
        sec++;
        normalize();
        return temp;
    }

    // 후위 -- (1초 감소)
    TimeMS operator--(int) {
        TimeMS temp = *this;
        sec--;
        normalize();
        return temp;
    }

    // 인덱스 연산자 오버로딩
    int operator[](int index) const {
        if (index == 0) return hour;
        else if (index == 1) return min;
        else if (index == 2) return sec;
        else return -1; // invalid index
    }

    // int 형 변환 연산자
    operator int() const {
        return hour * 3600 + min * 60 + sec;
    }

    // double 형 변환 연산자
    operator double() const {
        return hour + min / 60.0 + sec / 3600.0;
    }

    // friend * 연산자 오버로딩 (int * TimeMS)
    friend TimeMS operator*(int n, const TimeMS& t) {
        int totalSec = n * (int)t;
        return TimeMS(0, 0, totalSec);
    }

    // << 연산자 오버로딩
    friend ostream& operator<<(ostream& os, const TimeMS& t) {
        os << setfill('0') << setw(2) << t.hour << ":"
           << setw(2) << t.min << ":" << setw(2) << t.sec;
        return os;
    }

    // >> 연산자 오버로딩
    friend istream& operator>>(istream& is, TimeMS& t) {
        char sep1, sep2;
        is >> t.hour >> sep1 >> t.min >> sep2 >> t.sec;
        t.normalize();
        return is;
    }
};

int main() {
    TimeMS t1(1, 20, 30), t2(4, 35, 46), t3;

    // 1. +
    t3 = t1 + t2;
    cout << "t1 + t2 = " << t3 << endl;

    // 2. -
    t3 = t1 - t2;
    cout << "t1 - t2 = " << t3 << endl;

    // 3. ==, !=
    cout << boolalpha;
    cout << "t1 == t2? " << (t1 == t2) << endl;
    cout << "t1 != t2? " << (t1 != t2) << endl;

    // 4. 전위 ++, --
    ++t1;
    cout << "++t1 = " << t1 << endl;
    --t1;
    cout << "--t1 = " << t1 << endl;

    // 5. 후위 ++, --
    t1++;
    cout << "t1++ = " << t1 << endl;
    t1--;
    cout << "t1-- = " << t1 << endl;

    // 6. 인덱스 []
    cout << "t1[0](hour) = " << t1[0] << ", t1[1](min) = " << t1[1] << ", t1[2](sec) = " << t1[2] << endl;

    // 7. (int)
    cout << "(int)t1 = " << (int)t1 << " seconds" << endl;

    // 8. (double)
    cout << fixed << setprecision(6);
    cout << "(double)t1 = " << (double)t1 << " hours" << endl;

    // 9. 정수 * TimeMS
    t3 = 2 * t1;
    cout << "2 * t1 = " << t3 << endl;

    // 10. >>, <<
    cout << "Enter time in format HH:MM:SS: ";
    cin >> t3;
    cout << "You entered: " << t3 << endl;

    return 0;
}
