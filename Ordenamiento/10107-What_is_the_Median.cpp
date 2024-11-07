#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int T;
    cin >> T;
    vector<int> arr;
    while (cin) {        
        arr.push_back(T);

        sort(arr.begin(), arr.end());

        int size = arr.size();
        int m = size / 2;

        if (size%2 != 0) {
            cout << arr[m] << endl;
        }
        else {
            int result = (arr[m] + arr[m-1]) /2;
            cout << result << endl;
        }  

        cin >> T;      
    }

    return 0;
}