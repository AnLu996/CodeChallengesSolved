#include <iostream>
#include <vector>
#include <tuple>
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

int main() {
    int m, n;
    
    while (cin >> m >> n && m && n) {
        vector<tuple<int, int, int>> caminos;
        int camino_total = 0;

        for (int i = 0; i < n; i++) {
            int x, y, z;
            cin >> x >> y >> z;
            caminos.push_back({z, x, y});
            camino_total += z;
        }

        sort(caminos.begin(), caminos.end());

        DisjointSet dsu(m);
        int distancia_min = 0;
        
        for (auto [cost, u, v] : caminos) {
            if (dsu.unions(u, v)) {
                distancia_min += cost;
            }
        }

        int ahorro = camino_total - distancia_min;
        cout << ahorro << endl;
    }

    return 0;
}
