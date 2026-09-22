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

        vector<int> pos(n);

        for (int i = 0; i < n; i++) {
            int temp;

            cin >> temp;

            pos[i] = temp - i - 1;
        }

        sort(pos.begin(), pos.end());

        int prev_value = pos[0] - 1;
        int curr_length = 0;
        int max_length = 0;

        for (int i = 0; i < n; i++) {
            if (pos[i] - prev_value == 1) {
                curr_length += 1;
            } else if (pos[i] - prev_value != 0) {
                max_length = max(curr_length, max_length);
                curr_length = 1;
            }

            prev_value = pos[i];
        }

        max_length = max(curr_length, max_length);

        cout << max_length << "\n";
    }

    return 0;
}
