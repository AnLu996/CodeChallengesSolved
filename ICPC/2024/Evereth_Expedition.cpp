/*// FALTA IMPLEMENTAR

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int main() {
    int N;
    cin >> N;

    set<int> map;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        map.insert(temp);
    }

    vector<int> disponible;

    for (int i = 1; i < N+1; i++) {
        if (map.find(i) == map.end()) {
            disponible.push_back(i);
        }
    }

    int pos_big;
    int temp = *map.begin();

    for (int i = 1; i < N; i++) {
        

    

    return 0;
}*/

// FALTA MODIFICAR EL ÚLTIMO CASO PARA EL OUTPUT

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

bool isValidItinerary(const vector<int>& itinerary) {
    int n = itinerary.size();
    int peak = 0;

    // Find the peak index
    for (int i = 1; i < n; ++i) {
        if (itinerary[i] > itinerary[i - 1]) {
            peak = i;
        } else {
            break;
        }
    }

    // Check if it ascends correctly
    for (int i = 1; i <= peak; ++i) {
        if (itinerary[i] <= itinerary[i - 1]) {
            return false;
        }
    }

    // Check if it descends correctly
    for (int i = peak + 1; i < n; ++i) {
        if (itinerary[i] >= itinerary[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    int N;
    cin >> N;
    vector<int> itinerary(N);
    set<int> missingStations;

    // Input itinerary and find missing stations
    for (int i = 1; i <= N; ++i) {
        missingStations.insert(i);
    }

    for (int i = 0; i < N; ++i) {
        cin >> itinerary[i];
        if (itinerary[i] != 0) {
            missingStations.erase(itinerary[i]);
        }
    }

    // Try all permutations of missing stations to fill the blanks
    vector<int> missing(missingStations.begin(), missingStations.end());
    sort(missing.begin(), missing.end());

    do {
        vector<int> filledItinerary = itinerary;
        auto it = missing.begin();

        for (int i = 0; i < N; ++i) {
            if (filledItinerary[i] == 0) {
                filledItinerary[i] = *it;
                ++it;
            }
        }

        if (isValidItinerary(filledItinerary)) {
            for (int x : filledItinerary) {
                cout << x << " ";
            }
            cout << endl;
            return 0;
        }
    } while (next_permutation(missing.begin(), missing.end()));

    // If no valid itinerary is found
    cout << "*" << endl;
    return 0;
}
