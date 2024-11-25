#include<bits/stdc++.h>
using namespace std;
 int minSumOfLengths(vector<int>& arr, int target) {
        deque<int> dq;
        dq.push_back(arr[0]);
        priority_queue<int,vector<int>,greater<int>> pq;
        int cSum = arr[0],n = arr.size();
        if(cSum==target)
        {
            pq.push(dq.size());
            while(!dq.empty()) dq.pop_back();
            cSum =0;
        }
        for(int e =1;e<n;e++)
        {
            cSum +=arr[e];
            dq.push_back(arr[e]);
            while(cSum>target&& !dq.empty())
            {
                cSum-=dq.front(); dq.pop_front();
            }
            if(cSum==target)
        {
            pq.push(dq.size());
            while(!dq.empty()) dq.pop_back();
            cSum =0;
        }
        }
        if(pq.size()>1)
        {
        n = pq.top(); pq.pop();
        n += pq.top(); pq.pop();
        return n;
        }
        return -1;
    }
int main()
{
    vector<int> arr ={1,6,1};
    cout<<minSumOfLengths(arr,7);
    return 0;
}
