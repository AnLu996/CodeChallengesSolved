#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int potencia(int n) {
    int resp = 0;
    for (int i = n; i >= 1; i = i/2) {
        resp ++;
    }
    return resp;
}

int main() {
    fast();

    int m;
    cin >> m;

    while (m) {
        vector<int> pot;
        int maxpot = potencia(m);

        for (int i = 0; i < maxpot + 1; i++) {
            for (int j = 0; j < maxpot; j++) {
                int p = pow(2,i) * pow(3,j);
                pot.push_back(p);
            }
        }

        sort(pot.begin(), pot.end());

        for (auto x:pot) {
            if (x-m >= 0) {
                cout << x << endl;
                break;
            }
        }

        cin >> m;
    }
    return 0;
}