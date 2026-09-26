#include <bits/stdc++.h>
using namespace std;

vector<long long> primes(long long x) {
    vector<long long> p;

    for (long long d = 2; d * d <= x; d++) {
        if (x % d == 0) {
            p.push_back(d);

            while (x % d == 0) {
                x /= d;
            }
        }
    }

    if (x > 1) {
        p.push_back(x);
    }

    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;

    cin >> t;

    for (long long iteration = 0; iteration < t; iteration++) {
        long long n, x;

        cin >> n >> x;

        vector<long long> numbers(n);

        for (long long i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        vector<long long> prime_factors = primes(x);
        vector<long long> counts(prime_factors.size(), 0);
        long long optimal_count = 0;

        for (long long i = 0; i < prime_factors.size(); i++) {
            for (long long j = 0; j < n; j++) {
                if (numbers[j] % prime_factors[i] == 0) {
                    counts[i] += numbers[j];
                }
            }

            if (counts[i] > optimal_count) {
                optimal_count = counts[i];
            }
        }

        cout << optimal_count << "\n";
    }

    return 0;
}
