// Taken from here : http://codeforces.com/blog/entry/15729
// Look up : http://codeforces.com/blog/entry/11080

#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define endl '\n'
using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set< int >  s;
ordered_set<int >::iterator  it;

// Also look up the rope data structure here http://codeforces.com/blog/entry/10355
using namespace std;

int main()
{
    s.insert(1);
    s.insert(2);
    s.insert(4);
    s.insert(7);
    s.insert(10);
    cout << s.order_of_key(2) << endl; // the number of elements in the s less than 2
	cout << *s.find_by_order(4) << endl; // print the 0-th smallest number in s(0-based)
    return 0;
}
