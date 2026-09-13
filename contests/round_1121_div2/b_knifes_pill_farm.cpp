#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;

    cin >> t;

    for (int iteration = 0; iteration < t; iteration++) {
        int n, m;

        cin >> n >> m;

        vector<long long> numbers(n);

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        long long m_sum = 0;
        priority_queue<long long> queue;

        for (int i = 0; i < m - 1; i++) {
            queue.push(numbers[i]);
            m_sum += numbers[i];
        }

        long long max_count = LLONG_MIN;

        for (int i = m - 1; i < n; i++) {
            if (m > 1 and i >= m and numbers[i - 1] < queue.top()) {
                m_sum -= queue.top();
                queue.pop();

                queue.push(numbers[i - 1]);
                m_sum += numbers[i - 1];
            }

            long long curr_count = numbers[i] * m - m_sum;
            max_count = max(max_count, curr_count);
        }

        cout << max_count << "\n";
    }

    return 0;
}
