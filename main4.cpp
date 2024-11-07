#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}
int main() {
    fast();
    vector<int> seq;
    int num;


    while (cin >> num) {
        seq.push_back(num);
    }

    int n = seq.size();
    if (n == 0) {
        cout << "0\n-\n";
        return 0;
    }

    vector<int> dp(n, 1);
    vector<int> predecessor(n, -1); 

    int max_length = 0;
    int last_index = -1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (seq[i] > seq[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
                predecessor[i] = j;
            }
        }
        if (dp[i] > max_length) {
            max_length = dp[i];
            last_index = i;
        } else if (dp[i] == max_length) {
            last_index = i;
        }
    }

    vector<int> lis;
    while (last_index != -1) {
        lis.push_back(seq[last_index]);
        last_index = predecessor[last_index];
    }

    reverse(lis.begin(), lis.end());


    cout << max_length << "\n-\n";
    for (int i : lis) {
        cout << i << "\n";
    }

    return 0;
}
