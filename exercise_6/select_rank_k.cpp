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
int a[maxn];

int Partition(int a[], int l, int r)
{
    int p = a[l];
    while (l < r)
    {
        while (l < r && a[r] >= p)
            --r;
        a[l] = a[r];
        while (l < r && a[l] <= p)
            ++l;
        a[r] = a[l];
    }
    a[l] = p;
    return l;
}

int select_rank_k(int a[], int l, int r, int k)
{
    int g = (r - l + 5) / 5;
    int ret = l;
    for (int i = l; i <= r; i += 5)
    {
        sort(a + i, a + i + min(5, r - i + 1));
        swap(a[ret++], a[i + min(5, r - i + 1) / 2]);
    }
    sort(a + l, a + l + g);
    swap(a[l], a[l + g / 2]);
    int cur = Partition(a, l, r) - l;
    if (cur == k - 1)
        return a[l + cur];
    else if (cur < k)
        return select_rank_k(a, cur + 1, r, k - cur - 1);
    else
        return select_rank_k(a, l, cur - 1, k);
}
int main()
{
    int A[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
	printf("%d\n", select_rank_k(A, 0, 4, 4));
	return 0;
}