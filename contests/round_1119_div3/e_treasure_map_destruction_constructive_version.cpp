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

        vector<bool> locations(n, 0);
        vector<int> distances(n, 0);
        vector<int> original(n);
        bool info = false;

        for (int i = 0; i < n; i++) {
            int distance;

            cin >> distance;

            original[i] = distance;

            if (distance != -1) {
                if (i - distance >= 0) {
                    locations[i - distance] = 1;
                }

                if (i + distance < n) {
                    locations[i + distance] = 1;
                }

                if (distance == 1) {
                    distances[i] = (distances[i] == 0 ? -1 : distances[i]);
                } else if (distance > 0) {
                    distances[max(i - distance + 1, 0)] = max(distances[max(i - distance + 1, 0)], i + distance - 1 - max(i - distance + 1, 0));
                }

                info = true;
            }
        }

        if (info) {
            int wait = 0;

            vector<int> treasure(n, 0);
            bool passed = false;

            for (int i = 0; i < n; i++) {
                if (distances[i] != 0) {
                    wait = max(wait, distances[i] + 1);
                } else if (wait <= 0 and locations[i]) {
                    treasure[i] = 1;
                    passed = true;
                }

                wait -= 1;
            }

            for (int i = 0; i < n; i++) {
                if (original[i] != -1) {
                    if (not ((i - original[i] >= 0 and treasure[i - original[i]] == 1) or (i + original[i] < n and treasure[i + original[i]] == 1))) {
                        passed = false;
                        break;
                    }
                }
            }

            if (passed) {
                for (int i = 0; i < n - 1; i++) {
                    cout << treasure[i];
                }

                cout << treasure[n - 1] << "\n";
            } else {
                cout << -1 << "\n";
            }
        } else {
            for (int i = 0; i < n - 1; i++) {
                cout << 1;
            }

            cout << 1 << "\n";
        }
    }

    return 0;
}
