#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, k;

        cin >> n >> k;

        cout << 2 * (k - 1) + (long long) pow(2, n - k + 1) << "\n";
    }

    return 0;
}
