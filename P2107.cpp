/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-25 16:12:33
 * @LastEditTime : 2025-02-26 20:02:01
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P2107.cpp
 * @     © 2024 FeiYehua
 */
/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-25 16:12:33
 * @LastEditTime : 2025-02-25 20:47:36
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P2107.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
#define int long long
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
struct node
{
    int x, t;
    bool operator<(const node &t) const
    {
        return x < t.x;
    }
    bool operator>(const node &t) const
    {
        return x > t.x;
    }
} tmp;
priority_queue<node, vector<node>, greater<node>> q;
int t;
int lastT;
priority_queue<int> w;
int ans;
signed main()
{
    fr(n);
    fr(m);
    for (int i = 1; i <= n; i++)
    {
        fr(tmp.x);
        fr(tmp.t);
        q.push(tmp);
    }
    while (!q.empty())
    {
        t = t + q.top().x - lastT;
        // if(t+q.top().t<=m)
        // {
        w.push(q.top().t);
        t += q.top().t;
        // }
        // else if(!w.empty()&&q.top().t<w.top() && t+q.top().t-w.top()<=m )
        // {
        //     t+=(q.top().t-w.top());
        //     w.pop();
        //     w.push(q.top().t);
        // }
        while (!w.empty() && t > m)
        {
            t -= w.top();
            w.pop();
        }
        lastT = q.top().x;
        q.pop();
        ans=max(ans,(int)w.size());
    }
    cout << ans << endl;
}
//由于有走路时间的存在，可能会错过某些思考时间少的机房，最终错过最优解。
// 5 18
// 2 8
// 4 7
// 6 3
// 7 1
// 采用的解决方案是，每次向前走，都将新遇到的机房加入，再弹出机房，直至时间满足题意。
// 首先，显然走路时间只会增加，这样子弹出一定是正确的操作，即在此前已经决定不访问的机房，在之后也一定不会访问。
// 并且，在每次弹出过程中，都求出了走到这个机房的情况下的最优解，合起来就是全局最优解。而不会出现被某路程给卡住的情况。