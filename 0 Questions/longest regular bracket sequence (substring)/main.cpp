/*
longest substring that is a regular bracket sequence.
Also find the number of such substrings as well.

Eg
)((())))(()()) Ans= 6 and occurs 2 times.

*/
#include <bits/stdc++.h>
#define ll long long
#define N 1000010
using namespace std;
int res[N];
vector <int> st;// acts as a stack
int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int len_longest_reg_seq = 0;
    int freq_longest_reg_seq = 1;
    for(int i=0;i<n;i++)
    {
        if (s[i] == '(')
            st.push_back(i);
        else
        {
            if (!st.size())
                continue;
            int curr_len_reg_seq = i - st.back() + 1 + (st.back() ? res[st.back()-1] : 0);
            if (curr_len_reg_seq > len_longest_reg_seq)
            {
                len_longest_reg_seq = curr_len_reg_seq;
                freq_longest_reg_seq = 1;
            }
            else
            {
                if (curr_len_reg_seq == len_longest_reg_seq)
                    ++freq_longest_reg_seq;
            }
            res[i] = curr_len_reg_seq;
            st.pop_back();
        }
    }
    cout << len_longest_reg_seq << ' ' << freq_longest_reg_seq << endl;
	return 0;
}
