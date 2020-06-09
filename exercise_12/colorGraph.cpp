// #pragma GCC optimize(3,"Ofast","inline")
// #pragma GCC optimize(2)
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
#include <iomanip>
#include <unordered_map>
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
// char buf[(1 << 21) + 1], * p1 = buf, * p2 = buf;
// #define int long long
#define lowbit(x) (x & (-x))
#define lson root << 1, l, mid
#define rson root << 1 | 1, mid + 1, r
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, ll> pll;
typedef std::vector<ll> VI;
#define rep(i, a, n) for (int i = a; i < n; ++i)
#define SZ(x) ((int)((x).size()))
#define bug puts("BUG")
const long long INF = 0x3f3f3f3f3f3f3f3fLL;
const int inf = 0x3f3f3f3f;
const int mod = 998244353;
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
const int maxn = 1010;
const int maxcolor = 20;
int colored[maxn];//第i个点的颜色
int n, m, k;
int counter;
int uncolored;
struct EDGE{
    int next, to;
} edge[maxn * maxn];
int head[maxn], tot;
inline void addedge(int u,int v){
    edge[tot] = {head[u], v};
    head[u] = tot++;
}
void dfs(int u, int c){
    for (int i = head[u]; ~i; i = edge[i].next){//如果周围存在同色的点，则直接剪枝
        int v = edge[i].to;
        if(colored[v] == c)
            return;        
    }
    colored[u] = c;
    --uncolored;
    if( uncolored == 0){//如果不存在没有被染色的点，则是一种染色方案
        ++counter;
        ++uncolored;
        colored[u] = 0;
        return;
    }
    for (int j = 1; j <= k; ++j){
        if (j == c)//当前点的颜色必定不可能出现在相邻的点
            continue;
        for (int i = head[u]; ~i;i=edge[i].next){
            int v = edge[i].to;
            if( colored[v] )//如果已经被染色，则跳过，只尝试蓝色没有被染色过的点
                continue;
            dfs(v, j);
        }
    }
    colored[u] = 0;
    ++uncolored;
}

int main(){
    scanf("%d %d %d", &n, &m, &k);//n个点，m条边，k种颜色的总涂色方案数
    memset(head, -1, sizeof head);
    tot = 0;
    memset(colored, 0, sizeof colored);
    uncolored = n;
    int u, v;
    for (int i = 0; i < m; ++i){
        scanf("%d %d", &u, &v);
        addedge(u, v);
        addedge(v, u);
    }
    for (int i = 1; i <= k; ++i){
        dfs(1, i);//选取一个起点，对它尝试进行染色
    }
    if(counter > 0)
        printf("%d\n", counter);
    else
        puts("NO");
}

/*
3 2 10
1 2
2 3
3个点的链，用10种颜色
3 2 1
1 2
2 3
3个点的链，用1种颜色
*/