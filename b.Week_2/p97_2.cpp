#include <iostream>
using namespace std;

void N(int i) {
   
    int thousand = (i / 1000) % 10;
    if (thousand > 0) {
        cout << thousand << "천 ";
    }

    int hundred = (i / 100) % 10;
    if (hundred > 0) {
        cout << hundred << "백 ";
    }

    int ten = (i / 10) % 10;
    if (ten > 0) {
        cout << ten << "십 ";
    }
    
    int one = i % 10;
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

#include <iostream>
using namespace std;

void N(int i) {
    
    int thousand = (i / 1000) % 10;
    if (thousand > 0) {
        cout << thousand << "천 ";
    }

    int hundred = (i / 100) % 10;
    if (hundred > 0) {
        cout << hundred << "백 ";
    }

    int ten = (i / 10) % 10;
    if (ten > 0) {
        cout << ten << "십 ";
    }

    int one = i % 10;
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

#include <iostream>
using namespace std;

void N(int i) {
    
    int thousand = (i / 1000) % 10;
    if (thousand > 0) {
        if (thousand >1) {
            cout << thousand;
        }
        cout << "천 ";
    }

    int hundred = (i / 100) % 10;
    if (hundred > 0) {
        if (hundred>1) {
            cout << hundred;
        }
        cout << "백 ";
    }

    int ten = (i / 10) % 10;
    if (ten > 0) {
        if (ten >1) {
            cout << ten;
        }
        cout << "십 ";
    }

    int one = i % 10;
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