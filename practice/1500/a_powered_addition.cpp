#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n;

        cin >> n;

        vector<int> a(n);
        vector<int> maxs(n);
        int curr_max = INT_MIN;

        for (int i = 0; i < n; i++) {
            cin >> a[i];

            curr_max = max(curr_max, a[i]);
            maxs[i] = curr_max;
        }

        int seconds = 0;

        for (int i = n - 1; i >= 0; i--) {
            int remaining = maxs[i] - a[i];

            if (remaining >= 1) {
                int exponent = 0;

                while ((1LL << (exponent + 1)) <= remaining) {
                    exponent += 1;
                }

                seconds = max(seconds, exponent + 1);
            }
        }

        cout << seconds << "\n";
    }

    return 0;
}
