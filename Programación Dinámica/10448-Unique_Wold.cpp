#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring> 
using namespace std;

struct Camino {
    int destino, costo;
    Camino(int a, int b) : destino(a), costo(b) {}
};

vector<Camino> grafo[50];

void resolver(int inicio, int fin, int valor) {
    int distancias[50], enCola[50] = {};
    fill(distancias, distancias + 50, INT_MAX);
    distancias[inicio] = 0;

    queue<int> cola;
    cola.push(inicio);

    while (!cola.empty()) {
        int nodoActual = cola.front();
        cola.pop();
        enCola[nodoActual] = 0;

        for (auto it = grafo[nodoActual].begin(); it != grafo[nodoActual].end(); ++it) {
            if (distancias[it->destino] > distancias[nodoActual] + it->costo) {
                distancias[it->destino] = distancias[nodoActual] + it->costo;
                if (enCola[it->destino] == 0) {
                    enCola[it->destino] = 1;
                    cola.push(it->destino);
                }
            }
        }
    }

    int dp[125000], cantidadCaminos[51] = {}, enCamino = 0;

    fill(dp, dp + 125000, INT_MAX);
    int infinito = dp[0];
    dp[0] = 0;
    cantidadCaminos[fin] = 1;

    cola.push(fin);
    if (valor - distancias[fin] < 0) {
        cout << "No\n";
        return;
    }

    while (!cola.empty()) {
        int nodoActual = cola.front();
        cola.pop();
        enCamino++;

        for (auto it = grafo[nodoActual].begin(); it != grafo[nodoActual].end(); ++it) {
            if (distancias[it->destino] + it->costo == distancias[nodoActual]) {
                if (nodoActual == fin) {
                    for (int i = 0; i <= valor - distancias[fin]; i++) {
                        int j = (it->costo) * 2;
                        dp[i + j] = min(dp[i + j], dp[i] + 2);
                    }
                }
                cantidadCaminos[it->destino] += cantidadCaminos[nodoActual];
                if (enCola[it->destino] == 0) {
                    enCola[it->destino] = 1;
                    cola.push(it->destino);
                }
            }
        }
    }

    if (valor - distancias[fin] >= 0 && dp[valor - distancias[fin]] != infinito)
        cout << "Yes " << dp[valor - distancias[fin]] + enCamino - 1 << "\n";
    else
        cout << "No\n";
}

int main() {
    int casosDePrueba;
    cin >> casosDePrueba;
    while (casosDePrueba--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            grafo[i].clear();
        }

        for (int i = 0; i < m; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            x--; y--;
            grafo[x].emplace_back(y, v);
            grafo[y].emplace_back(x, v);
        }

        cin >> m;
        for (int i = 0; i < m; i++) {
            int x, y, v;
            cin >> x >> y >> v;
            x--; y--;
            resolver(x, y, v);
        }

        if (casosDePrueba)
            cout << "\n";
    }

    return 0;
}
