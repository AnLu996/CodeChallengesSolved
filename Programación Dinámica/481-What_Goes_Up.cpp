#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

// Función recursiva para imprimir la subsecuencia
void print(const vector<int> &seq, const vector<int> &predecessor, int pos) {
    if (pos == -1) return;

    print(seq, predecessor, predecessor[pos]);
    cout << seq[pos] << "\n";
}

int main() {
    fast();
    vector<int> seq;
    int num;

    // Leer todos los números de entrada
    while (cin >> num) {
        seq.push_back(num);
    }

    int n = seq.size();
    if (n == 0) {
        cout << "0\n-\n";
        return 0;
    }

    // dp almacenará el valor más pequeño posible de una subsecuencia creciente hasta cada punto
    vector<int> dp(n);
    vector<int> dp_id(n);  // Guarda el índice del elemento en seq que está en dp
    vector<int> predecessor(n);  // Guarda el predecesor de cada elemento en la subsecuencia

    int lisCount = 0;  // Contador de la longitud de la subsecuencia
    int lisEnd = 0;    // Índice del último elemento de la subsecuencia más larga

    for (int i = 0; i < n; i++) {
        // Encuentra la posición donde seq[i] debe ir en dp para mantener la subsecuencia creciente
        size_t pos = lower_bound(dp.begin(), dp.begin() + lisCount, seq[i]) - dp.begin();

        dp[pos] = seq[i];  // Actualizamos dp con el nuevo valor
        dp_id[pos] = i;    // Guardamos el índice del elemento en seq

        // Si no es el primer elemento, actualizamos el predecesor
        if (pos > 0) {
            predecessor[i] = dp_id[pos - 1];
        } else {
            predecessor[i] = -1;
        }

        // Si hemos extendido la subsecuencia más larga, incrementamos lisCount
        if (pos == lisCount) {
            lisCount++;
            lisEnd = i;
        }
    }

    // Imprimir la longitud de la subsecuencia más larga y la subsecuencia misma
    cout << lisCount << "\n-\n";
    print(seq, predecessor, lisEnd);

    return 0;
}
