#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int C;
    cin >> C;

    for (int case_num = 1; case_num <= C; ++case_num) {
        int N, H, Ta, Td;
        cin >> N >> H >> Ta >> Td;

        vector<int> heights(N);
        for (int i = 0; i < N; ++i) {
            cin >> heights[i];
        }

        // Sort the hippos' heights in ascending order
        sort(heights.begin(), heights.end());

        int total_time = 0;
        int left = 0;
        int right = N - 1;

        while (left <= right) {
            if (left == right) {  // Only one hippo left
                total_time += Ta;
                break;
            }
            // Check if the smallest (left) and largest (right) hippos can go together
            if (heights[left] + heights[right] < H) {
                // They can go together
                total_time += Td;
                left++;  // Move left pointer up
                right--; // Move right pointer down
            } else {
                // Only the largest hippo (right) goes alone
                total_time += Ta;
                right--;
            }
        }

        cout << "Case " << case_num << ": " << total_time << "\n";
    }

    return 0;
}
