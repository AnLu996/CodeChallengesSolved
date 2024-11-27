#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string S;
    cin >> S;

    int n = S.length();
    int c = 0;

    for (int i = n-1; i > 0; i--) {
        if (S[i] < S[i-1] || S[i] == S[i-1] ) {
            c++;
            break;
        } 
        c++;
    }

    cout << n-c << endl;

    return 0;
}