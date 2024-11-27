/*// FALTA IMPLEMENTAR

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> map;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        map.insert(temp);
    }

    vector<int> disponible;

    for (int i = 1; i < N+1; i++) {
        if (map.find(i) == map.end()) {
            disponible.push_back(i);
        }
    }

    int pos_big;
    int temp = *map.begin();

    for (int i = 1; i < N; i++) {
        

    

    return 0;
}*/