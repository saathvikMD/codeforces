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

        vector<long long> costs(n);
        vector<long long> total(n);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> costs[i];
            sum += costs[i];
            total[i] = sum;
        }

        long long minimum = sum;

        for (int i = 1; i < n - 1; i++) {
            int low = i;
            int high = n - 2;

            while (low <= high) {
                int mid = (low + high) / 2;

                if (total[mid] >= sum - total[mid] + total[i - 1]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            for (long long j = max(0, low - 1); j <= min(high + 1, n - 2); j++) {
                minimum = min(minimum, max({total[j], sum - total[i - 1], sum - total[j] + total[i - 1]}));
            }
        }

        cout << minimum << "\n";
    }

    return 0;
}
