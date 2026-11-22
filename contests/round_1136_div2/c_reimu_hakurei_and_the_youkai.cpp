#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        long long n, x;

        cin >> n >> x;

        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        long long cards = 0;
        long long reduce = 0;

        for (int i = 0; i < n - 1; i++) {
            a[i] -= reduce;

            if (a[i] <= x) {
                reduce += x;
            } else if (a[i] % x == 0) {
                cards += a[i] / x - 1;
                reduce += (a[i] / x) * x;
            } else {
                cards += a[i] / x;
                reduce += (a[i] / x + 1) * x;
            }
        }

        cout << cards << "\n";
    }

    return 0;
}
