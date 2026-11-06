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

        vector<vector<int>> paths(n, vector<int>());

        for (int i = 0; i < n - 1; i++) {
            int a, b;

            cin >> a >> b;

            paths[a - 1].push_back(b - 1);
            paths[b - 1].push_back(a - 1);
        }

        if (n % 2 == 0) {
            cout << n + 1;
        } else {
            vector<int> visited(n, -1);
            visited[0] = n + 1;

            for (int i = 0; i < n; i++) {
                if (visited[i] == -1) {
                    queue<int> q;
                    visited[i] = i;
                    q.push(i);

                    while (not q.empty()) {
                        int x = q.front();
                        q.pop();

                        for (int j = 0; j < paths[x].size(); j++) {
                            if (visited[paths[x][j]] == -1) {
                                q.push(paths[x][j]);
                                visited[paths[x][j]] = i;
                            }
                        }
                    }
                }
            }

            bool done = false;

            for (int i = 1; i <= n / 2; i++) {
                if (visited[i] != visited[n - i]) {
                    cout << n + 2;
                    done = true;
                    break;
                }
            }

            if (not done) {
                vector<int> visited(n, -1);
                visited[n - 1] = n + 1;

                for (int i = 0; i < n; i++) {
                    if (visited[i] == -1) {
                        queue<int> q;
                        visited[i] = i;
                        q.push(i);

                        while (not q.empty()) {
                            int x = q.front();
                            q.pop();

                            for (int j = 0; j < paths[x].size(); j++) {
                                if (visited[paths[x][j]] == -1) {
                                    q.push(paths[x][j]);
                                    visited[paths[x][j]] = i;
                                }
                            }
                        }
                    }
                }

                bool done = false;

                for (int i = 0; i < n / 2; i++) {
                    if (visited[i] != visited[n - i - 2]) {
                        cout << n;
                        done = true;
                        break;
                    }
                }

                if (not done) {
                    cout << n + 1;
                }
            }
        }

        cout << '\n';
    }

    return 0;
}
