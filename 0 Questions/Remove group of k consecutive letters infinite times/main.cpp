/*

Eg
s="qddxxxd";k=3;
ans= "q"
*/


#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    string str;
    cin >> n >> k >> str;

    // I maintain it as a deque so I can print it at the end without reversing it
    deque< pair<char, int> > stk;

    // Iterate over the string
    for (int i = 0; i < n; ++ i) {

        if (!stk.empty() && stk.back().first == str[i]) {
            // If the element is equal to the top of the stack, increase the frequency
            stk.back().second += 1;
        } else {
            // Otherwise, push the new character into the stack
            stk.push_back({str[i], 1});
        }
        // If the last letter in the stack has frequency equal to k, pop it.
        if (stk.back().second == k) {
            stk.pop_back();
        }
    }

    // Print the stack
    while (!stk.empty()) {
        cout << string(stk.front().second, stk.front().first);
        stk.pop_front();
    }
    cout << "\n";

    return 0;
}
