#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
void min_subArray(vector<int> &arr,int n,int k)
{
    deque<int>dq;
    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && arr[dq.front()]>=arr[i])
        {
            dq.pop_front();
        }
        dq.push_back(i);
    }
    for(int i =k;i<n;i++)
    {
        cout<<arr[dq.front()]<< " ";

        while(!dq.empty() && dq.front()<=(i-k)) dq.pop_front();

        while(!dq.empty() && arr[dq.front()]>=arr[i])
        {
            dq.pop_front();
        }
        dq.push_back(i);
    }
        cout<<arr[dq.front()]<< " ";
        cout<<endl;
}
void max_subArray(vector<int> &arr,int n,int k)
{
    deque<int> dq;
    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && arr[dq.front()]<=arr[i]) dq.pop_front();
        dq.push_back(i);
    }
    for(int i = k;i<n;i++)
    {
        cout<<arr[dq.front()]<<" ";

        while(!dq.empty() && dq.front()<= (i-k)) dq.pop_front();

        while(!dq.empty() && arr[dq.front()]<=arr[i]) dq.pop_front();
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
    cout<<endl;
}
int main()
{
    int n , k ; //n->vect size , k-> subarray size
    vector<int> arr = {0,5,5,3,10,1,4,0};
    n  = arr.size();
    k=3;
    min_subArray(arr,n,k);
    max_subArray(arr,n,k);
    return 0;
}
