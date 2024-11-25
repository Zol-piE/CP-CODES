#include<bits/stdc++.h>
using namespace std;
int subArr(vector<int>&arr,int n,int target)
{
    int k=1,curr = arr[0],s=0,m = INT_MAX;

    if(curr==target)
    {
        m = min(k,m);
    }
    for(int e =1; e<n; e++)
    {
        curr += arr[e];
        k++;
        while(curr>target && s<e)
        {
            curr -= arr[s];
            s++;
            k--;
        }
        if(curr==target)
        {
            m = min(k,m);
        }
    }
    return m;
}
int main()
{
    vector<int> arr = { 15,1,3,5,10,7,4,9,7};
    int n = arr.size();
    cout<<subArr(arr,n,15)<<endl;
    return 0;
}
