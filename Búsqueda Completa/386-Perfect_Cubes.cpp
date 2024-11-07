#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main() {
    vector<tuple<int, int, int, int>> matrix;
    for (int a = 2; a < 201; a ++) {
        int aCubo = a * a * a;

        for (int b = 2; b < a; b++) {
            int bCubo = b * b * b;
            if (bCubo > aCubo) {
                break;
            }

            for (int c = b; c < a; c++) {
                int cCubo = c * c * c;
                if ((bCubo + cCubo) > aCubo) {
                    break;
                }

                for (int d = c; d < a; d++) {
                    int dCubo = d * d * d;
                    if ((bCubo + cCubo + dCubo) == aCubo) {
                        matrix.push_back(make_tuple(a, b, c, d));
                    } else if ((bCubo + cCubo + dCubo) > aCubo) {
                        break;
                    }
                }
            }
        }
    }

    sort(matrix.begin(), matrix.end());

    for (int i = 0; i < matrix.size(); i++) {
        cout << "Cube = " << get<0>(matrix[i]) << ", Triple = (" << get<1>(matrix[i]) << "," << get<2>(matrix[i]) << "," << get<3>(matrix[i]) << ")\n";
    }

    return 0;
}
