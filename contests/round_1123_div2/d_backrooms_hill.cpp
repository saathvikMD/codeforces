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
        vector<int> odds;
        vector<int> evens;

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];

            if (i % 2 == 0) {
                evens.push_back(numbers[i]);
            } else {
                odds.push_back(numbers[i]);
            }
        }

        sort(odds.begin(), odds.end());
        sort(evens.begin(), evens.end());
        int odd = odds.size() - 1;
        int even = evens.size() - 1;

        if (n == 1) {
            cout << "YES" << "\n";
        } else {
            int peak;
            bool turn_left;
            bool turn_right;

            if (odds[odd] > evens[even]) {
                peak = odds[odd];
                odds.pop_back();
                odd -= 1;
                turn_left = true;
                turn_right = true;
            } else {
                peak = evens[even];
                evens.pop_back();
                even -= 1;
                turn_left = false;
                turn_right = false;
            }

            vector<int> left;
            vector<int> right;
            left.push_back(peak);
            right.push_back(peak);
            bool possible = true;

            while (even >= 0 or odd >= 0) {
                bool done = false;

                if (turn_left) {
                    if (even >= 0 and evens[even] < left[left.size() - 1]) {
                        left.push_back(evens[even]);

                        turn_left = not turn_left;
                        even -= 1;
                        done = true;
                    }
                } else {
                    if (odd >= 0 and odds[odd] < left[left.size() - 1]) {
                        left.push_back(odds[odd]);

                        turn_left = not turn_left;
                        odd -= 1;
                        done = true;
                    }
                }

                if (not done) {
                    if (turn_right) {
                        if (even >= 0 and evens[even] < right[right.size() - 1]) {
                            right.push_back(evens[even]);

                            turn_right = not turn_right;
                            even -= 1;
                            done = true;
                        }
                    } else {
                        if (odd >= 0 and odds[odd] < right[right.size() - 1]) {
                            right.push_back(odds[odd]);

                            turn_right = not turn_right;
                            odd -= 1;
                            done = true;
                        }
                    }
                }

                if (not done) {
                    possible = false;

                    break;
                }
            }

            if (possible) {
                cout << "YES" << "\n";
            } else {
                cout << "NO" << "\n";
            }
        }
    }

    return 0;
}
