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

        int a, b, c;

        cin >> a >> b >> c;

        cout << n - min({a, b, c}) << "\n";
    }

    return 0;
}
