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

        vector<int> numbers(n);

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        for (int k = 0; k < 1000; k++) {
            for (int i = 0; i < n; i++) {
                string s = to_string(numbers[i]);
                int sum = 0;

                for (int j = 0; j < s.length(); j++) {
                    sum += (s[j] - '0') * (s[j] - '0');
                }

                numbers[i] = sum;
            }
        }

        int tune = 0;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (numbers[i] == numbers[j]) {
                    tune += 1;
                }
            }
        }

        cout << tune << "\n";
    }

    return 0;
}
