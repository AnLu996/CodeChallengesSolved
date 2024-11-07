#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m, k, d; 
    vector<vector<int>> v;

    while (cin >> n >> m) {
        vector<vector<int>> v(10000000);

        for (int i = 1; i <= n; i++) {
            cin >> d;
            v[d].push_back(i);
        }

        for (int i = 0; i < m; i++) {
            cin >> k >> d;

            if (k < v[d].size()+1) {
                cout << v[d][k-1] << '\n';
            } else {
                cout << "0\n";
            }
        }
        
    }

    return 0;
}
