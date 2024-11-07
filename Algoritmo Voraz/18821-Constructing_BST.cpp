#include <iostream>
#include <cmath>

using namespace std;

void BST (int izq, int der, int H) {
    if (H == 0 || izq > der) {
        return;
    }

    int espacio = pow(2, H-1)-1;
    int root = der - espacio;

    if (root < izq) {
        root = izq;
    }

    cout << " " << root;

    BST(izq, root-1, H-1);
    BST(root+1, der, H-1);
}

int main() {
    int caso = 1;
    int N, H;

    while (cin >> N, cin >> H, N!= 0 && H != 0) {
        cout << "Case " << caso << ":";
        caso ++;
        if (pow(2,H) - 1 < N) {
            cout << " Imposible.\n";
            continue;
        }

        if(H > N) {
            H = N;
        }

        BST(1, N, H);
        cout << endl;
    }

}