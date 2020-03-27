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
const int maxn = 1e5 + 10;
struct point
{
    double x, y;
} p[maxn];

double dis(point a,point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool cmpx(point a,point b)
{
    return a.x < b.x;
}
bool cmpy(point a,point b)
{
    return a.y < b.y;
}
double cal(point a[],int len)
{
    if(len==1)
        return inf;
    if(len==2)
        return dis(a[0], a[1]);
    double p = a[len / 2 - 1].x;
    int mid = len / 2;
    double d = min(cal(a, mid), cal(a + mid, len - mid));
    int tot = 0;
    for (int i = 0; i < len; ++i)
        if (fabs(p - a[i].x) <= d)
            swap(a[tot++], a[i]);
    sort(a, a + tot, cmpy);
    for (int i = 0; i < tot; ++i)
    {
        for (int j = i + 1; j < tot; ++j)
        {
            if (a[j].y - a[i].y > d)
                break;
            d = min(d, dis(a[i], a[j]));
        }
    }
    return d;
}

int main()
{
    int n;
    read(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
    }
    sort(p, p + n, cmpx);
    printf("%.6f\n", cal(p, n));
}