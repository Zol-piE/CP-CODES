#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define yes cout << "YES\n";
#define no cout << "NO\n";
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
#define rep(a, b) for (int i = (a); i < (b); i++)
#define ZolpiE ios_base::sync_with_stdio(false), cin.tie(nullptr)
using vi = vector<int>;
class dsu
{
  private:
  public:
    vector<int> parent;
    vector<int> size;
    int n;
    // Initialize N isolated sets
    dsu(int n) : n(n)
    {

        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i; // Every node is initially its own root
        }
    }

    // Find the root of x with Path Compression
    int find(int x)
    {
        if (parent[x] == x)
        {
            return x;
        }
        // Recursively find the root and compress the path
        return parent[x] = find(parent[x]);
    }

    // Merge sets containing x and y using Union by Size
    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY)
        {
            // Always attach the smaller tree to the larger tree
            if (size[rootX] < size[rootY])
            {
                swap(rootX, rootY);
            }
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
    }
};
int NumberOfComponent(dsu &gp) // n -> number of nodes
{
    set<int> roots;

    for (int i = 1; i <= gp.n; i++)
        roots.insert(gp.find(i));

    return roots.size();
}
void IterateThroughComponents(dsu &gp)
{
    map<int, vector<int>> comp;

    for (int i = 1; i <= gp.n; i++)
    {
        comp[gp.find(i)].push_back(i);
    }
    for (auto &[root, nodes] : comp)
    {
        for (int x : nodes)
            cout << x << ' ';

        cout << '\n';
    }
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
        dsu gp(n);
        gp.unite(1, 3);
        gp.unite(1, 5);
        gp.unite(3, 5);
        gp.unite(2, 4);
        gp.unite(4, 6);
        cout << NumberOfComponent(gp) << endl;
    }

    return 0;
}
