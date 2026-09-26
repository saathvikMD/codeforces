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

        sort(numbers.begin(), numbers.end(), greater<int>());

        vector<int> order;

        while (numbers.size() > 0) {
            vector<int> counts(101, 0);
            int max_count = 1;
            int max_val = numbers[0];
            vector<int> saved;
            order.push_back(numbers[0]);

            for (int i = 1; i < n; i++) {
                if (numbers[i] == max_val) {
                    max_count += 1;
                    order.push_back(numbers[i]);
                } else if (counts[numbers[i]] + 1 > max_count) {
                    saved.push_back(numbers[i]);
                } else {
                    counts[numbers[i]] += 1;
                    order.push_back(numbers[i]);
                }
            }

            numbers = saved;
            n = numbers.size();
        }

        for (int i = 0; i < order.size(); i++) {
            cout << order[i] << " ";
        }

        cout << "\n";
    }

    return 0;
}
