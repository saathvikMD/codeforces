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

        int zeros = 0;
        int ones = 0;

        for (int i = 0; i < n; i++) {
            int temp;

            cin >> temp;

            if (temp == 0) {
                zeros += 1;
            } else {
                ones += 1;
            }
        }

        if (ones >= zeros) {
            cout << "Bessie" << "\n";
        } else {
            cout << "Elsie" << "\n";
        }
    }

    return 0;
}
