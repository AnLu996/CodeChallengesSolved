#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m) {
        vector<vector<pair<int, int>>> matriz(m);
        for (int i = 0; i < n; i++) {
            int r;
            cin >> r;
            vector<pair<int, int>> v(r);
            for (int j = 0; j < r; j++) {
                cin >> v[j].first;
            }
            for (int j = 0; j < r; j++) {
                cin >> v[j].second;
            }
            for (int j = 0; j < r; j++) {
                matriz[v[j].first - 1].push_back({i + 1, v[j].second});
            }
        }
        
        cout << m << " " << n << endl;
        for (int i = 0; i < m; i++) {
            cout << matriz[i].size();
            if (matriz[i].size()) {
                cout << " ";
            }
            for (int j = 0; j < matriz[i].size(); j++) {
                cout << matriz[i][j].first;
                if (j != matriz[i].size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
            for (int j = 0; j < matriz[i].size(); j++) {
                cout << matriz[i][j].second;
                if (j != matriz[i].size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}
