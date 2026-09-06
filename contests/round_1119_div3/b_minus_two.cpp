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

        int odds = 0;
        int even_odds = 0;
        int even_evens = 0;

        for (int i = 0; i < n; i++) {
            long long temp;

            cin >> temp;

            if (temp % 2 == 1) {
                odds += 1;
            } else {
                if ((temp / 2) % 2 == 0) {
                    even_evens += 1;
                } else {
                    even_odds += 1;
                }
            }
        }

        cout << max({odds, even_evens, even_odds}) << "\n";
    }

    return 0;
}
