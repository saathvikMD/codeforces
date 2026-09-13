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

        vector<int> swap;
        vector<int> numbers(n);
        vector<int> numbers_original(n);

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
            numbers_original[i] = numbers[i];
        }

        sort(numbers.begin(), numbers.end());

        for (int i = 0; i < n; i++) {
            if (numbers[i] != numbers_original[i]) {
                swap.push_back(numbers_original[i]);
            }
        }

        reverse(swap.begin(), swap.end());

        int swap_index = 0;
        bool possible = true;

        for (int i = 0; i < n; i++) {
            if (numbers[i] != numbers_original[i]) {
                if (numbers[i] == swap[swap_index]) {
                    swap_index += 1;
                } else {
                    possible = false;
                    break;
                }
            }
        }

        if (possible) {
            cout << "YES" << "\n";
        } else {
            cout << "NO" << "\n";
        }
    }

    return 0;
}
