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
#define Task "proB"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n, x, y;
vii ke[maxn];
int d[maxn];
int mx = 0;
int tr[maxn];
void dfs(int u, int p, int &x)
{
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
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i < n; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
    }
    d[1] = 0;
    dfs(1, -1, x);
    mx = 0;
    d[x] = 0;
    dfs(x, -1, y);
    int t = y;
    int res =  oo;
    while (t != x)
    {
        res = min(res, max(d[t], d[y] - d[t]));
        t = tr[t];
    }
    cout << res;
}
