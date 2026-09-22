#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        long long n;

        cin >> n;

        bool possible = false;

        while (true) {
            if (n % 2 == 0) {
                n /= 2;
            } else if (n > 1) {
                possible = true;

                break;
            } else {
                break;
            }
        }

        if (possible) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
