/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-19 20:03:38
 * @LastEditTime : 2025-02-19 20:17:05
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P2002.cpp
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
int cnt;
int ans;
const int maxN = 1e5 + 10;
const int maxM = 5e5 + 10;
struct node
{
    int low;
    int dfn;
    vector<int> v;
    bool inStack;
    int scc;
} cities[maxN];
pair<int, int> sides[maxM];
stack<int> stk;
struct node1
{
    int in;
    vector<int> v;
    bool isSCC;
} nc[maxN];
void tarjan(int x)
{
    cnt++;
    cities[x].dfn = cities[x].low = cnt;
    cities[x].inStack = 1;
    stk.push(x);
    for (auto it : cities[x].v)
    {
        if (cities[it].inStack)
        {
            cities[x].low = min(cities[it].dfn, cities[x].low);
        }
        else if (!cities[it].dfn)
        {
            tarjan(it);
            cities[x].low = min(cities[x].low, cities[it].low);
        }
    }
    if (cities[x].low == cities[x].dfn)
    {
        while (stk.top() != x)
        {
            int top = stk.top();
            stk.pop();
            cities[top].scc = x;
            cities[top].inStack = 0;
        }
        cities[x].inStack = 0;
        cities[x].scc = x;
        stk.pop();
    }
}
int main()
{
    fr(n);
    fr(m);
    for (int i = 1; i <= m; i++)
    {
        fr(sides[i].first);
        fr(sides[i].second);
        cities[sides[i].first].v.push_back(sides[i].second);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!cities[i].dfn)
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int x = cities[sides[i].first].scc;
        int y = cities[sides[i].second].scc;
        if (x != y)
        {
            nc[x].v.push_back(y);
            nc[y].in++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cities[i].scc == i)
        {
            nc[i].isSCC = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (nc[i].isSCC && nc[i].in == 0)
        {
            ans++;
            // tuopu(i);
        }
    }
    cout << ans;
}