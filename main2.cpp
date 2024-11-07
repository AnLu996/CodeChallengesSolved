#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int L, S;
    int num_cases = 1;

    while (cin >> L >> S && L > 0 && S > 0) {
        vector<vector<int>> matrix(S, vector<int>(L, 0));
        int sum = 0;
        
        for (int i = 0; i < L - 1; i++) {
            matrix[0][i] = i + 1;
            sum += matrix[0][i];
        }

        int last = S - sum;
        matrix[0][L - 1] = last; 

        for (int i = 1; i < S; i++) {
            for (int k = 0; k < L - 1; k++) {
                matrix[i][k] = matrix[i - 1][k] + 1;
            }
            matrix[i][L - 1] = matrix[i - 1][L - 1] - 2;
        }
        
        /*
        cout << "Matrix for Case " << num_cases << ":" << endl;
        for (int i = 0; i < S; i++) {
            for (int j = 0; j < L; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
        */

        

        int count = 0;
        for (int i = 0; i < S; i++) {
            //sort(matrix[i].begin(), matrix[i].end());
            //if (matrix[i][0] > 0) {
            if (0 < matrix[i][L - 1]) {
                count++;
            }
        }

        cout << "Case " << num_cases << ": " << count << endl;

        num_cases++;
    }

    return 0;
}
