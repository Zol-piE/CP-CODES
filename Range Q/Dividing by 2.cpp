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
signed main()
{
    ZolpiE;

    int tc;
    cin >> tc;
    while (tc--)
    {

        int n;
        cin >> n;
        vector<int> arr(n, 0);
        inputarray(arr, n);
        sort(arr.begin(), arr.end());
        int i = 0;
        int j = i + 1;
        int c = 0;
        while (j < n)
        {
            if (arr[j] > arr[i])
            {
                while (arr[j] > arr[i])
                {
                    arr[j] /= 2;
                    c++;
                }
                sort(arr.begin(), arr.end());
                i = 0;
                j = i + 1;
            }
            else
            {
                i = j;
                j = i + 1;
            }
        }
        cout << c << endl;
    }

    return 0;
}
