/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-08 22:58:58
 * @LastEditTime : 2025-02-08 23:04:58
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P3366.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
template <typename T>
void fr(T &num)
{
    char ch;
    T sign = 1;
    ch = getchar_unlocked();
    num = 0;
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            sign = -1;
        ch = getchar_unlocked();
    }
    while (isdigit(ch))
    {
        num = num * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    (num) *= sign;
    return;
}
int n, m;
const int maxM = 2e5 + 10;
struct node
{
    int u;
    int v;
    int w;
    bool operator<(const node &t) const
    {
        return w < t.w;
    }
    bool operator>(const node &t) const
    {
        return w > t.w;
    }
} sides[maxM];
const int maxN = 5e3 + 10;
int fa[maxN];
int getFather(int x)
{
    if (fa[x] != x)
    {
        fa[x] = getFather(fa[x]);
    }
    return fa[x];
}
void bind(int x, int y)
{
    int a = getFather(x);
    int b = getFather(y);
    if (a != b)
    {
        fa[a] = b;
    }
}
int cnt;
int ans;
priority_queue<node, vector<node>,greater<node>> sidesHeap;
int main()
{
    fr(n);
    fr(m);
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i; // 初始化并查集
    }
    for (int i = 1; i <= m; i++)
    {
        fr(sides[i].u);
        fr(sides[i].v);
        fr(sides[i].w);
        sidesHeap.push(sides[i]);
    }
    // sort(sides+1,sides+1+m);
    while (!sidesHeap.empty() && cnt < n - 1)
    {
        node tmp = sidesHeap.top();
        if (getFather(tmp.u) != getFather(tmp.v)) // 不成环
        {
            cnt++;
            ans += tmp.w;
            bind(tmp.u,tmp.v);
        }
        sidesHeap.pop();
    }
    if (cnt < n - 1)
    {
        cout << "orz";
    }
    else
    {
        cout << ans;
    }
}