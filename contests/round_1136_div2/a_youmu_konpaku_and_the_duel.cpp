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

        int moves = n;
        int charge = 2;

        while (charge - 1 < moves) {
            int curr_moves = charge - 1;
            int curr_charge = charge;
            int temp_n = n;

            while (temp_n > 0 and curr_moves < moves) {
                temp_n -= max(1, curr_charge);
                curr_charge -= 1;
                curr_moves += 1;
            }

            moves = min(moves, curr_moves);
            charge += 1;
        }

        cout << moves << "\n";
    }

    return 0;
}
