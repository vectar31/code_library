#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int i = 0, j = i + 1, len = s.length();
    string output(s);
    while(i < len){
        if(output[i] == s[i]) {
            while(j < len && output[i] == output[j]){
                j ++;
            }
            if(j >= len){
                j = 0;
                i --;
                continue;
            }
            if(output[i] != output[j] && j < len) {
                swap(output[i], output[j]);
                j ++;
            }
        }
        i ++;
    }
    for(i = 0; i < len; i ++){
        if(s[i] == output[i]){
            cout << "Not possible\n";
            return 0;
        }
    }
    cout << output << "\n";
    return 0;
}
