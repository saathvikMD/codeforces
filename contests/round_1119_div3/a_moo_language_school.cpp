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

        string fields;

        cin >> fields;

        int nhoj = 0;

        for (int i = 0; i < n; i += k) {
            bool passed = false;

            for (int j = i; j < i + k; j += 1) {
                if (fields[j] == '0') {
                    passed = true;
                    break;
                }
            }

            if (not passed) {
                nhoj += 1;
            }
        }

        cout << nhoj << "\n";
    }

    return 0;
}
