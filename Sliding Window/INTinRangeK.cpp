#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
int subArray(vector<int> &arr,int k,int n)
{

    vector<int> freq(k+1,0);
    int con =0,l=0,ms = INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>0 && arr[i]<=k)
        {
            if(freq[arr[i]]==0)
            {
                con++;
            }
            freq[arr[i]]++;
        }
        while(con==k)
        {
            ms = min(ms,(i-l+1));
            if(arr[l]>0 && arr[l]<=k)
            {
                freq[arr[l]]--;
                if(freq[arr[l]]==0)
                {
                    con--;
                }
            }
            l++;
        }
    }
    return ms;
}
int main()
{
    fast
    int k;
    vector<int> arr = { 1,2,3,7,1,12,9,11,9,6,3,7,5,4,5,3,1,2,3,4};
    int n = arr.size();
    cout<<subArray(arr,4,n)<<endl;

    return 0;
}
