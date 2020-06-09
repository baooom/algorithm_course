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
    FILE* _INPUT=freopen("../input.txt", "r", stdin);
    // FILE* _OUTPUT=freopen("output.txt", "w", stdout);
#endif
using namespace std;
const int maxn = 20;
struct Circle{
    double dot, radius;
    Circle(double dot,double radius):dot(dot),radius(radius){}
    Circle(){}
};//圆类
double getCenter(Circle a,Circle b){
    return a.dot + 2 * sqrt(a.radius * b.radius);
}//计算若圆a,b相切且圆a在前，则圆b的圆心横坐标位置

Circle temp[maxn], C[maxn], best[maxn]; //temp为回溯用的辅助数组，C为输入数组,best表示最优的排列方式
bool used[maxn];//表示某个圆已经被使用，防止重复计算同一个圆
int n;
double minWidth;//最小距离，初始化为每个直径之和，每次得到合法答案后取最小值
void dfs(int cur){
    for (int i = 0; i < n; ++i){
        if(!used[i]){//每次尝试的圆必须是没有使用过的
            used[i] = 1;
            if (cur == 0){//如果是第一个圆，则直接计算
                temp[cur] = Circle(C[i].radius, C[i].radius);
            }else{//否则需要向前遍历所有的圆来得到当前尝试的圆的圆心横坐标
                double newDot = getCenter(temp[cur - 1], C[i]);
                for (int j = cur - 2; j >= 0; --j){
                    newDot = max(newDot, getCenter(temp[j], C[i]));
                }
                temp[cur] = Circle(newDot, C[i].radius);
            }
            if(temp[cur].dot+temp[cur].radius>=minWidth){//如果此时的长度已经超过已经得到的答案，则没有继续搜索的必要
                used[i] = 0;
                continue;
            }
            if (cur == n - 1){//如果当前是最后一个圆，则对答案取最小值
                if (temp[cur].dot + temp[cur].radius < minWidth){
                    minWidth = temp[cur].dot + temp[cur].radius;
                    for (int j = 0; j < n; ++j){
                        best[j] = temp[j];
                    }
                }
                used[i] = 0;
                continue;
            }
            dfs(cur + 1);
            used[i] = 0;
        }
    }
}

int main(){
    scanf("%d", &n);
    minWidth = 0;
    for (int i = 0; i < n;++i){
        scanf("%lf", &C[i].radius);
        minWidth += C[i].radius * 2;//初始化最小值为所有圆的直径之和，易证最小宽度不会超过这个值
    }
    dfs(0);
    printf("shorest width:%.2f\n", minWidth);
    puts("best Circle Permutation:");
    for (int i = 0; i < n; ++i){
        printf("%.2f ", best[i].radius);
    }
}


//