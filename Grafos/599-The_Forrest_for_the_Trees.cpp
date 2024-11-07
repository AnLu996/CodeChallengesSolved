#include <iostream>
#include <set>
#include <unordered_map>
#include <string>

using namespace std;

char search(char x, unordered_map<char, char>& padre) {
    if (padre[x] == x)
        return x;
    return padre[x] = search(padre[x], padre);
}

void unir(char x, char y, unordered_map<char, char>& padre, unordered_map<char, int>& size) {
    char rootX = search(x, padre);
    char rootY = search(y, padre);
    if (rootX != rootY) {
        if (size[rootX] < size[rootY])
            swap(rootX, rootY);
        padre[rootY] = rootX;
        size[rootX] += size[rootY];
    }
}

int main() {
    int N;
    cin >> N;
    while (N--) {
        set<pair<char, char>> edges;
        set<char> vertices;
        string in;
        while (cin >> in && in[0] != '*') {
            if (in == "") continue;
            char left = in[1];
            char right = in[3];
            edges.insert({left, right});
        }
        string vs;
        cin >> vs;
        for (char vertex : vs) {
            if (vertex != ',') {
                vertices.insert(vertex);
            }
        }

        unordered_map<char, char> padre;
        unordered_map<char, int> size;
        for (char v : vertices) {
            padre[v] = v;
            size[v] = 1;
        }

        for (auto edge : edges) {
            unir(edge.first, edge.second, padre, size);
        }

        set<char> uniqueTrees;
        int acorns = 0;
        for (char v : vertices) {
            if (padre[v] == v && size[v] == 1) {
                acorns++;
            } else {
                uniqueTrees.insert(search(v, padre));
            }
        }
        cout << "There are " << uniqueTrees.size() << " tree(s) and " << acorns << " acorn(s)." << endl;
    }

    return 0;
}
