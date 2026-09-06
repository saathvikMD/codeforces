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

        int distance = 0;
        int backup_start = -1;
        int backup_end = -1;
        int start = 0;
        int prev = -1;
        bool started = false;

        for (int i = 0; i < n; i++) {
            int temp;
            
            cin >> temp;

            a[i] = temp;

            if (started) {
                if (temp == 1) {
                    if (i - start + 1 > distance) {
                        distance = i - start + 1;
                        backup_start = start;
                        backup_end = i;
                    }

                    start = i;
                } else if (temp == -1) {
                    prev = i;
                }
            } else if (temp == -1 or temp == 1) {
                started = true;
                start = i;
                distance = 1;
                backup_start = i;
                backup_end = i;
            }

            if (prev > start and prev - start + 1 > distance) {
                distance = prev - start + 1;
                backup_start = start;
                backup_end = prev;
            }
        }

        for (int j = 0; j < n - 1; j++) {
            if (j == backup_start or j == backup_end) {
                cout << 1 << " ";
            } else if (j > backup_start and j < backup_end) {
                cout << 0 << " ";
            } else {
                if (a[j] == -1) {
                    cout << 0 << " ";
                } else {
                    cout << a[j] << " ";
                }
            }
        }

        if (n - 1 == backup_start or n - 1 == backup_end) {
            cout << 1 << "\n";
        } else if (n - 1 > backup_start and n - 1 < backup_end) {
            cout << 0 << "\n";
        } else {
            if (a[n - 1] == -1) {
                cout << 0 << "\n";
            } else {
                cout << a[n - 1] << "\n";
            }
        }
    }

    return 0;
}
