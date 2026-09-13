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

        if (k > 2 * n - 1 or k < n) {
            cout << -1 << "\n";
        } else {
            vector<vector<int>> grid(n, vector<int> (n, 0));
            int curr_number = 1;

            for (int i = 0; i < 2 * n - k; i++) {
                grid[i][i] = curr_number;
                curr_number += 1;
            }

            for (int col = 0; col < n; col++) {
                for (int row = 0; row < n; row++) {
                    if (grid[row][col] == 0) {
                        grid[row][col] = curr_number;
                        curr_number += 1;
                    }
                }
            }

            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n - 1; col++) {
                    cout << grid[row][col] << " ";
                }

                cout << grid[row][n - 1] << "\n";
            }
        }
    }

    return 0;
}
