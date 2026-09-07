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

        vector<char> answer(n, 'A');
        vector<char> groups = {'A', 'B', 'C'};
        int zero_count = 0;

        for (int i = 0; i < n; i++) {
            int temp;

            cin >> temp;

            if (temp == 0) {
                if (zero_count > 2) {
                    answer[i] = 'C';
                } else {
                    answer[i] = groups[zero_count];
                }

                zero_count += 1;
            } else if (temp == 1) {
                answer[i] = 'C';
            } else {
                answer[i] = 'B';
            }
        }

        if (zero_count == 1) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";

            for (int i = 0; i < n; i++) {
                cout << answer[i];
            }

            cout << "\n";
        }
    }

    return 0;
}
