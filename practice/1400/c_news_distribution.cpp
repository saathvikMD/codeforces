#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> participant(n);

    for (int i = 0; i < m; i++) {
        int k;

        cin >> k;

        int first;

        for (int j = 0; j < k; j++) {
            int temp;

            cin >> temp;

            if (j == 0) {
                first = temp - 1;
            } else {
                participant[first].push_back(temp - 1);
                participant[temp - 1].push_back(first);
            }
        }
    }

    vector<int> visited(n, -1);

    for (int i = 0; i < n; i++) {
        if (visited[i] == -1) {
            vector<int> current;
            current.push_back(i);
            visited[i] = 0;

            int curr_spread = 1;

            while (current.size() > 0) {
                vector<int> next;

                for (int j = 0; j < current.size(); j++) {
                    for (int k = 0; k < participant[current[j]].size(); k++) {
                        if (visited[participant[current[j]][k]] == -1) {
                            visited[participant[current[j]][k]] = i;
                            next.push_back(participant[current[j]][k]);
                        }
                    }
                }

                current = next;
                curr_spread += next.size();
            }

            visited[i] = curr_spread;

            cout << visited[i] << " ";
        } else {
            cout << visited[visited[i]] << " ";
        }
    }

    return 0;
}
