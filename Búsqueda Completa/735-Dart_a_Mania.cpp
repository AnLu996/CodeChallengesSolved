#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream> // Incluyendo sstream para usar stringstream

using namespace std;

// Posibles puntajes que se pueden obtener con un tiro de dardo
const vector<int> scores = [] {
    vector<int> temp{0}; // Puntaje 0
    for (int i = 1; i <= 20; ++i) {
        temp.push_back(i);       // Puntaje normal
        temp.push_back(i * 2);   // Doble
        temp.push_back(i * 3);   // Triple
    }
    temp.push_back(50); // Bull's eye
    return temp;
}();

pair<int, int> calculate_combinations_and_permutations(int target_score) {
    unordered_set<string> unique_combinations; // Para guardar combinaciones únicas
    vector<int> darts(3); // Para almacenar puntajes de los tres dardos

    // Generar todas las combinaciones posibles de 3 dardos
    for (int i = 0; i < scores.size(); ++i) {
        for (int j = i; j < scores.size(); ++j) {
            for (int k = j; k < scores.size(); ++k) {
                int sum = scores[i] + scores[j] + scores[k];
                if (sum == target_score) {
                    // Guardar combinación única
                    darts[0] = scores[i];
                    darts[1] = scores[j];
                    darts[2] = scores[k];
                    sort(darts.begin(), darts.end()); // Ordenar para asegurar unicidad
                    unique_combinations.insert(to_string(darts[0]) + "," + to_string(darts[1]) + "," + to_string(darts[2]));
                }
            }
        }
    }

    // Contar combinaciones
    int combination_count = unique_combinations.size();
    int permutation_count = 0;

    // Contar permutaciones para cada combinación única
    for (const string& comb : unique_combinations) {
        int count[3] = {0};
        int distinct_count = 0;

        // Contar cuántos números distintos hay en la combinación
        stringstream ss(comb);
        string part; // Cambiamos comb a part para leer cada parte
        while (getline(ss, part, ',')) { // Cambiamos comb a part aquí
            int num = stoi(part);
            count[num == darts[0] ? 0 : (num == darts[1] ? 1 : 2)]++;
        }

        // Calcular el número de permutaciones
        if (count[0] == 3) {
            permutation_count += 1; // 3 iguales
        } else if (count[0] == 2 || count[1] == 2) {
            permutation_count += 3; // 2 iguales, 1 diferente
        } else {
            permutation_count += 6; // 3 diferentes
        }
    }

    return {combination_count, permutation_count};
}

int main() {
    vector<int> input_scores;
    int score;

    // Leer las puntuaciones de entrada
    while (cin >> score && score > 0) {
        input_scores.push_back(score);
    }

    // Procesar cada puntuación
    for (int target_score : input_scores) {
        auto [combination_count, permutation_count] = calculate_combinations_and_permutations(target_score);
        
        if (combination_count > 0) {
            cout << "NUMBER OF COMBINATIONS THAT SCORES " << target_score << " IS " << combination_count << ".\n";
            cout << "NUMBER OF PERMUTATIONS THAT SCORES " << target_score << " IS " << permutation_count << ".\n";
        } else {
            cout << "THE SCORE OF " << target_score << " CANNOT BE MADE WITH THREE DARTS.\n";
        }

        cout << string(70, '*') << "\n";
    }

    cout << "END OF OUTPUT\n";
    return 0;
}
