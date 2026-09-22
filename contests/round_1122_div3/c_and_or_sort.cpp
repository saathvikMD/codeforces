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

        string s;

        cin >> s;

        vector<int> zeroes(n);
        int curr_zeroes = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                curr_zeroes += 1;
            }

            zeroes[i] = curr_zeroes;
        }

        if (s[0] == '1') {
            cout << zeroes[n - 1] << "\n";
        } else {
            int operations = 0;
            int best_operations = n;

            for (int i = 0; i < n; i++) {
                if (s[i] == '1') {
                    if (zeroes[n - 1] - zeroes[i] > n - 1 - i - (zeroes[n - 1] - zeroes[i])) {
                        operations += 1;
                    } else {
                        if (operations + zeroes[n - 1] - zeroes[i] < best_operations) {
                            best_operations = operations + zeroes[n - 1] - zeroes[i];
                        }

                        operations += 1;
                    }
                }
            }

            cout << min(operations, best_operations) << "\n";
        }
    }

    return 0;
}
