#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int x, y, m;

        cin >> x >> y >> m;

        string spell;

        cin >> spell;

        int maximum = x + y;

        for (int i = 0; i < m; i++) {
            if (spell[i] == '+') {
                if (y >= 1) {
                    y += 1;
                } else {
                    y += 1;
                    x -= 1;
                }
            } else {
                if (y > 1) {
                    y -= 1;
                    x += 1;
                } else if (x == 0) {
                    y -= 1;
                    x += 1;
                } else {
                    x -= 1;
                }
            }

            if (x + y == 0) {
                break;
            }

            maximum = max(maximum, x + y);
        }
        
        cout << maximum << "\n";
    }

    return 0;
}
