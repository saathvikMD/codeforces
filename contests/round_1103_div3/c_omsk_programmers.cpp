#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;

    cin >> t;

    for (long long iteration = 0; iteration < t; iteration++) {
        long long a, b, x;

        cin >> a >> b >> x;

        long long moves = INT_MAX;
        long long count_a = 0, count_b = 0;

        for (long long i = a; i > 0; i /= x) {
            count_b = 0;

            for (long long j = b; j > 0; j /= x) {
                moves = min(abs(i - j) + count_a + count_b, moves);
                count_b += 1;
            }

            moves = min(i + count_a + count_b, moves);
            count_a += 1;
        }

        count_b = 0;

        for (long long j = b; j > 0; j /= x) {
            moves = min(j + count_a + count_b, moves);
            count_b += 1;
        }

        moves = min(count_a + count_b, moves);
        cout << moves << "\n";
    }

    return 0;
}
