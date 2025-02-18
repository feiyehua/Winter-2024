/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-18 10:53:37
 * @LastEditTime : 2025-02-18 14:44:17
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P3387.cpp
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
const int maxN = 1e5 + 10;

struct node
{
    int w;
    vector<int> v;
    int dfn;
    int low;
    bool inStack;
    int scc;
} pts[maxN];
struct node1
{
    int w;
    vector<int> v;
    int in;
} np[maxN];
int u, v;
int cnt;
stack<int> stk;
const int maxM = 1e5 + 10;
pair<int, int> sides[maxM];
void tarjan(int x)
{
    cnt++;
    pts[x].dfn = cnt;
    pts[x].low = cnt;
    stk.push(x);
    pts[x].inStack = 1;
    for (auto it : pts[x].v)
    {
        if (pts[it].dfn && pts[it].inStack)
        {
            pts[x].low = min(pts[it].dfn, pts[x].low);
        }
        else if (!pts[it].dfn)
        {
            tarjan(it);
            pts[x].low = min(pts[it].low, pts[x].low);
        }
    }
    if (pts[x].low == pts[x].dfn)
    {
        while (stk.top() != x)
        {
            pts[x].w += pts[stk.top()].w;
            pts[stk.top()].inStack = 0;
            pts[stk.top()].scc = x;
            stk.pop();
        }
        pts[x].scc = x; // 单独标记scc根节点
        np[x].w=pts[x].w;
        pts[x].inStack=0;
        stk.pop();
    }
}
int dp[maxN];
void tuopu(int x)
{
    for (auto it : np[x].v)
    {
        dp[it] = max(dp[it], dp[x] + np[x].w);
        np[it].in--;
        if (np[it].in <= 0)
        {
            tuopu(it);
        }
    }
    return;
}
int ans;
int main()
{
    fr(n);
    fr(m);
    for (int i = 1; i <= n; i++)
    {
        fr(pts[i].w);
    }
    for (int i = 1; i <= m; i++)
    {
        fr(u);
        fr(v);
        sides[i].first = u;
        sides[i].second = v;
        pts[u].v.push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!pts[i].dfn)
            tarjan(i);
    }
    // 重新建图：维护ssc之间的连通性
    for (int i = 1; i <= m; i++)
    {
        if (pts[sides[i].first].scc != pts[sides[i].second].scc)
        {
            np[pts[sides[i].first].scc].v.push_back(pts[sides[i].second].scc);
            np[pts[sides[i].first].scc].w = pts[pts[sides[i].first].scc].w;
            np[pts[sides[i].second].scc].w = pts[pts[sides[i].second].scc].w;
            np[pts[sides[i].second].scc].in++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (np[i].in == 0)
        {
            tuopu(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i] + np[i].w);
    }
    cout << ans << endl;
}