#include <bits/stdc++.h>
using namespace std;

bool possible(string s, int cost, int n) {
    bool possible = true;
    int sum = 0;
    int crossing_distance = 0;
    int adjust = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            if (sum > 0) {
                adjust += 1;
            }

            int move = 1 - sum;

            if (move == 0) {
                move = 1;
            }

            if (abs(move) > cost) {
                if (adjust >= 2 and sum <= -2) {
                    if (not (abs(move - 1) > cost)) {
                        crossing_distance = abs(move - 1);
                        sum += move;
                        adjust = 0;
                    } else {
                        possible = false;
                        break;
                    }
                } else if (sum < 0 and crossing_distance < cost and not (abs(move) - 1 > cost)) {
                    sum += move;
                    crossing_distance = abs(move) - 1;
                    adjust = 0;
                } else {
                    possible = false;
                    break;
                }
            } else {
                if (sum <= 0) {
                    crossing_distance = abs(move);
                    adjust = 0;
                }

                sum += move;
            }
        } else if (s[i] == '0') {
            if (sum == 0) {
                possible = false;
                break;
            }

            int move = -sum;

            if (abs(move) > cost) {
                if (crossing_distance < cost and not (abs(move) - 1 > cost)) {
                    sum += move;
                    crossing_distance = abs(move) - 1;
                } else {
                    possible = false;
                    break;
                }
            } else {
                crossing_distance = INT_MAX;
                sum += move;
            }
        } else if (s[i] == '-') {
            if (sum < 0) {
                adjust += 1;
            }

            int move = -1 - sum;

            if (move == 0) {
                move = -1;
            }

            if (abs(move) > cost) {
                if (adjust >= 2 and sum >= 2) {
                    if (not (abs(move + 1) > cost)) {
                        crossing_distance = abs(move + 1);
                        sum += move;
                        adjust = 0;
                    } else {
                        possible = false;
                        break;
                    }
                } else if (sum > 0 and crossing_distance < cost and not (abs(move) - 1 > cost)) {
                    sum += move;
                    crossing_distance = abs(move) - 1;
                    adjust = 0;
                } else {
                    possible = false;
                    break;
                }
            } else {
                if (sum >= 0) {
                    crossing_distance = abs(move);
                    adjust = 0;
                }

                sum += move;
            }
        }
    }

    return possible;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n;

        cin >> n;

        string s;

        cin >> s;

        int low = 1;
        int high = n;
        int answer = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (possible(s, mid, n)) {
                answer = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if (answer == -1) {
            cout << -1 << "\n";
        } else {
            cout << answer << "\n";
        }
    }

    return 0;
}
