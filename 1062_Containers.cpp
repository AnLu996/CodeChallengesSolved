#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    int count = 1;

    while (cin >> input && input != "end") {
        vector<char> pila;

        for (int j = 0; j < input.size(); j++) {
            bool add = false;         

            for (int k = 0; k  < pila.size(); k++){
                /*if (pila.empty()) {
                    break;
                }*/

                if (input[j] <= pila[k]) {
                    pila[k] = input[j];
                    add = true;
                    break;
                }
            }   

            if (!add) {
                pila.push_back(input[j]);
            }
        }
        
        cout << "Case " << count << ": " << pila.size() << endl;
        count++;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          
    }

    return 0;
}