/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-10 15:58:49
 * @LastEditTime : 2025-02-10 16:03:59
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P3385.cpp
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
int t;
int n, m, u, v, w;
const int maxM = 3e3 + 10;
const int maxN = 2e3 + 10;
int cnt[maxN];
bool inQ[maxN];
long long dis[maxN];
vector<vector<pair<int, int>>> sides(maxN, vector<pair<int, int>>(0));
void spfa()
{
    // spfa判断环
    memset(cnt, 0, sizeof cnt);
    memset(inQ, 0, sizeof inQ);
    memset(dis, 0x3f, sizeof dis);
    queue<int> q;
    q.push(1);
    dis[1] = 0;
    cnt[1]++;
    while (!q.empty())
    {
        int h = q.front();
        inQ[h] = 0;
        q.pop();
        for (auto it : sides[h])
        {
            if (dis[it.first] > dis[h] + it.second)
            {
                dis[it.first] = dis[h] + it.second;
                if (!inQ[it.first])
                {
                    q.push(it.first);
                    inQ[it.first] = 1;
                    cnt[it.first]++;
                    if (cnt[it.first] >= n)
                    {
                        cout << "YES\n";
                        return;
                    }
                }
            }
        }
    }
    cout << "NO\n";
}
int main()
{
    fr(t);
    while (t--)
    {
        fr(n);
        for (int i = 1; i <= n; i++)
        {
            sides[i].clear();
        }
        fr(m);
        for (int i = 1; i <= m; i++)
        {
            fr(u);
            fr(v);
            fr(w);
            sides[u].push_back(make_pair(v, w));
            if (w >= 0)
            {
                sides[v].push_back(make_pair(u, w));
            }
        }
        spfa();
    }
}