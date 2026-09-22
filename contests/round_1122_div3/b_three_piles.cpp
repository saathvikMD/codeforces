#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        long long a, b, c;

        cin >> a >> b >> c;

        if (b <= a) {
            cout << abs(a + c - b) << "\n";
        } else if (b > a) {
            if (abs(a + c - b) > abs(b - a)) {
                cout << abs(a + c - b) << "\n";
            } else {
                cout << abs(b - a) << "\n";
            }
        }
    }

    return 0;
}
