/*
Each second, he can ask his teacher to round the grade at any place after the decimal point (also, he can ask to round to the nearest integer).

There are t seconds left till the end of the break, so Efim has to act fast.
Help him find what is the maximum grade he can get in no more than t seconds.
Note, that he can choose to not use all t seconds.
Moreover, he can even choose to not round the grade at all.

*/
#include <bits/stdc++.h>
using namespace std;

char s[200010];

void add_from(int pos) {
    int add = 1;
    for (int i = pos; i >= 0; i--) {
        if (s[i] == '.') {
            continue;
        }
        int val = s[i] - '0';
        val += add;
        s[i] = val % 10 + '0';
        add = val / 10;
    }
}

int main() {
    int n, K;
    scanf("%d%d", &n, &K);
    scanf("%s", s + 1);
    s[0] = '0';
    int pos = 1;
    while (s[pos] != '.') pos++;
    pos++;
    for (int i = pos; i <= n; i++) {
        if (s[i] >= '5') {
            s[i] = 0;
            add_from(i - 1);
            break;
        } else if (s[i] == '4') {
            int tot = 1;
            while (i <= n && s[i] == '4') {
                i++;
                tot++;
            }
            if (s[i] >= '5') {
                tot = min(tot, K);
                s[i - tot + 1] = 0;
                add_from(i - tot);
                break;
            }
        }
    }
    n = strlen(s);
    if (s[n - 1] == '.') {
        n--;
    }
    int f = 0;
    if (s[0] == '0') {
        f++;
    }
    for (int i = f; i < n; i++) {
        printf("%c", s[i]);
    }
    puts("");
    return 0;
}
