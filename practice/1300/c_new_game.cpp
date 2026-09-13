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

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        int bottom = 0, top = 0;
        int max_cards = 0;

        while (top < n) {
            if (top >= 1 and a[top] - a[top - 1] > 1) {
                bottom = top;
            }

            int different_cards_used = a[top] - a[bottom] + 1;
            int cards_used = top - bottom + 1;

            if (different_cards_used <= k) {
                max_cards = max(max_cards, cards_used);

                top += 1;
            } else {
                bottom += 1;
            }
        }

        cout << max_cards << "\n";
    }

    return 0;
}
