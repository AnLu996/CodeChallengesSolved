#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    int n, m, p, t, ps[100001];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> m >> p;

        for (int j = 0; j < m; j++) {
            cin >> t;
            ps[j] = t;
        }

        sort (ps, ps + m);

        int r = 0;
        t = 0;

        for (int j = 0; j < m; j++) {
            if ( t + ps[j] > p) {
                break;
            }

            t += ps[j];
            r++;
        }

        cout << r << endl;
    }

    return 0;
}