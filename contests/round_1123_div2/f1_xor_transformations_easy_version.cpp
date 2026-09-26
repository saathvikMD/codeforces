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

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        vector<int> cases(q);

        for (int i = 0; i < q; i++) {
            cin >> cases[i];
        }

        bool done = false;
        int final_case = *max_element(cases.begin(), cases.end());
        vector<int> differences;
        int iter = 0;

        while (not done and iter < final_case + 1) {
            sort(numbers.begin(), numbers.end());
            vector<int> xors;
            xors.reserve(n * (n - 1) / 2);
            differences.push_back(numbers[n - 1] - numbers[0]);

            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    xors.push_back(numbers[i] ^ numbers[j]);
                }
            }

            nth_element(xors.begin(), xors.begin() + n, xors.end());
            xors.resize(n);

            if (*max_element(xors.begin(), xors.end()) == 0) {
                done = true;
            }

            numbers = xors;

            iter += 1;
        }

        for (int i = 0; i < q; i++) {
            if (cases[i] < differences.size()) {
                cout << differences[cases[i]] << "\n";
            } else {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}
