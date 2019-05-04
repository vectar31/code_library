#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
     /* Do not compare for all elements. Compare only
        when  max_ending_here > 0 */
        else if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
   }
    cout<<max_so_far<<endl;
    return 0;
}
