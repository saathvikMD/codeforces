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

        string test = "";

        for (int i = 0; i < n; i++) {
            test += "+--";
        }

        cout << test << endl;

        int k;

        cin >> k;

        if (k == -1) {
            break;
        } else if (k == 0) {
            cout << n << endl;
        } else {
            cout << n + (k - 1) / 3 + 1 << endl;
        }
    }

    return 0;
}
