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
#define Task "proF"
using namespace std;
ifstream fi(Task".inp");
ofstream fo(Task".out");
typedef long long ll;
typedef long double ld;
int n;
int dp[maxn];
int id[maxn];
int ST1[4 * maxn];
int ST2[4 * maxn];
struct data{
    int l, r;
};
data a[maxn];
bool cmp(data a, data b)
{
    return a.r < b.r;
}
int biSearch(int l, int r, int val)
{
    int mid;
    int res = r+1;
    while (l <= r)
    {
        mid = (l + r)/ 2;
        if (a[mid].r > val)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    return res;
}
void init(int nut, int l, int r)
{
    if (l == r)
    {
        id[l] = nut;
        return;
    }
    int mid = (l + r)/2;
    init(nut * 2, l, mid);
    init(nut * 2 + 1, mid + 1, r);
}
void doi1(int x, int y)
{
    int nut = id[x];
    ST1[nut] = y;
    while (nut > 1)
    {
        nut /= 2;
        ST1[nut] = max(ST1[nut * 2], ST1[nut * 2 + 1]);
    }
}
void doi2(int x, int y)
{
    int nut = id[x];
    ST2[nut] = y;
    while (nut > 1)
    {
        nut /= 2;
        ST2[nut] = max(ST2[nut * 2], ST2[nut * 2 + 1]);
    }
}
int get1(int nut, int l, int r, int u, int v)
{
    if (u > v || u < 0 || v < 0) return -oo;
    if (l > v || r < u) return -oo;
    if (l >= u && r <= v) return ST1[nut];
    int mid = (l + r)/2;
    int maxl = get1(nut * 2, l, mid, u, v);
    int maxr = get1(nut * 2 + 1, mid + 1, r, u, v);
    return max(maxl, maxr);
}
int get2(int nut, int l, int r, int u, int v)
{
    if (u > v || u < 0 || v < 0) return -oo;
    if (l > v || r < u) return -oo;
    if (l >= u && r <= v) return ST2[nut];
    int mid = (l + r)/2;
    int maxl = get2(nut * 2, l, mid, u, v);
    int maxr = get2(nut * 2 + 1, mid + 1, r, u, v);
    return max(maxl, maxr);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
    cin >> n;
    for (int i = 1; i <= n; i ++)
    {
        int l, r;
        cin >> l >> r;
        a[i] = {l, r};
    }
    init(1, 1, n);
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i ++)
    {
        dp[i] = a[i].r - a[i].l;
        int k = biSearch(1, i - 1, a[i].l);
        // be hon k
        int dyna1 = get1(1, 1, n, 1, k - 1);
        int dyna2 = get2(1, 1, n, k, i - 1);
        dp[i] = max(dp[i], max(dyna1 + a[i].r - a[i].l, dyna2 + a[i].l + a[i].r));
        doi1(i, dp[i]);
        doi2(i, dp[i] - 2 * a[i].r);
    }
    cout << *max_element(dp + 1, dp + 1 + n);
}
