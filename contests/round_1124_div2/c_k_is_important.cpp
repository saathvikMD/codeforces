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

        vector<int> numbers(n);
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];

            if (i >= k - 1 and i <= n - k) {
                sum += numbers[i];
            }
        }

        long long max_extra = 0;

        for (int i = 0; i < min(k - 1, n - k + 1); i++) {
            max_extra += max(numbers[i], numbers[n - 1 - i]);
        }

        cout << sum + max_extra << "\n";
    }

    return 0;
}
