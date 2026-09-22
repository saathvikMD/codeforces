#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        long long n, k;

        cin >> n >> k;

        cout << ((k - 1) / (n - 1)) * n + ((k - 1) % (n - 1) + 1) << "\n";
    }

    return 0;
}
