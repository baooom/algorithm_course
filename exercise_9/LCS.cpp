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
#include <time.h>
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
    FILE* _INPUT=freopen("..\\input.txt", "r", stdin);
    // FILE* _OUTPUT=freopen("output.txt", "w", stdout);
#endif
using namespace std;
const int maxn = 1010;
int dp[maxn][maxn];
int s[maxn], t[maxn];
int ds[maxn][maxn], dt[maxn][maxn];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    memset(dp, 0, sizeof dp);
    memset(ds, 0, sizeof ds);
    memset(dt, 0, sizeof dt);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", s + i);
    }
    for (int i = 1; i <= m; ++i)
    {
        scanf("%d", t + i);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            if (s[i] == t[j])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                if (dp[i - 1][j] > dp[i][j - 1])
                {
                    ds[i][j] = 1;
                }else
                {
                    dt[i][j] = 1;
                }
            }
        }
    }
    printf("%d\n", dp[n][m]);
    stack<int> stk;
    int l = n, r = m;
    while (l > 0 && r > 0)
    {
        if (s[l] == t[r])
        {
            stk.push(s[l]);
            --l;
            --r;
        }else
        {
            l -= ds[l][r];
            r -= dt[l][r];
        }
    }
    while(!stk.empty())
    {
        printf("%d ", stk.top());
        stk.pop();
    }
}

/*
16 17
24 13 29 24 8 23 28 24 17 8 5 3 24 22 10 8 
9 22 21 17 23 30 25 17 17 22 19 21 23 30 11 26 12 
*/