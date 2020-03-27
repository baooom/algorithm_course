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
};

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

double cal(vector<point> &p, vector<point> &q)
{
    if (p.size() == 1)
        return inf;
    if (p.size() == 2)
        return dis(p[0], p[1]);
    int px = p[p.size() / 2 - 1].x;
    vector<point> left_p, right_p, left_q, right_q;
    for (int i = 0; i < p.size(); ++i)
    {
        if(i<p.size()/2)
            left_p.push_back(p[i]);
        else
            right_p.push_back(p[i]);
        if (q[i].x < px)
            left_q.push_back(q[i]);
        else
            right_q.push_back(q[i]);
    }
    double d = min(cal(left_p, left_q), cal(right_p, right_q));
    int totl = 0, totr = 0;
    for (int i = 0; i < left_q.size(); ++i)
    {
        if (px - left_q[i].x < d)
            swap(left_q[totl++], left_q[i]);
    }
    for (int i = 0; i < right_q.size(); ++i)
    {
        if (right_q[i].x - px < d)
            swap(right_q[totr++], right_q[i]);
    }
    for (int i = 0; i < left_q.size(); ++i)
    {
        int begin = lower_bound(right_q.begin(), right_q.end(), left_q[i], cmpy) - right_q.begin();
        begin = max(0, begin - 3);
        for (int j = begin; j < right_q.size(); ++j)
        {
            if (right_q[j].y - left_q[i].y > d)
                break;
            d = min(d, dis(left_q[i], right_q[j]));
        }
    }
    return d;
}

int main()
{
    int n;
    read(n);
    vector<point> p(n), q(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lf%lf", &p[i].x, &p[i].y);
        q[i] = p[i];
    }
    sort(p.begin(), p.end(), cmpx);
    sort(q.begin(), q.end(), cmpy);
    printf("%.6f\n", cal(p, q));
}