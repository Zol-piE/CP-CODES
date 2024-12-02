#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
int subArray(vector<int> &arr,int n , int target)
{
    unordered_map<int,int> mp;
    int pSum = 0;
    int res = 0;
    for(int i =0;i<n;i++)
    {
        pSum += arr[i];
        if(mp.find(pSum - target)!= mp.end())
        {
            int index = mp[pSum-target];
            res = max(res,i - index);
        }
        if(pSum==target)
        {
            res = max(res,i);
        }
        if(mp.find(pSum) == mp.end())
        {
            mp.insert({pSum,i});
        }
    }
    return res;
}
int main()
{
    vector<int> arr = { 8,3,1,5,-6,6,2,2};
    cout<<subArray(arr,arr.size(),4)<<endl;
    return 0;
}

