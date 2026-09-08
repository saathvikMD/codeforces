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

        vector<int> numbers(n);
        int zero = 0;

        for (int i = 0; i < n; i++) {
            int temp;

            cin >> temp;

            if (temp == 0) {
                zero += 1;
            }

            numbers[i] = temp;
        }

        if (zero >= 2) {
            cout << (numbers[0] == 1 ? 1 : 0) + (numbers[n - 1] == 1 ? 1 : 0) << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
