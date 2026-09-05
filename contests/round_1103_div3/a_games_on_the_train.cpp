#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;

        cin >> n;

        int min_height = INT_MAX;
        int max_height = INT_MIN;

        for (int j = 0; j < n; j++) {
            int h;

            cin >> h;

            if (h < min_height) {
                min_height = h;
            }

            if (h > max_height) {
                max_height = h;
            }
        }

        cout << max_height - min_height + 1 << "\n";
    }

    return 0;
}
