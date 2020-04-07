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
    FILE* _INPUT=freopen("..\\input.txt", "r", stdin);
    // FILE* _OUTPUT=freopen("output.txt", "w", stdout);
#endif
using namespace std;
int f[5][6] = {
    {0},
    {0, 11, 12, 13, 14, 15},
    {0, 0, 5, 10, 15, 20},
    {0, 2, 10, 30, 32, 40},
    {0, 20, 21, 22, 23, 24}};
int dp[5][110];
int main()
{
    ll res = 0;
    for (int i = 1; i <= 4; ++i)
    {
        for (int j = 109; j >= 0; --j)
        {
            for (int k = 0; j - k >= 0 && k <= 5; ++k)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - k] + f[i][k]);
            }
        }
    }
    for (int i = 0; i < 110; ++i)
    {
        printf("%d:%d\n", i, dp[4][i]);
    }
}