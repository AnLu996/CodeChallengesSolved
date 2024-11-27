#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>
#include <math.h>
#include <algorithm>

using namespace std;

class DisjointSet {
    public:
        vector<int> parent;
        vector<int> rank;
        
        DisjointSet(int n) {
            parent.resize(n);
            rank.resize(n, 0);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }
        
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }
        
        bool unions(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (rank[rootX] > rank[rootY]) {
                    parent[rootY] = rootX;
                }
                else if (rank[rootX] < rank[rootY]) {
                    parent[rootX] = rootY;
                }
                else {
                    parent[rootY] = rootX;
                    rank[rootX]++;
                }
                return true;
            }
            return false;
        }
};

double distanciaEuclidiana(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int T;
    cin >> T;
    int num_case = 1;

    while (T--) {
        int n, r;
        cin >> n >> r;

        vector<pair<int, int>> coordenadas;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            coordenadas.push_back({x, y});
        }

        vector<tuple<double, int, int>> aristas;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                double dist = distanciaEuclidiana(coordenadas[i].first, coordenadas[i].second, coordenadas[j].first, coordenadas[j].second);
                aristas.push_back({dist, i, j});
            }
        }

        sort(aristas.begin(), aristas.end());

        DisjointSet ds(n);
        int num_estados = 1;
        double longitud_carreteras = 0, longitud_ferrocarriles = 0;

        for (auto [dist, u, v] : aristas) {
            if (ds.unions(u, v)) {
                if (dist <= r) {
                    longitud_carreteras += dist;
                } else {
                    longitud_ferrocarriles += dist;
                    num_estados++;
                }
            }
        }

        cout << "Case #" << num_case << ": " << num_estados << " " << round(longitud_carreteras) << " " << round(longitud_ferrocarriles) << endl;
        num_case++;
    }

    return 0;
}