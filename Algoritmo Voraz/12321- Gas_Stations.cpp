#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Rango {
    int left, right;
};

int main() {
    int L, G;
    while (cin >> L >> G && (L != 0 || G != 0)) {
        vector<Rango> camino;
        for (int i = 0; i < G; i++) {
            int x, r;
            cin >> x >> r;
            camino.push_back({x - r, x + r});
        }

        sort(camino.begin(), camino.end(), [](const Rango &a, const Rango &b) {
            if (a.left == b.left) return a.right > b.right;
            return a.left < b.left;
        });

        int zona = 0;
        int estaciones = 0;
        int i = 0;

        while (i < G && zona < L) {
            int c = zona;

            while (i < G && camino[i].left <= zona) {
                c = max(c, camino[i].right);
                i++;
            }

            if (c == zona) {
                estaciones = -1;
                break;
            }

            zona = c;
            estaciones++;
        }

        if (zona < L) {
            cout << "-1" << endl;
        } else {
            cout << (G - estaciones) << endl;
        }
    }

    return 0;
}
