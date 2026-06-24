#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define yes cout << "YES\n";
#define no cout << "NO\n";
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX >> 1;
#define rep(a, b) for (ll i = (a); i < (b); i++)
#define ZolpiE                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr)
using vi = vector<int>;
struct custom_hash
{
    static uint64_t splitmix64(uint64_t x)
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const
    {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void pr(vi &arr, int n)
{
    for (ll i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
void inputarray(vector<int> &arr, int n)
{
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
class SegmentTree
{
  public:
    int n;
    vector<int> initialArray;
    vector<int> segmentTree;

    SegmentTree(vector<int> &arr)
        : n(arr.size()),
          initialArray(arr),
          segmentTree(4 * max(1, (int)arr.size()), 0)
    {
        if (n)
            build(0, 0, n - 1);
    }

    void build(int ind, int low, int high)
    {
        if (low == high)
        {
            segmentTree[ind] = initialArray[low];
            return;
        }

        int mid = low + (high - low) / 2;

        build(2 * ind + 1, low, mid);
        build(2 * ind + 2, mid + 1, high);

        segmentTree[ind] =
            min(segmentTree[2 * ind + 1],
                segmentTree[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        // No overlap
        if (r < low || l > high)
            return INT_MAX;

        // Complete overlap
        if (l <= low && high <= r)
            return segmentTree[ind];

        // Partial overlap
        int mid = low + (high - low) / 2;

        return min(
            query(2 * ind + 1, low, mid, l, r),
            query(2 * ind + 2, mid + 1, high, l, r));
    }

    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    void pointUpdate(int ind, int low, int high, int idx, int val)
    {
        if (low == high)
        {
            segmentTree[ind] = val;
            initialArray[idx] = val;
            return;
        }

        int mid = low + (high - low) / 2;

        if (idx <= mid)
            pointUpdate(2 * ind + 1, low, mid, idx, val);
        else
            pointUpdate(2 * ind + 2, mid + 1, high, idx, val);

        segmentTree[ind] =
            min(segmentTree[2 * ind + 1],
                segmentTree[2 * ind + 2]);
    }

    void pointUpdate(int idx, int val)
    {
        pointUpdate(0, 0, n - 1, idx, val);
    }
};
signed main()
{
    ZolpiE;

    int tc;
    cin >> tc;
    while (tc--)
    {
    }

    return 0;
}
