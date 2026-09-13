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

        vector<long long> ratings(n);

        for (int i = 0; i < n; i++) {
            cin >> ratings[i];
        }

        sort(ratings.begin(), ratings.end());

        vector<long long> before(n + 1);
        vector<long long> after(n + 1);
        long long divisor = 998244353;

        before[0] = 1;
        after[n] = 1;

        for (int i = 1; i < n; i++) {
            before[i] = (before[i - 1] * i) % divisor;
        }

        for (int i = n - 1; i >= 0; i--) {
            after[i] = (after[i + 1] * i) % divisor;
        }

        long long total_cost = 0;
        long long parents = 0;
        long long costs = 0;
        long long multiply = 0;

        for (int i = n - 2; i >= 0; i--) {
            parents += 1;
            costs = (costs + parents * (ratings[i + 1] - ratings[i])) % divisor;

            if (ratings[i] < ratings[i + 1]) {
                multiply = (before[parents - 1] * after[parents + 1]) % divisor;
            }

            total_cost = (total_cost + multiply * costs) % divisor;
        }

        cout << total_cost << "\n";
    }

    return 0;
}
