#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    bool firstCase = true;

    while (cin >> k && k != 0) {
        vector<int> S(k);
        for (int i = 0; i < k; i++) {
            cin >> S[i];
        }

        vector<int> array(6);

        if (!firstCase) {
            cout << "\n"; 
        }
        firstCase = false;

        for (int i = 0; i < k - 5; i++) {
            array[0] = S[i];
            for (int j = i + 1; j < k - 4; j++) {
                array[1] = S[j];
                for (int m = j + 1; m < k - 3; m++) {
                    array[2] = S[m];
                    for (int n = m + 1; n < k - 2; n++) {
                        array[3] = S[n];
                        for (int p = n + 1; p < k - 1; p++) {
                            array[4] = S[p];
                            for (int q = p + 1; q < k; q++) {
                                array[5] = S[q];
                                cout << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << " " << array[5] << "\n";
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}
