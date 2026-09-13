#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
  
    int n;

    cin >> n;

    vector<int> interest(n);

    for (int i = 0; i < n; i++) {
        cin >> interest[i];
    }

    for (int i = 0; i < n; i++) {
        int temp;

        cin >> temp;

        interest[i] -= temp;
    }

    sort(interest.begin(), interest.end());

    int bottom = 0, greater = n - 1;
    long long possibilities = 0;

    while (bottom < greater) {
        int sum = interest[bottom] + interest[greater];

        if (sum > 0) {
            possibilities += greater - bottom;

            greater -= 1;
        } else {
            bottom += 1;
        }
    }

    cout << possibilities;

    return 0;
}
