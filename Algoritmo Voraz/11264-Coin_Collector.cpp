#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main() {
    fast();

    int m;
    cin >> m;

    while (m--) {
        vector<int> moneda;
        int cant; cin>>cant;
        for (int i = 0; i < cant; i++) {
            int temp; cin>>temp;
            moneda.push_back(temp);
        }

        int sum = 0, rest = 0;

        for (int i = 0; i < cant; i++) {
            if(cant-1 == 0 || sum + moneda[i] < moneda[i+1]) {
                sum += moneda[i];
                rest++;
            }

        }

        cout << rest+1 << "\n";
    }
    return 0;
}