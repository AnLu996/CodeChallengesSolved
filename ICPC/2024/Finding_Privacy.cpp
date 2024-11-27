/*// NO FUNCIONA AÚN

#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
    int k, n;
    cin >> k >> n;

    if ( (2*k) + 1 < n || k+1 == n || k == n) {
        cout << "*" << endl;
        return 0;
    }

    vector<char> banios;

    if (k % 2 == 0) {
        for (int i = 0; i < n; i+=2) {
            if (k) {
                banios.push_back('-');
                banios.push_back('X');
            }
            else {
                banios.push_back('-');
            }
            k--;
        }
    }
    else {
        for (int i = 0; i < n; i+=2) {
            if (k) {
                banios.push_back('X');
                banios.push_back('-');
            }
            else {
                banios.push_back('-');
            }
            k--;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << banios[i];
    }

    return 0;
}*/

