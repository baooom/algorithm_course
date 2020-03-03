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
const int maxn = 2e3 + 10;
int mmp[maxn][maxn];
int dis[maxn];
bool vis[maxn];
int dijkstra(int s, int t, int n)
{
    memset(dis, 0x3f, sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[s] = 0;
    for (int i = 1; i <= n; ++i)
    {
        int v = 0;
        for (int j = 1; j <= n; ++j)//遍历找到最近的点
        {
            if (!vis[j] && dis[j] < dis[v])
                v = j;
        }
        vis[v] = 1;
        for (int j = 1; j <= n; ++j)//用这个点更新所有的距离
        {
            dis[j] = min(dis[j], dis[v] + mmp[v][j]);
        }
    }
    return dis[t];
}
int main()
{
    int n, m, s, t;
    int u, v, w;
    read(n), read(m);
    memset(mmp, 0x3f, sizeof mmp);
    for (int i = 0; i < m; ++i)
    {
        read(u), read(v), read(w);
        mmp[u][v] = min(mmp[u][v], w);//如果有重边，选择最短的
    }
    read(s), read(t);
    printf("%d\n", dijkstra(s, t, n));
}