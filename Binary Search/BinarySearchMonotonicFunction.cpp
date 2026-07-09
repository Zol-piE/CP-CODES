#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 9;
int a[N], n;
long long s;
bool f(int x)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i] / x;
    }
    return sum >= s;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 1, r = 1e9, ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (f(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}