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
#define Task ""
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
vii ke[maxn];
int d1[maxn];
int d2[maxn];
int n;
void dfs(int u, int p)
{
    for (pii v : ke[u]) if (v.F != p)
    {
        dfs(v.F, u);
        if (d1[v.F] + v.S >= d1[u])
        {
            d2[u] = d1[u];
            d1[u] = d1[v.F] + v.S;
        }
        else if (d1[v.F] + v.S >= d2[u]) d2[u] = d1[v.F] + v.S;
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
    dfs(1, -1);
    int res = 0;
    for (int i = 1; i <= n; i ++)
        res = max(res, d1[i] + d2[i]);
    cout << res;

}

