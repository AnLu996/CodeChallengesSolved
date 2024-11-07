#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N--) {
        int P;
        cin >> P;

        vector<int> vecinos(P);
        string linea;
        getline(cin, linea);

        for (int i = 0; i < P; i++) {
            string vecinos_str;
            getline(cin, vecinos_str);
            int count = count_if(vecinos_str.begin(), vecinos_str.end(), [](char c) { return c == ' '; });
            vecinos[i] = count + 1;
        }

        int min_vecinos = *min_element(vecinos.begin(), vecinos.end());

        bool first = true;
        for (int i = 0; i < P; i++) {
            if (vecinos[i] == min_vecinos) {
                if (!first) cout << " ";
                cout << i + 1;
                first = false;
            }
        }
        cout << endl;
    }
    return 0;
}