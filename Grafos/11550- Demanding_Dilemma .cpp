#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;

    while (N--) {
        int c, f;
        cin >> c >> f;

        int matriz[c][f];
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < f; j++) {
                cin >> matriz[i][j];    
        }
    }

    bool es = true;
    set<string> conjuntoAristas;

    for (int i = 0; i < f; i++) {
            int suma = 0;
            string vertices = "";

            for (int j = 0; j < c; j++) {
                suma += matriz[j][i];
                if (matriz[j][i] != 0) {
                    vertices += ('0' + j);
                }
            }

            if (suma != 2 || vertices.length() != 2 || conjuntoAristas.find(vertices) != conjuntoAristas.end())  {
                es = false;
                break;
            }

            conjuntoAristas.insert(vertices);
    }
    
    if (es) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    }
    return 0;
}