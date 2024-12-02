#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
int subArray(vector<int> &arr,int n)
{
    for(int i =0;i<n;i++)
    {
        if(arr[i]==0) arr[i]=-1;
    }
    unordered_map<int,int> mp;
    int res =0,pSum =0;
    for(int i =0;i<n;i++)
    {
        pSum += arr[i];
        if(pSum ==0)
        {
            res = max(res,i - mp[1]);
        }
        if(mp.find(pSum)!=mp.end())
        {
            res = max(res,i - mp[pSum]);
        }
        mp[pSum] = i;
    }
    return res;
}
int main()
{
    vector<int> arr = {1,1,1,1,0,0,0,0};
    cout<<subArray(arr,arr.size())<<endl;
    return 0;
}

