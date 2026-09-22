#include <bits/stdc++.h>
using namespace std;

vector<int> primes(int x) {
    vector<int> p;

    for (int d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            p.push_back(d);

            while (x % d == 0) {
                x /= d;
            }
        }
    }

    if (x > 1) {
        p.push_back(x);
    }

    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> factors(200001);

    for (int i = 0; i < 200001; i++) {
        factors[i] = primes(i);
    }

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, k;

        cin >> n >> k;

        vector<int> numbers(n);
        int max_val = 0;

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];

            max_val = max(max_val, numbers[i]);
        }

        vector<int> optimal(n + 1, INT_MAX);

        for (int i = 0; i <= k; i++) {
            optimal[i] = 0;
        }

        for (int i = k + 1; i <= max_val; i++) {
            for (int j = 0; j < factors[i].size(); j++) {
                optimal[i] = min(optimal[i], 1 + factors[i][j] * optimal[i / factors[i][j]]);
            }
        }

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += optimal[numbers[i]];
        }

        cout << sum << "\n";
    }

    return 0;
}
