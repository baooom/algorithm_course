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
int p[maxn], a[maxn], b[maxn];
int s[maxn][maxn], dp[maxn][maxn];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
    {
        scanf("%d", p + i);
    }
    for (int i = 1; i <= n - 1; ++i)
    {
        a[i] = p[i];
        b[i] = p[i + 1];
    }
    clock_t pre = clock();
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n - 1; ++i)
        dp[i][i] = 0, s[i][i] = i;
    for (int len = 2; len <= n - 1; ++len)
    {
        for (int l = 1, r; l + len - 1 <= n - 1; ++l)
        {
            r = l + len - 1;
            int cur = a[l] * b[r];
            for (int k = l; k < r; ++k)
            {
                if (dp[l][k] + dp[k + 1][r] + cur * b[k] < dp[l][r])
                {
                    s[l][r] = k;
                    dp[l][r] = dp[l][k] + dp[k + 1][r] + cur * b[k];
                }
            }
        }
    }
    printf("%d\n", dp[1][n - 1]);
    printf("time used:%f\n", (clock() - pre) * 1.0 / CLOCKS_PER_SEC);
}