// Input: c 2
// Output: BLANCO

#include <iostream>

using namespace std;

int main() {
    char letter;
    int number;
    cin >> letter >> number;

    while (cin) {
        if (number%2 == (letter-96)%2) {
            cout << "NEGRO";
        }
        else {
            cout << "BLANCO";
        }
        cout << endl;
        cin >> letter >> number;
    }

    return 0;
}