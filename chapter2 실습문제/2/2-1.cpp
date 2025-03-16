#include <iostream>
using namespace std;

void N(int i) {
    int thousand = (i / 1000) % 10;
    int hundred = (i / 100) % 10;
    int ten = (i / 10) % 10;
    int one = i % 10;

    if (thousand > 0) {
        cout << thousand << "천 ";
    }

    if (hundred > 0) {
        cout << hundred << "백 ";
    }

    if (ten > 0) {
        cout << ten << "십 ";
    }

    if (one > 0) {
        cout << one;
    }

    if (i == 0) {
        cout << "0";
    }

    cout << endl;
}

int main()
{
    int i;
    cout << "10000 미만의 정수를 입력하세요: ";
    cin >> i;
    N(i);
    return 0;
}