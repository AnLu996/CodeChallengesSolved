#include <iostream>
#include <string>
using namespace std;

pair<int, string> makeKoolString(int K, string S) {
    int flips = 0;
    int n = S.size();
    for (int i = 0; i < n; ) {
        char current = S[i];
        int j = i;

        // Find the length of the current group of identical characters
        while (j < n && S[j] == current) {
            ++j;
        }

        int groupLength = j - i;

        // If group length >= K, perform flips
        if (groupLength >= K) {
            for (int pos = i + K - 1; pos < j; pos += K) {
                S[pos] = (S[pos] == '0' ? '1' : '0'); // Flip the character
                ++flips;
            }
        }

        // Move to the next group
        i = j;
    }
    return {flips, S};
}

int main() {
    int K;
    string S;
    cin >> K >> S;

    auto result = makeKoolString(K, S);
    cout << result.first << " " << result.second << endl;

    return 0;
}
