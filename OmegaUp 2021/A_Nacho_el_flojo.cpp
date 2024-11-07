// FALTAAAAA COMPLETAR

#include <iostream>
#include <string>

using namespace std;

int main() {
    int ejercicios;

    cin >> ejercicios;

    while (ejercicios--) {
        int vector[4];
        for (int i = 0; i < 4; i++) {
            int value;
            cin >> value;
            vector[i] = value;
        }

        int first = vector[0] + vector[2];
        int second = vector[1] + vector[3];

        string result;

        for (int i = 0; i < 4; i++) {
            int a, b;
            cin >> a >> b;
            if (a == first && b == second) {
                result = result + char(65 + i);
            }
        }

        cout << result;
    }

    return 0;
}