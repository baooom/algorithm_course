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
    FILE* _INPUT=freopen("../input.txt", "r", stdin);
    // FILE* _OUTPUT=freopen("output.txt", "w", stdout);
#endif
using namespace std;
const int maxn = 1e5 + 10;
struct EDGE
{
    int next, to;
} edge[maxn];
int head[maxn], tot;
inline void addedge(int u,int v)
{
    edge[tot] = {head[u], v};
    head[u] = tot++;
}
int node;
int rid[maxn];
char code[maxn];
void encode(int u,int cnt)
{
    code[cnt] = 0;
    if(rid[u])
    {
        printf("Code of %d : %s\n", rid[u], code);
        return;
    }
    for (int i = head[u], c = 0; ~i; i = edge[i].next, c ^= 1)
    {
        int v = edge[i].to;
        code[cnt] = '0' + c;
        encode(v, cnt + 1);
    }
}
int main()
{
    int n;
    int t;
    memset(head, -1, sizeof head);
    scanf("%d", &n);
    priority_queue<pii, vector<pii>, greater<pii>> q;
    for (int i = 1; i <= n; ++i)
    {
        read(t);
        q.push(pii(t, ++node));
        rid[i] = node;
    }
    while (q.size() > 1)
    {
        pii u = q.top();
        q.pop();
        pii v = q.top();
        q.pop();
        addedge(++node, u.second);
        addedge(node, v.second);
        q.push(pii(u.first + v.first, node));
    }
    int root = q.top().second;
    q.pop();
    encode(root, 0);
}