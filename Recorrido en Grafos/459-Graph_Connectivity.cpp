#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

// Function to perform DFS and mark connected nodes
void dfs(char node, map<char, set<char>>& graph, set<char>& visited) {
    visited.insert(node);
    for (char neighbor : graph[node]) {
        if (visited.find(neighbor) == visited.end()) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    int testCases;
    cin >> testCases;
    cin.ignore(); // Ignore the newline after the number of test cases
    
    bool firstCase = true;
    
    while (testCases--) {
        if (!firstCase) cout << "\n";
        firstCase = false;

        string line;
        
        // Read the largest node, which defines the range of nodes
        getline(cin, line); // Read empty line between cases
        getline(cin, line);
        char largestNode = line[0];

        // Initialize the graph
        map<char, set<char>> graph;
        for (char node = 'A'; node <= largestNode; ++node) {
            graph[node] = set<char>();
        }

        // Read the edges
        while (getline(cin, line) && !line.empty()) {
            char u = line[0], v = line[1];
            graph[u].insert(v);
            graph[v].insert(u);
        }

        // Count the number of connected components
        set<char> visited;
        int components = 0;

        for (char node = 'A'; node <= largestNode; ++node) {
            if (visited.find(node) == visited.end()) {
                // New connected component found
                dfs(node, graph, visited);
                components++;
            }
        }

        // Output the number of components for this test case
        cout << components << "\n";
    }
    
    return 0;
}
