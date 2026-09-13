#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_cases;

    cin >> test_cases;

    for (int iteration = 0; iteration < test_cases; iteration++) {
        string s;

        cin >> s;

        string t;

        cin >> t;

        vector<int> s_count(26, 0);

        for (int i = 0; i < s.size(); i++) {
            s_count[s[i] - 'a']++;
        }

        int remaining = s.size();
        vector<int> extra(26, 0);

        for (int i = 0; i < t.size(); i++) {
            if (s_count[t[i] - 'a'] > 0) {
                remaining -= 1;
                s_count[t[i] - 'a'] -= 1;
            } else {
                extra[t[i] - 'a'] += 1;
            }
        }

        if (remaining > 0) {
            cout << "Impossible" << "\n";
        } else {
            int s_index = 0;

            for (int i = 0; i < 26; i++) {
                char alphabet = 'a' + i;

                while (s_index < s.size() and s[s_index] <= alphabet) {
                    cout << s[s_index];

                    s_index++;
                }

                for (int j = 0; j < extra[i]; j++) {
                    cout << alphabet;
                }
            }

            for (int i = s_index; i < s.size(); i++) {
                cout << s[i];
            }

            cout << "\n";
        }

    }

    return 0;
}
