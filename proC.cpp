//ngqminh.cl2735
#include <bits/stdc++.h>
#define PB push_back
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define mpa make_pair
#define oo INT_MAX
#define F first
#define S second
#define reset(x, i) memset(x,i,sizeof(x))
#define sz(x) int(x.size())
#define mp make_pair
#define maxn 100005
#define MOD
#define Task "proC"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
vii ke[maxn];
int n;
int m;
int l;
vi tplt;
bool dd[maxn];
int d[maxn];
int mx = 0;
int x, y;
int tr[maxn];
int maxres = 0;
void dfs(int u, int p, int &x)
{
    dd[u] = 1;
    for (pii v : ke[u])
        if (v.F != p) {
            d[v.F] = d[u] + v.S;
            tr[v.F] = u;
            if (d[v.F] > mx)
            {
                x = v.F;
                mx = d[v.F];
            }
            dfs(v.F, u, x);
        }
}
void sol(int u)
{
    if (!sz(ke[u]))
    {
        tplt.PB(0);
        return;
    }
    mx = 0;
    d[u] = 0;
    dfs(u, -1, x);
    mx = 0;
    d[x] = 0;
    dfs(x, -1, y);
    int t = y;
    int res = oo;
    while (t != x)
    {
        res = min(res, max(d[t], d[y] - d[t]));
        t = tr[t];
    }
    tplt.PB(res);
    maxres = max(maxres, d[y]);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> m >> l;
    for (int i = 1; i <= m; i ++) {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
    }
    for (int i = 0; i < n; i ++)
        if (!dd[i]) sol(i);
    sort(tplt.begin(), tplt.end(), greater<int>());
    if (n - m == 1) cout << maxres;
    else if (n - m == 2) cout << max(maxres, tplt[0] + tplt[1] + l);
    else cout << max(maxres, max(tplt[0] + tplt[1] + l, tplt[2] + tplt[1] + l*2));
    return 0;
}
