#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int hammingDistance(const string &s1, const string &s2) {
    int distance = 0;
    for (size_t i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]) {
            ++distance;
        }
    }
    return distance;
}

int main() {
    int M, Q;
    cin >> M >> Q;

    vector<string> movies(M);
    for (int i = 0; i < M; ++i) {
        cin >> movies[i];
    }

    for (int k = 0; k < Q; ++k) {
        string clip;
        cin >> clip;
        int clipLength = clip.size();
        
        int best_index = -1;
        int min_distance = INT_MAX;

        for (int i = 0; i < M; ++i) {
            const string &movie = movies[i];
            int movieLength = movie.size();

            for (int j = 0; j <= movieLength - clipLength; ++j) {
                string substring = movie.substr(j, clipLength);
                int distance = hammingDistance(clip, substring);

                if (distance < min_distance) {
                    min_distance = distance;
                    best_index = i + 1;
                }
            }
        }

        cout << best_index << endl;
    }

    return 0;
}
