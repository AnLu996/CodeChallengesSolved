#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define M_PI 3.141592653589793

using namespace std;

int main() {
    int ang, N;
    cin >> ang >> N;

    double angle_rad = ang * M_PI / 180.0;

    vector<pair<int, double>> terraplanistas;
    for (int i = 0; i < N; i++) {
        int X, H;
        cin >> X >> H;
        double sombra = H / tan(angle_rad);
        terraplanistas.push_back({X, X + sombra});
    }

    sort(terraplanistas.begin(), terraplanistas.end());

    double longitud_cubierta = 0.0;
    double fin_actual = 0.0;

    for (const auto& terraplanista : terraplanistas) {
        double inicio_sombra = terraplanista.first;
        double fin_sombra = terraplanista.second;

        if (inicio_sombra > fin_actual) {
            longitud_cubierta += fin_sombra - inicio_sombra;
        } else if (fin_sombra > fin_actual) {
            longitud_cubierta += fin_sombra - fin_actual;
        }

        fin_actual = max(fin_actual, fin_sombra);
    }

    cout.precision(10);
    cout << fixed << longitud_cubierta << endl;

    return 0;
}
