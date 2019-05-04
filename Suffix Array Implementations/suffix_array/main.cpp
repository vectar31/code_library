#include <bits/stdc++.h>
using namespace std;
// o(nlogn)
#define For(i, a, b) for (int i=(a); i<(b); ++i)
#define foreach(x, v) for (typeof (v).begin() x = (v).begin(); x != (v).end(); ++x)
#define D(x) cout << #x " = " << (x) << endl

const int N = 50005;
// Begins Suffix Arrays implementation
// O(n log n) - Manber and Myers algorithm

//Usage:
// Fill str with the characters of the string.
// Call SuffixSort(n), where n is the length of the string stored in str.
// That's it!

//Output:
// pos = The suffix array. Contains the n suffixes of str sorted in lexicographical order.
//       Each suffix is represented as a single integer (the position of str where it starts).
// RANK = The inverse of the suffix array. RANK[i] = the index of the suffix str[i..n)
//        in the pos array. (In other words, pos[i] = k <==> RANK[k] = i)
//        With this array, you can compare two suffixes in O(1): Suffix str[i..n) is smaller
//        than str[j..n) if and only if RANK[i] < RANK[j]

int str[N]; //input
int RANK[N], pos[N]; //output
int cnt[N], NEXT[N]; //internal
bool bh[N], b2h[N];

bool smaller_first_char(int a, int b){
  return str[a] < str[b];
}

void SuffixSort(int n){
  //sort suffixes according to their first character
  for (int i=0; i<n; ++i){
    pos[i] = i;
  }
  sort(pos, pos + n, smaller_first_char);
  //{pos contains the list of suffixes sorted by their first character}

  for (int i=0; i<n; ++i){
    bh[i] = i == 0 || str[pos[i]] != str[pos[i-1]];
    b2h[i] = false;
  }

  for (int h = 1; h < n; h <<= 1){
    //{bh[i] == false if the first h characters of pos[i-1] == the first h characters of pos[i]}
    int buckets = 0;
    for (int i=0, j; i < n; i = j){
      j = i + 1;
      while (j < n && !bh[j]) j++;
      NEXT[i] = j;
      buckets++;
    }
    if (buckets == n) break; // We are done! Lucky bastards!
    //{suffixes are separted in buckets containing strings starting with the same h characters}

    for (int i = 0; i < n; i = NEXT[i]){
      cnt[i] = 0;
      for (int j = i; j < NEXT[i]; ++j){
        RANK[pos[j]] = i;
      }
    }

    cnt[RANK[n - h]]++;
    b2h[RANK[n - h]] = true;
    for (int i = 0; i < n; i = NEXT[i]){
      for (int j = i; j < NEXT[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0){
          int head = RANK[s];
          RANK[s] = head + cnt[head]++;
          b2h[RANK[s]] = true;
        }
      }
      for (int j = i; j < NEXT[i]; ++j){
        int s = pos[j] - h;
        if (s >= 0 && b2h[RANK[s]]){
          for (int k = RANK[s]+1; !bh[k] && b2h[k]; k++) b2h[k] = false;
        }
      }
    }
    for (int i=0; i<n; ++i){
      pos[RANK[i]] = i;
      bh[i] |= b2h[i];
    }
  }
  for (int i=0; i<n; ++i){
    RANK[pos[i]] = i;
  }
}
// End of suffix array algorithm

// Algorithm GetHeight
// input: A text A and its suffix array Pos
//    1 for i:=1 to n do
//    2     RANK[Pos[i]] := i
//    3 od
//    4 h:=0
//    5 for i:=1 to n do
//    6     if RANK[i] > 1 then
//    7        k := Pos[RANK[i]-1]
//    8        while A[i+h] = A[j+h] do
//    9           h := h+1
//    10       od
//    11       Height[RANK[i]] := h
//    12       if h > 0 then h := h-1 fi
//    13    fi
//    14 od
int height[N];
// height[i] = length of the longest common prefix of suffix pos[i] and suffix pos[i-1]
// height[0] = 0
void getHeight(int n){
  for (int i=0; i<n; ++i) RANK[pos[i]] = i;
  height[0] = 0;
  for (int i=0, h=0; i<n; ++i){
    if (RANK[i] > 0){
      int j = pos[RANK[i]-1];
      while (i + h < n && j + h < n && str[i+h] == str[j+h]) h++;
      height[RANK[i]] = h;
      if (h > 0) h--;
    }
  }
}


string s;

void solve(){
  int n = s.size();
  for (int i=0; i<n; ++i) str[i] = s[i];
  SuffixSort(n);
  getHeight(n);
  long long ans = 0;
  for (int i=0; i<n; ++i){
    ans += n - pos[i] - height[i];
  }
  cout<<ans<<endl;
}


int main(){
  int t;
  cin >> t;
  while (t--){
    cin >> s;
    solve();
  }
  return 0;
}
