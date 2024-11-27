#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();  // Ignorar el salto de línea después del número de casos
    string str;
    getline(cin, str);  // Ignorar la línea en blanco inicial

    while (t--) {
        vector<set<char>> groups;
        unordered_set<char> allNodes;  // Conjunto para rastrear todos los nodos
        char largestNode;

        // Leer el nodo más grande
        cin >> largestNode;
        cin.ignore();

        // Agregar todos los nodos al conjunto de nodos totales
        for (char node = 'A'; node <= largestNode; node++) {
            allNodes.insert(node);
        }

        // Leer todos los pares de caracteres en la entrada hasta el cambio de caso.
        while (getline(cin, str) && !str.empty()) {
            char first = str[0];
            char second = str[1];
            bool merged = false;

            // Intentar agregar el par a uno de los grupos existentes.
            for (auto& group : groups) {
                if (group.count(first) || group.count(second)) {
                    group.insert(first);
                    group.insert(second);
                    merged = true;
                    break;
                }
            }

            // Si no se pudo agregar a ningún grupo, crear uno nuevo.
            if (!merged) {
                set<char> newGroup = {first, second};
                groups.push_back(newGroup);
            }

            // Remover los nodos conectados del conjunto de nodos individuales
            allNodes.erase(first);
            allNodes.erase(second);
        }

        // Agregar cada nodo individual como un grupo propio
        for (char node : allNodes) {
            groups.push_back({node});
        }

        // Imprimir el resultado para este caso
        cout << groups.size() << endl;

        // Imprimir una línea en blanco entre casos, excepto al final
        if (t > 0) {
            cout << endl;
        }
    }

    return 0;
}
