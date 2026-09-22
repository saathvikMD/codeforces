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

        if (k % 2 == 0) {
            if (n % 2 == 0) {
                if (n >= k) {
                    cout << "YES" << "\n";

                    for (int i = 0; i < k - 1; i++) {
                        cout << 1 << " ";
                    }

                    cout << n - k + 1 << "\n";
                } else {
                    cout << "NO" << "\n";
                }
            } else {
                cout << "NO" << "\n";
            }
        } else {
            if (n % 2 == 0) {
                if (n >= k * 2) {
                    cout << "YES" << "\n";

                    for (int i = 0; i < k - 1; i++) {
                        cout << 2 << " ";
                    }

                    cout << n - k * 2 + 2 << "\n";
                } else {
                    cout << "NO" << "\n";
                }
            } else {
                if (n >= k) {
                    cout << "YES" << "\n";

                    for (int i = 0; i < k - 1; i++) {
                        cout << 1 << " ";
                    }

                    cout << n - k + 1 << "\n";
                } else {
                    cout << "NO" << "\n";
                }
            }
        }
    }

    return 0;
}
