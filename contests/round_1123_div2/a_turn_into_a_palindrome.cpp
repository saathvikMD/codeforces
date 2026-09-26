#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n;
        char c;

        cin >> n >> c;

        string s;

        cin >> s;

        int start = 0;
        int end = n - 1;
        int count = 0;

        while (start < end) {
            if (s[start] != s[end]) {
                if (s[start] != c) {
                    count += 1;
                }

                if (s[end] != c) {
                    count += 1;
                }
            }

            start += 1;
            end -= 1;
        }

        cout << count << "\n";
    }

    return 0;
}
