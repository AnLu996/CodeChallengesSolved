#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, tc = 1;
    cin >> t;
    while (t--) {
        vector<int> w(10);
        for (int &x : w) cin >> x;

        sort(w.begin(), w.end());

        vector<int> chicas(5);
        bool found = false;

        for (int i = 1; i < w[0]; i++) {
            int x = i, y = w[0] - i;
            int z = w[1] - x;
            if (x > y) 
                break;

            for (int j = y; j < w[9]; j++) {
                int p = j, q = w[9] - j;
                if (p < q) 
                    swap(p, q);
                if (q < y)
                    break;
                int r = w[8] - p;
                if (r == z) {
                    chicas[0] = x;
                    chicas[1] = y;
                    chicas[2] = z;
                    chicas[3] = q;
                    chicas[4] = p;

                    vector<int> tmp;
                    for (int k = 0; k < 5; k++) {
                        for (int l = k + 1; l < 5; l++) {
                            tmp.push_back(chicas[k] + chicas[l]);
                        }
                    }

                    sort(tmp.begin(), tmp.end());
                    if (tmp == w) {
                        found = true;
                        break;
                    }
                }
            }
            if (found) break;
        }

        cout << "Case " << tc++ << ": ";
        for (int i = 0; i < 5; i++)
            cout << chicas[i] << " \n"[i == 4];
    }

    return 0;
}
