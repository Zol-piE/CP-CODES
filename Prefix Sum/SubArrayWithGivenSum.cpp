#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
bool subArray(vector<int> &arr,int n,int target)
{
    unordered_set<int> st;
    int prefixSum =0;
    for(int i =0;i<n;i++)
    {
        prefixSum += arr[i];
        if(st.find(prefixSum-target)!= st.end() || prefixSum==target) return true;
        st.insert(prefixSum);
    }
    return false;
}
int main()
{
    vector<int> arr = {5,8,6,13,3,-1,4};
    cout<<subArray(arr,arr.size(),6)<<endl;
    arr.clear();
    cout<<subArray(arr,arr.size(),100)<<endl;

    return 0;
}

