#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
int fun(vector<int> &left,vector<int> &right)
{
    vector<int> arr(1000,0);
    int n = left.size();
    int mfreq = INT_MIN,res =0;
    for(int i=0;i<n;i++)
    {
        arr[left[i]]++;
        arr[right[i]+1]--;
    }
    for(int i =1;i<1000;i++)
    {
        arr[i]+=arr[i-1];
        if(mfreq<arr[i])
        {
            mfreq = arr[i];
            res = i;
        }
    }

    return res;

}
int main()
{
    vector<int> left= {1,2,3 },right= {3,5,7};
    cout<<fun(left,right);
    return 0;
}
