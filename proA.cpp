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
#define Task "proA"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int x, y, n;
vii ke[maxn];
int d[maxn];
void dfs(int u, int p)
{
    for (pii v : ke[u])
        if (v.F != p) {
            d[v.F] = d[u] + v.S;
            dfs(v.F, u);
        }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    fi >> n;
    for (int i = 1; i < n; i ++)
    {
        int u, v, w;
        fi >> u >> v >> w;
        ke[u].PB({v, w});
        ke[v].PB({u, w});
    }
    d[1] = 0;
    dfs(1, -1);
    int dmax = *max_element(d + 1, d + n + 1);
    for (int i = 1; i <= n; i ++)
        if (dmax - d[i] == 0)
        {
            d[i] = 0;
            dfs(i, -1);
            break;
        }
    fo << *max_element(d + 1, d + n + 1);
}
