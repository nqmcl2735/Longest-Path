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
#define Task "proE"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
vii ke[maxn];
ll p[maxn];
int n;
ll s[maxn];
ll d[maxn];
ll t[maxn];
ll c[maxn];
ll sump;
ll resmin = 100000000000000000, resmax = 0;
void dfs(int u, int pr)
{
    s[u] = p[u];
    for (pii v : ke[u]) if(v.F != pr)
    {
        d[v.F] = d[u] + v.S;
        dfs(v.F, u);
        s[u] += s[v.F];
        t[u] += t[v.F] + s[v.F] * v.S;
    }
}
void dfs2(int u, int pr)
{
    resmin = min(resmin, c[u] + t[u]);
    resmax = max(resmax, c[u] + t[u]);
    for (pii v : ke[u]) if(v.F != pr)
    {
        c[v.F] = c[u] + (t[u] - t[v.F] - s[v.F] * v.S) + v.S*(sump - s[v.F]);
        dfs2(v.F, u);
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
    sump = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> p[i];
        sump += p[i];
    }
    dfs(1, -1);
    c[1] = 0;
    dfs2(1, -1);
    cout << resmin << " " << resmax;
}
