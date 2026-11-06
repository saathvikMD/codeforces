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

        int all_xor = 0;

        for (int i = 0; i < n; i++) {
            all_xor ^= (i + 1);
        }

        vector<bool> do_double(n, false);

        for (int i = n; i >= 1; i--) {
            if ((all_xor ^ i ^ (i * 2)) > all_xor) {
                do_double[i - 1] = true;
                all_xor = all_xor ^ i ^ (i * 2);
            }
        }

        for (int i = 0; i < n; i++) {
            cout << do_double[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}
