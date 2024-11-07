#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map> 

using namespace std;

int main() {
    string letras;

    cin >> letras;
    
    vector<int> nombre(6, 0); 

    for(const char i : letras) {
        if (i == 'm') 
            nombre[0] = nombre[0] + 1;
        else if (i == 'i') 
            nombre[1] = nombre[1] + 1;
        else if (i == 'g') 
            nombre[2] = nombre[2] + 1;
        else if (i == 'u') 
            nombre[3] = nombre[3] + 1;
        else if (i == 'e') 
            nombre[4] = nombre[4] + 1;
        else if (i == 'l') 
            nombre[5] = nombre[5] + 1;
        else 
            ;         
    }

    sort(nombre.begin(), nombre.end());

    cout << nombre[0] << endl;

    return 0;
}