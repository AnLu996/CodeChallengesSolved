#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    while(n--) {
        int produc, consu;
        cin >> produc >> consu;

        vector<int> Pro(produc);
        vector<int> Cons(consu);
        vector<int> Comb(produc + consu + 1);

        for (int i = 0; i < produc; ++i) {
            cin >> Pro[i];
            Comb[i] = Pro[i];
        }

        for (int i = 0; i < consu; ++i) {
            cin >> Cons[i];
            Comb[i + produc] = Cons[i];
        }

        Comb[produc + consu] = 0;

        sort(Pro.begin(), Pro.end());
        sort(Cons.begin(), Cons.end());
        sort(Comb.begin(), Comb.end());

        int oferta = 0;
        int min = INT_MAX;
        int ind_Pro = 0;
        int ind_Cons = 0;

        for (int i = 0; i <= produc + consu; ++i) {
            int actual = Comb[i];

            while (ind_Pro < produc && Pro[ind_Pro] <= actual) {
                ind_Pro++;
            }
            while (ind_Cons < consu && Cons[ind_Cons] < actual) {
                ind_Cons++;
            }

            int enojados = produc - ind_Pro + ind_Cons;

            if (enojados < min) {
                min = enojados;
                oferta = actual;
            }
        }

        cout << oferta << " " << min << "\n";
    }

    return 0;
}