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

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<pair<int, int>> ranges;

        for (int i = 0; i < n; i++) {
            long long left_range = a[i] * (i + 1);
            long long right_range = min(a[i] * (i + 1) + (i + 1), n);

            if (left_range < n) {
                ranges.push_back({left_range, right_range});
            }
        }

        sort(ranges.begin(), ranges.end());

        vector<bool> possible(n, true);
        int possible_count = n;
        int prev_possible = 0;

        for (int i = 0; i < ranges.size(); i++) {
            for (int j = max(prev_possible, ranges[i].first); j < ranges[i].second; j++) {
                possible[j] = false;
                possible_count -= 1;
            }

            prev_possible = max(prev_possible, ranges[i].second);
        }

        cout << possible_count << "\n";

        bool started = false;
        
        for (int i = 0; i < n; i++) {
            if (possible[i]) {
                if (started) {
                    cout << " " << i;
                } else {
                    cout << i;

                    started = true;
                }
            }
        }

        cout << "\n";
    }

    return 0;
}
