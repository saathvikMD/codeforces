#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int x, y;

        cin >> x >> y;

        int max_val = x + y;

        bitset<32> sum(max_val);
        string sum_bits = sum.to_string();

        for (int i = 0; i < sum_bits.length(); i++) {
            if (sum_bits[i] == '1') {
                if (pow(2, sum_bits.length() - i - 1) <= x) {
                    x -= pow(2, sum_bits.length() - i - 1);
                }
            }
        }

        cout << max_val << " " << x << "\n";
    }

    return 0;
}
