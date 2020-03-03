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
const int maxn = 510;
int mmp[maxn][maxn];//邻接矩阵存图
void floyd(int n)
{
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                mmp[i][j] = min(mmp[i][j], mmp[i][k] + mmp[k][j]);//floyd算法的状态转移方程
            }
        }
    }
}
int main()
{
    int u, v, w;
    int n, m;
    memset(mmp, 0x3f, sizeof mmp);//以0x3f3f3f3f作为无穷大，即便*2也不超过int能表示的上限
    read(n), read(m);
    for (int i = 0; i < m; ++i)
    {
        read(u), read(v), read(w);
        mmp[u][v] = min(mmp[u][v],w);//如果有重边，选择最短的
    }
    for (int i = 1; i <= n; ++i)//默认自己到自己的距离为0
        mmp[i][i] = 0;
    floyd(n);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            printf("%d%c", mmp[i][j] == inf ? -1 : mmp[i][j], " \n"[j == n]);
        }
    }
}