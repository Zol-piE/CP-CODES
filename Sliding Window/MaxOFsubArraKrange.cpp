#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
int subArray(vector<int> &arr,int n,int k)
{
    int curr = 0,mSum = INT_MIN;
    for(int i =0;i<k;i++) curr+= arr[i];
    mSum = max(curr,mSum);
    for(int i=k;i<n;i++)
    {
        curr += arr[i] - arr[i-k];
        mSum = max(mSum,curr);
    }
    return mSum;
}
int main()
{
    fast
    int k,n;
    vector<int> arr = {10,50,30,20,5,1};
    n = arr.size();
    cout<<subArray(arr,n,3);
    return 0;
}
