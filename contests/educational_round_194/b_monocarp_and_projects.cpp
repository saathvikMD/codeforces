#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        long long x, y, k;

        cin >> x >> y >> k;

        long long day = 0;
        long long sum = 0;

        while (day < k) {
            long long remainder = y % x;

            if (x > y - x) {
                sum += remainder * (k - day);
                break;
            }

            sum += remainder;
            x += 1;
            y += 1;
            day += 1;
        }

        cout << sum << "\n";
    }

    return 0;
}
