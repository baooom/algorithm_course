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
void merge(int A[], int T[], int S[], int len1, int len2)//将长度为len1的序列S和长度为len2的序列T进行归并，结果储存在A中
{
    int p = 0;
    int i = 0, j = 0;
    while (i < len1 && j < len2)
    {
        if(T[i]<S[j])
            A[p++] = T[i++];
        else
            A[p++] = S[j++];
    }
    while (i < len1)
        A[p++] = T[i++];
    while (j < len2)
        A[p++] = S[j++];
}

void mergeSort(int A[], int T[], int len)//递归排序
{
    if (len == 1)
        return;
    int mid = len / 2;
    mergeSort(A, T, mid);//先处理前半
    mergeSort(A + mid, T + mid, len - mid);//处理后半
    merge(T, A, A + mid, mid, len - mid);//对序列进行归并
    for (int i = 0; i < len; ++i)
        A[i] = T[i];
}
const int maxn = 1e5 + 10;
int a[maxn], temp[maxn];
int main()
{
    int n;
    read(n);
    for (int i = 0; i < n; ++i)
        read(a[i]);
    mergeSort(a, temp, n);
    for (int i = 0; i < n; ++i)
        printf("%d%c", a[i], " \n"[i == n - 1]);
}