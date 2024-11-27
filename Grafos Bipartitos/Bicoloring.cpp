#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBicolor(int n, const vector<pair<int, int>>& edges) {
    vector<vector<int>> adj(n);
    for (auto [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> color(n, -1);
    queue<int> q;

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            color[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n && n) {
        int l;
        cin >> l;

        vector<pair<int, int>> edges;
        for (int i = 0; i < l; i++) {
            int x, y;
            cin >> x >> y;
            edges.push_back({x, y});
        }

        if (isBicolor(n, edges)) {
            cout << "BICOLORABLE." << endl;
        } else {
            cout << "NOT BICOLORABLE." << endl;
        }
    }

    return 0;
}
