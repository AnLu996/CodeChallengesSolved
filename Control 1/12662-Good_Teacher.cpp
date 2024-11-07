#include <iostream>
#include <string>

using namespace std;

string s[105];
int n, q;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
    }
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        if (s[x] != "?") {
            cout << s[x] << endl;
        } else {
            int ld = 1000;
            int rd = 1000;
            string ln, rn;

            for (int i = x - 1; i > 0; i--) {
                if (s[i] != "?") {
                    ln = s[i];
                    ld = x - i;
                    break;
                }
            }

            for (int i = x + 1; i <= n; i++) {
                if (s[i] != "?") {
                    rn = s[i];
                    rd = i - x;
                    break;
                }
            }

            if (ld == rd) {
                cout << "middle of " << ln << " and " << rn << endl;
            } else {
                if (ld < rd) for (int i = 0; i < ld; i++) cout << "right of ";
                else for (int i = 0; i < rd; i++) cout << "left of ";
                if (ld < rd) cout << ln << endl;
                else cout << rn << endl;
            }
        }
    }
    return 0;
}
