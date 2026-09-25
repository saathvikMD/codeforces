#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        long long n, a, b;

        cin >> n >> a >> b;

        bool possible = false;
        long long power = 1;

        while (true) {
            if (power > n) {
                break;
            } else if ((n - power) % b == 0) {
                possible = true;

                break;
            }

            power *= a;

            if (a == 1) {
                break;
            }
        }

        if (n == 1) {
            possible = true;
        }

        if (possible) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
