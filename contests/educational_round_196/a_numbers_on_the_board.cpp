#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int l, r;

        cin >> l >> r;

        if (l <= 0 and r >= 0) {
            cout << max(0, (max(abs(l), abs(r)) - min(abs(l), abs(r))) - 1) << "\n";
        } else {
            cout << abs(l - r) << '\n';
        }
    }

    return 0;
}
