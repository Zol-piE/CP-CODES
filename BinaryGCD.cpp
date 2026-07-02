#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define yes cout << "YES\n";
#define no cout << "NO\n";
using ll = long long;
const ll MOD = 1e9 + 7;
const ll INF = LLONG_MAX >> 1;
#define rep(a, b) for (ll i = (a); i < (b); i++)
#define ZolpiE ios_base::sync_with_stdio(false), cin.tie(nullptr)

int binGcd(int a, int b)
{
    if (a == 0 || b == 0)
        return a | b;
    int shift = __builtin_ctz(a | b);
    a >>= (__builtin_ctz(a));
    do
    {
        b >>= __builtin_ctz(b);
        if (a > b)
            swap(a, b);
        b -= a;
    } while (b);
    return a << shift;
}
signed main()
{
    ZolpiE;

    int tc;
    cin >> tc;
    while (tc--)
    {
        int a, b;
        cin >> a >> b;
        cout << binGcd(a, b) << endl;
    }

    return 0;
}
