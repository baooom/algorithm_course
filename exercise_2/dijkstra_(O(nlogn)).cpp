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
int dis[maxn];
struct EDGE
{
    int next, to, w;
} edge[maxn << 1];
int head[maxn], tot;
inline void addedge(int u,int v,int w)
{
    edge[tot] = {head[u], v, w};
    head[u] = tot++;
}
int dis[maxn];
bool vis[maxn];
struct NODE
{
    int v, w;
    NODE(){}
    NODE(int _v,int _w):v(_v),w(_w){}
    bool operator < (const NODE& other)const
    {
        return w > other.w;//stl的优先队列是大顶堆，需要重载小于号为大于
    }
};
int dijkstra(int s,int t)
{
    priority_queue<NODE> q;
    memset(dis, 0x3f, sizeof dis);
    q.push(NODE(s, 0));
    dis[s] = 0;
    while (!q.empty())
    {
        NODE u = q.top();//从优先对内中取出最近的点
        q.pop();
        vis[u.v] = 1;
        for (int i = head[u.v]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if(vis[v])
                continue;
            if (dis[v] > dis[u.v] + edge[i].w)
            {
                dis[v] = dis[u.v] + edge[i].w;//更新距离
                q.push(NODE(v, dis[v]));
            }
        }
    }
    return dis[t];
}
int main()
{
    int n, m, s, t;
    int u, v, w;
    read(n), read(m);
    for (int i = 0; i < m; ++i)
    {
        read(u), read(v), read(w);
        addedge(u, v, w);
    }
    read(s), read(t);
    printf("%d\n", dijkstra(s, t));
}