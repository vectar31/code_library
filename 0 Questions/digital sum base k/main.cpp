#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

vector<long long> get_xor(long long x, long long k) {
    long long last_digit = (((x / k) * ((k * (k - 1)) / 2)) + ((x % k) * (x % k + 1)) / 2) % k;
    vector<long long> answer(1, last_digit);
    long long p = 1, cx = x;
    while (p <= x / k) {
        cx /= k;
        p = p * k;
        long long digit = cx % k;
        long long freq = x % p + 1;
        answer.push_back((digit * freq) % k);
    }
    return answer;
}

vector<long long> get_xor_k(long long a, long long b, long long k) {
    vector<long long> sum_a = get_xor(a - 1, k);
    vector<long long> sum_b = get_xor(b, k);
    for (int i = 0; i < (int)max(sum_a.size(), sum_b.size()); ++ i) {
        if (i >= (int)sum_b.size()) {
            sum_b.push_back(0);
        }
        sum_b[i] = (sum_b[i] - (i < (int)sum_a.size() ? sum_a[i] : 0) + k) % k;
    }
    return sum_b;
}

int main() {
    long long k;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        long long a, b;
        cin >> a >> b >> k;
        vector<long long> sum = get_xor_k(a, b, k);
        long long answer = 0, p = 1;
        for (int i = 0; i < (int)sum.size(); ++ i) {
            answer += sum[i] * p;
            p *= k;
        }
        cout << answer << "\n";
    }
    return 0;
}
