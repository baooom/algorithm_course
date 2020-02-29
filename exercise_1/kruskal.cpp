// #pragma GCC optimize(3,"Ofast","inline")
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <cstdlib>
#include <bitset>
#include <assert.h>
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
// char buf[(1 << 21) + 1], * p1 = buf, * p2 = buf;
// #define int long long
#define lowbit(x) (x & (-x))
#define lson root << 1, l, mid
#define rson root << 1 | 1, mid + 1, r
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair<ll, ll> pii;
#define bug puts("BUG")
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const double eps = 1e-6;
template <class T>
inline void read(T &x)
{
    int sign = 1;char c = getchar();x = 0;
    while (c > '9' || c < '0'){if (c == '-')sign = -1;c = getchar();}
    while (c >= '0' && c <= '9'){x = x * 10 + c - '0';c = getchar();}
    x *= sign;
}
#ifdef LOCAL
    FILE* _INPUT=freopen("input.txt", "r", stdin);
    // FILE* _OUTPUT=freopen("output.txt", "w", stdout);
#endif
using namespace std;
const int maxn = 1e5 + 10;
struct EDGE
{
    int u, v, w;
    bool operator < (const EDGE& other)const
    {
        return w < other.w;
    }
} edge[maxn];
int f[maxn];
int find(int x)
{
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}
void joint(int u,int v)
{
    int fu = find(u), fv = find(v);
    if(fu!=fv)
        f[fu] = fv;
}
ll kruskal(int n,int m)
{
    sort(edge, edge + m);
    ll res = 0;
    int tot = 0;
    for (int i = 0; i < m; ++i)
    {
        if (find(edge[i].u) != find(edge[i].v))
        {
            joint(edge[i].u, edge[i].v);
            res += edge[i].w;
            ++tot;
        }
        if (tot == n - 1)
            break;
    }
    return res;
}
int main()
{
    int n, m;
    int u, v, w;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        f[i] = i;
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    printf("%lld\n", kruskal(n, m));
}