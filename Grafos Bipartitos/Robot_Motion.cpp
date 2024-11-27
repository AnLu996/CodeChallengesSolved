#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int filas, columnas, entrada;

    while (cin >> filas >> columnas >> entrada && filas && columnas && entrada) {
        
        vector<string> matrix(filas);
        for (int i = 0; i < filas; i++) {
            cin >> matrix[i];
        }

        vector<vector<int>> visitados(filas, vector<int>(columnas, -1));
        int steps = 0, loop_start = -1;
        int row = 0, col = entrada - 1;

        while (true) {
            if (row < 0 || row >= filas || col < 0 || col >= columnas) {
                cout << steps << " step(s) to exit" << endl;
                break;
            }

            if (visitados[row][col] != -1) {
                loop_start = visitados[row][col];
                cout << loop_start << " step(s) before a loop of " << steps - loop_start << " step(s)" << endl;
                break;
            }
            
            visitados[row][col] = steps++;
            char direction = matrix[row][col];

            if (direction == 'N') {
                row--;
            }
            else if (direction == 'S') {
                row++;
            }
            else if (direction == 'E') {
                col++;
            }
            else if (direction == 'W') {
                col--;
            }
        }
    }
    return 0;
}
