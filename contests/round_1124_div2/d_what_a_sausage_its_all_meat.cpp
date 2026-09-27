#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, q;

        cin >> n >> q;

        vector<int> numbers(n);
        vector<int> possible = {0, 3, 5, 6, 9, 10, 12, 15};
        vector<int> impossible = {1, 2, 4, 7, 8, 11, 13, 14};
        vector<int> group(n, 0);
        int sum = 0;

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];

            if (find(possible.begin(), possible.end(), numbers[i]) != possible.end()) {
                group[i] = 1;
                sum += 1;
            }
        }

        cout << sum << " ";

        for (int i = 0; i < q; i++) {
            int p, x;

            cin >> p >> x;

            if (find(possible.begin(), possible.end(), x) != possible.end()) {
                if (group[p - 1] == 0) {
                    sum += 1;
                    group[p - 1] = 1;
                }
            } else {
                if (group[p - 1] == 1) {
                    sum -= 1;
                    group[p - 1] = 0;
                }
            }

            cout << sum << " ";
        }

        cout << "\n";
    }

    return 0;
}
