#include <iostream>
#include <string>
using namespace std;

// 사용자 정의 예외 클래스
class AccountException {
    string type;
    int amount;
public:
    AccountException(string t, int a) : type(t), amount(a) {}
    string getType() const { return type; }
    int getAmount() const { return amount; }
};

class CustomerAccount {
    int balance;
public:
    CustomerAccount(int b = 0) : balance(b) {}

    int getBalance() { return balance; }

    int deposit(int amount) {
        if (amount <= 0) throw AccountException("Deposit", amount);
        balance += amount;
        return balance;
    }

    int withdraw(int amount) {
        if (amount > balance) throw AccountException("Withdraw", amount);
        balance -= amount;
        return balance;
    }
};

int main() {
    CustomerAccount acc(1000);  // 초기 잔액: 1000

    try {
        acc.deposit(500);  // 정상 입금
        cout << "입금 후 잔액: " << acc.getBalance() << endl;

        acc.withdraw(2000);  // 잔액 초과로 예외 발생
        cout << "출금 후 잔액: " << acc.getBalance() << endl;
    }
    catch (AccountException& e) {
        cout << "[예외 발생] " << e.getType()
             << " 실패, 금액: " << e.getAmount() << endl;
    }

    try {
        acc.deposit(-100);  // 음수 입금으로 예외 발생
    }
    catch (AccountException& e) {
        cout << "[예외 발생] " << e.getType()
             << " 실패, 금액: " << e.getAmount() << endl;
    }

    return 0;
}
