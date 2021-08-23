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
#define Task "proD"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
vii ke[maxn];
int n, k;
//int h[maxn];
double vp, vc;
int f[maxn];
struct edge
{
    int u, v;
    double w;
};
void dfs(int u, int p)
{
    f[u] = 1;
    for (pii v : ke[u])
    {
        if (v.F == p) continue;
        dfs(v.F, u);
        f[u] += f[v.F];
    }
}
double dgiam[maxn];
edge canh[maxn];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n >> k >> vp >> vc;
    for (int i = 1; i < n; i ++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
        canh[i] = {u, v, w};
    }
    dfs(1, 0);
    for (int i = 1; i < n; i ++)
    {
        //if (h[canh[i].u] > h[canh[i].v]) swap(canh[i].u, canh[i].v);
        int g = min(f[canh[i].v], f[canh[i].u]);
        dgiam[i] = (canh[i].w/vp - canh[i].w/vc) * g * (n - g);
    }
    double res = 0;
    sort(dgiam + 1, dgiam + n, greater<double>());
    for (int i = 1; i <= k; i ++) res += dgiam[i];
    cout << fixed << setprecision(2) << res;
}
