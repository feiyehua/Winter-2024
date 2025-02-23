/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-23 12:24:41
 * @LastEditTime : 2025-02-23 12:30:29
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P3545.cpp
 * @     © 2024 FeiYehua
 */
/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-23 12:24:41
 * @LastEditTime : 2025-02-23 12:26:54
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P3545.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
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
int n;
const int maxN = 3e5 + 10;
int a[maxN];
int b[maxN];
int tot;
priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
signed main()
{
    fr(n);
    for (int i = 1; i <= n; i++)
    {
        fr(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        fr(b[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        tot += a[i];

        if (tot >= b[i])//可以直接满足
        {
            tot-=b[i];
            q.push(make_pair(b[i], i));
        }
        else if(!q.empty())
        {
            if(tot>=-q.top().first+b[i]&&q.top().first>b[i])
            {
                tot-=-q.top().first+b[i];
                q.pop();
                q.push(make_pair(b[i], i));
            }
        }
    }
    cout<<q.size()<<endl;
    while(!q.empty())
    {
        cout<<q.top().second<<" ";
        q.pop();
    }
}