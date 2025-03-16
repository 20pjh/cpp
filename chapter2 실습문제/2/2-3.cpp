#include <iostream>
using namespace std;

void N(int i) {
    int thousand = (i / 1000) % 10;
    int hundred = (i / 100) % 10;
    int ten = (i / 10) % 10;
    int one = i % 10;

    if (thousand > 0) {
        if (thousand >1) {
            cout << thousand;
        }
        cout << "천 ";
    }

    if (hundred > 0) {
        if (hundred>1) {
            cout << hundred;
        }
        cout << "백 ";
    }

    if (ten > 0) {
        if (ten >1) {
            cout << ten;
        }
        cout << "십 ";
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