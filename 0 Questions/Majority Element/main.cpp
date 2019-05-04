/* Program for finding out majority element in an array
A majority element in an array A[] of n n is an element that appears more than n/2 times */
# include<bits/stdc++.h>
#define N 11000010
using namespace std;

int a[N];
/* Function to find the candidate for Majority */
int findCandidate(int n)
{
    int maj_index = 0, count = 1;
    int i;
    for (i = 1; i < n; i++)
    {
        if (a[maj_index]==a[i])
            count++;
        else
            count--;
        if (count==0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}
/* Function to check if the candidate occurs more than n/2 times */
bool isMajority(int n, int cand)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
      if (a[i] == cand)
         count++;
    if (count > n/2)
       return 1;
    else
       return 0;
}
int main()
{
    //ifstream fin("input.txt");
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    int cand=findCandidate(n);
    if(isMajority(n,cand))
        printf("%d",cand);
    else
        printf("No Majority Element");
    return 0;
}
