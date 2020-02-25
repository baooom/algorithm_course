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
    int next, to, w;
} edge[maxn << 1];
int head[maxn], tot;
inline void addedge(int u, int v, int w)
{
    edge[tot] = {head[u], v, w};
    head[u] = tot++;
}
struct node
{
    int u, v, w;
    node(int _u, int _v, int _w) : u(_u), v(_v), w(_w){}
    bool operator < (const node& other)const
    {
        return w > other.w;
    }
};

int f[maxn];
int find(int x)
{
    return x == f[x] ? f[x] : f[x] = find(f[x]);
}

void joint(int u, int v)
{
    int fu = find(u), fv = find(v);
    if (u != v)
        f[fu] = fv;
}

ll prim(int s)
{
    priority_queue<node> q;
    for (int i = head[s]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        q.push(node(s, v, edge[i].w));
    }
    ll res = 0;
    while(!q.empty())
    {
        int u = q.top().u, v = q.top().v, w = q.top().w;
        q.pop();
        if (find(u) == find(v))
            continue;
        res += w;
        joint(u, v);
        for (int i = head[v]; ~i; i = edge[i].next)
        {
            int t = edge[i].to;
            if(find(v)==find(t))
                continue;
            q.push(node(v, t, edge[i].w));
        }
    }
    return res;
}

int main()
{
    int n, m;
    int u, v, w;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        f[i] = i;
        head[i] = -1;
    }
    for (int i = 0; i < m; ++i)
    {
        scanf("%d%d%d", &u, &v, &w);
        addedge(u, v, w);
        addedge(v, u, w);
    }
    printf("%lld\n", prim(1));
    return 0;
}