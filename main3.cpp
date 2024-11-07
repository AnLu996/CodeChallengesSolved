#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    int chain_num = 1;
    while (true) {
        int n, k;
        cin >> n >> k;
        
        if (n == 0 && k == 0) break;
        
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            cin >> d[i];
        }

        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int median = d[(i + j) / 2];
                for (int l = i; l <= j; l++) {
                    cost[i][j] += abs(d[l] - median);
                }
            }
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, numeric_limits<int>::max()));
        vector<vector<int>> trace(n + 1, vector<int>(k + 1, -1));


        for (int i = 0; i <= k; i++) {
            dp[0][i] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int m = 0; m < i; m++) {
                    int current_cost = dp[m][j - 1] + cost[m][i - 1];
                    if (current_cost < dp[i][j]) {
                        dp[i][j] = current_cost;
                        trace[i][j] = m;
                    }
                }
            }
        }


        vector<pair<int, pair<int, int>>> result;
        int i = n;
        for (int j = k; j > 0; j--) {
            int start = trace[i][j];
            int depot_position = (start + i - 1) / 2;
            result.push_back({depot_position, {start + 1, i}});
            i = start;
        }
        reverse(result.begin(), result.end());


        cout << "Chain " << chain_num++ << endl;
        for (int i = 0; i < result.size(); i++) {
            int depot = result[i].first + 1;
            int start = result[i].second.first;
            int end = result[i].second.second;
            cout << "Depot " << i + 1 << " at restaurant " << depot << " serves restaurants " << start << " to " << end << endl;
        }
        cout << "Total distance sum = " << dp[n][k] << endl << endl;
    }
    return 0;
}
