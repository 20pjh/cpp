#include <iostream>
#include <iomanip> 

using namespace std;

double calculatePi(int n) {
    double pi = 0.0;
    for (int i = 0; i <= n; i++) {
        double term = 1.0 / (2 * i + 1); 
        if (i % 2 == 1) term = -term;   
        pi += term;
    }
    return pi * 4; 
}

int main() {
    int n;
    cout << "정수 n 입력: ";
    cin >> n;

    if (n < 0) {
        cout << "n은 0 이상의 정수여야 합니다.\n";
        return 1;
    }

    double pi = calculatePi(n);
    cout << fixed << setprecision(10); 
    cout << "근사값: " << pi << endl;

    return 0;
}