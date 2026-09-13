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
        vector<long long> original_numbers(n);

        for (int i = 0; i < n; i++) {
            cin >> numbers[i];

            original_numbers[i] = numbers[i];
        }

        sort(numbers.begin(), numbers.end());

        long long m_sum = 0;
        priority_queue<long long> queue;

        for (int i = 0; i < m - 1; i++) {
            queue.push(original_numbers[i]);
            m_sum += original_numbers[i];
        }

        long long max_count = LLONG_MIN;

        for (int i = m - 1; i < n; i++) {
            if (m > 1 and i >= m and original_numbers[i - 1] < queue.top()) {
                m_sum -= queue.top();
                queue.pop();

                queue.push(original_numbers[i - 1]);
                m_sum += original_numbers[i - 1];
            }

            long long curr_count = original_numbers[i] * m - m_sum;
            max_count = max(max_count, curr_count);
        }

        cout << max_count << "\n";
    }

    return 0;
}
