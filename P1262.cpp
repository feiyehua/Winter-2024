/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-18 15:05:56
 * @LastEditTime : 2025-02-18 15:20:48
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P1262.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
bool frontf;
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
int m, n;
const int maxN = 3e3 + 10;
int p;
int tmp;
const int INF = 1e8 + 10;
struct node
{
    int w = INF;
    vector<int> v;
    int dfn;
    int low;
    bool inStack;
    int scc;
} spy[maxN];
stack<int> stk;
int r, u, v;
int cnt;
void tarjan(int x)
{
    cnt++;
    spy[x].dfn = cnt;
    spy[x].low = cnt;
    spy[x].inStack = 1;
    stk.push(x);
    for (auto it : spy[x].v)
    {
        if (spy[it].inStack)
        {
            spy[x].low = min(spy[x].low, spy[it].dfn);
        }
        else if (!spy[it].dfn)
        {
            tarjan(it);
            spy[x].low = min(spy[it].low, spy[x].low);
        }
    }
    if (spy[x].dfn == spy[x].low)
    {
        while (stk.top() != x)
        {
            int top = stk.top();
            stk.pop();
            spy[top].inStack = 0;
            spy[top].scc = x;
            spy[x].w = min(spy[top].w, spy[x].w);
        }
        stk.pop();
        spy[x].scc = x;
        spy[x].inStack = 0;
    }
}
const int maxR = 8e3 + 10;
pair<int, int> sides[maxR];
struct node1
{
    int u;
    int w;
    vector<int> v;
    int in;
    bool vis;
} newspy[maxN];
int ans;
int reachableSCC[maxN];
void tuopu(int x)
{
    newspy[x].vis = 1;
    for (auto it : newspy[x].v)
    {
        reachableSCC[it] = 1;
        // newspy[it].in--;
        if (!newspy[it].vis)
        {
            tuopu(it);
        }
    }
}
bool isSCC[maxN];
bool endF;
int main()
{
    // cout<<(&endF-&frontf)<<endl;
    fr(n);
    fr(p);
    for (int i = 1; i <= p; i++)
    {
        fr(tmp);
        fr(spy[tmp].w);
    }
    fr(r);
    for (int i = 1; i <= r; i++)
    {
        fr(u);
        fr(v);
        sides[i].first = u;
        sides[i].second = v;
        spy[u].v.push_back(v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!spy[i].dfn)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= r; i++)
    {
        int x = spy[sides[i].first].scc;
        int y = spy[sides[i].second].scc;
        if (x != y)
        {
            newspy[y].in++;
            newspy[x].v.push_back(y);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int scc = spy[i].scc;
        isSCC[scc] = 1;
        newspy[scc].w = spy[scc].w;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!isSCC[i])
        {
            continue;
        }
        if (newspy[i].in == 0 && !newspy[i].vis)
        {
            newspy[i].vis = 1;
            if (newspy[i].w < INF)
            {
                reachableSCC[i] = 1;
                tuopu(i);
                ans += newspy[i].w;
            }
            else
            {
                ans = INF + 10;
            }
        }
    }
    if (ans < INF)
    {
        cout << "YES\n"
             << ans;
        return 0;
    }
    //上面只能解决一张图的连通性问题。
    //下面解决那些由于起始点为INF而导致的没有被访问到的点
    for(int i=1;i<=n;i++)
    {
        if(isSCC[i]&&newspy[i].w<INF)
        {
            reachableSCC[i]=1;
            tuopu[i];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int scc = spy[i].scc;
        if (!reachableSCC[scc])
        {
            cout << "NO\n"
                 << i;
            return 0;
        }
    }
}