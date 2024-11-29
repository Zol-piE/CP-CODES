#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
int getSum(vector<int> &arr,int n,int i ,int j)
{
    vector<int> ps;
    ps.push_back(arr[0]);
    for(int i =1;i<n;i++)
    {
        ps.push_back((arr[i])+ps[i-1]);
    }
    if(i!=0) return ps[j] - ps[i-1];
    return ps[j];
}
int main()
{
    vector<int> arr ={ 2,8,3,9,6,5,4};
    int n = arr.size();
    cout<<getSum(arr,n,0,6)<<endl;
    cout<<getSum(arr,n,2,3)<<endl;
    return 0;
}
