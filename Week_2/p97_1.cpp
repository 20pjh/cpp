#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++) {
        for(int j = 1; j <= i; j++){
            cout << j;
        }
        cout << endl;
        
    }
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    for (int i = 5; i >= 1; i--) {
        for(int j = 5; j >= 6-i; j--){
            cout << j;
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++){ 
        for(int j = 1; j <= 5 - i; j++){
            cout << "  ";
        }
        for(int j = i; j>= 1; j--){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    for (int i = 1; i <= 5; i++){ 
        for(int j = 1; j <= 5 - i; j++){
            cout << "  ";
        }
        for(int j = i; j>= 1; j--){
            cout << j << " ";
        }
        for(int j = 2; j<= i; j++){
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}