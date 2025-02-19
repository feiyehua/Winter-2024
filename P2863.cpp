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
int in0SCCCnt;
int ans;
const int maxN = 1e4 + 10;
const int maxM = 5e4 + 10;
stack<int> stk;
pair<int, int> sides[maxM];
struct node
{
    int low;
    int dfn;
    vector<int> v;
    bool inStack;
    int scc;
    int cnt=1;
} cows[maxN];
struct node1
{
    int cnt; // 统计喜欢的scc数量
    vector<int> v;
    int in;
    bool isSCC;
} scc[maxN];
void tarjan(int x)
{
    cnt++;
    cows[x].dfn = cows[x].low = cnt;
    cows[x].inStack = 1;
    stk.push(x);
    for (auto it : cows[x].v)
    {
        if (cows[it].inStack)
        {
            cows[x].low = min(cows[it].dfn, cows[x].low);
        }
        else if (!cows[it].dfn)
        {
            tarjan(it);
            cows[x].low = min(cows[x].low, cows[it].low);
        }
    }
    if (cows[x].low == cows[x].dfn)
    {
        while (stk.top() != x)
        {
            int top = stk.top();
            stk.pop();
            cows[x].cnt+=cows[top].cnt;
            cows[top].scc = x;
            cows[top].inStack = 0;
        }
        cows[x].inStack = 0;
        cows[x].scc = x;
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
        cows[sides[i].first].v.push_back(sides[i].second);
    }
    for(int i=1;i<=n;i++)
    {
        if(!cows[i].dfn)
        {
            tarjan(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(cows[i].scc==i&&cows[i].cnt>1)
        {
            // scc[i].isSCC=1;
            ans++;
        }
    }
    cout<<ans;
}