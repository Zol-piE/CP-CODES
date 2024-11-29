#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
bool eqArray(vector<int> &arr,int n)
{
    int leftSum =0,cSum =0;

    for(int i=0;i<n;i++) cSum +=arr[i];

    for(int i=0;i<n;i++)
    {
        if(leftSum == (cSum - arr[i])) return true;
        leftSum += arr[i];
        cSum -=arr[i];
    }
    return false;
}
int main()
{
    vector<int> arr = {4,2,-2};
    int n = arr.size();
    cout<<eqArray(arr,n);
    return 0;
}
