#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, k;

        cin >> n >> k;

        string binary;

        cin >> binary;

        for (int j = 0; j < n - k; j++) {
            if (binary[j] != '0') {
                binary[j] = '0';
                binary[j + k] = (binary[j + k] == '0' ? '1' : '0');
            }
        }

        bool possible = true;

        for (int j = n - k; j < n; j++) {
            if (binary[j] == '1') {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
