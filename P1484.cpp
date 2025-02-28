/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-27 09:30:28
 * @LastEditTime : 2025-02-28 21:34:13
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P1484.cpp
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
int n, k;
const int maxN = 3e5 + 10;
int v[maxN];
bool vis[maxN];
struct node
{
    int v;
    int i;
    bool operator<(const node &t) const
    {
        return v < t.v;
    }
    bool operator>(const node &t) const
    {
        return v > t.v;
    }
} tmp;
priority_queue<node> q;
int ans;
int cnt;
int t;
struct node1
{
    int l;
    int r;
} li[maxN];
//为了考虑到多个点连续被合并过的情况，需要使用一个链表
bool ab[maxN];
void del(int x)//删除x左右的元素
{
    if (li[x].l != 0)
    {
        ab[li[x].l] = 1;
        if (li[li[x].l].l != 0)
        {
            li[li[li[x].l].l].r = x;
            li[x].l = li[li[x].l].l;
        }
        else
        {
            li[x].l = 0;
        }
    }
    if (li[x].r != 0)
    {
        ab[li[x].r] = 1;
        if (li[li[x].r].r != 0)
        {
            li[li[li[x].r].r].l = x;
            li[x].r = li[li[x].r].r;
        }
        else
        {
            li[x].r=0;
        }
    }
}
signed main()
{
    fr(n);
    fr(k);
    for (int i = 1; i <= n; i++)
    {
        fr(v[i]);
        tmp.v = v[i];
        tmp.i = i;
        q.push(tmp);
        li[i].l = i - 1;
        li[i].r = i + 1;
    }
    li[n].r = 0;
    while (cnt < k && !q.empty() && q.top().v > 0)
    {
        if (ab[q.top().i])
        {
            q.pop();
            continue;
        }
        tmp = q.top();
        q.pop();
        cnt++;
        ans += tmp.v;
        // vis[tmp.i]=1;
        // vis[li[tmp.i].l]=1;
        // vis[li[tmp.i].r]=1;
        // if (li[tmp.i].l < 1 || li[tmp.i].r < 1)
        // {
        //     continue;
        // }
        tmp.v = v[li[tmp.i].r] + v[li[tmp.i].l] - tmp.v;
        //这是核心的反悔操作。
        //值是如果连续旁边两个点比加入中间的一个点多出来的收益。
        //相当于把旁边两个点缩成了一个点。
        //此后的操作同理，还可以进行更多层合并。
        del(tmp.i);
        v[tmp.i] = tmp.v;
        q.push(tmp);
    }
    cout << ans << endl;
}