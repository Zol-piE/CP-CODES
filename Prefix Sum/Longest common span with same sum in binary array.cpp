#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
int subArray(vector<int> &arr,vector<int> &brr,int n)
{
    vector<int> minusArr;
    for(int i=0;i<n;i++)
    {
        minusArr.push_back(arr[i]-brr[i]);
    }
    unordered_map<int,int> mp;
    int pSum =0,res =0 ;
    for(int i=0;i<n;i++)
    {
        pSum+=minusArr[i];
        if(pSum==0)
        {
            res =  max(res,i);
        }
        if(mp.find(pSum)!=mp.end())
        {
            res = max(res,i - mp[pSum]);
        }
        else mp[pSum] = i;
    }
    return res;
}
int main()
{
    vector<int> arr1 = {0,1,0,0,0,0},arr2 = {1,0,1,0,0,1};
    cout<<subArray(arr1,arr2,arr1.size())<<endl;
    arr1.clear();
    arr2.clear();
    arr1 = {0,1,0,1,1,1,1};
    arr2 = {1,1,1,1,1,0,1};
    cout<<subArray(arr1,arr2,arr1.size())<<endl;
    return 0;
}

