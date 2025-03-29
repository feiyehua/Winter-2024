/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-29 08:05:26
 * @LastEditTime : 2025-03-29 08:26:15
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : 4701.cpp
 * @     © 2024 FeiYehua
 */
// 做这道题的时候被STL坑了两次。
// 第一次是由于一个struct的<重载写得不好，导致set直接认为两个不相同的node是相等的，最终导致有很多node没有被正确放入set中。
// 第二次是因为一边遍历迭代器，一边删除set里面的元素，导致遍历漏一些元素。解决方案是先把所有需要删除的元素拎出来，最后遍历完了再统一删除。
// 还可以使用remove_if，不过涉及到使用lamba表达式，没有时间研究了。
// 之前也被stl迭代器坑过。现在只能说，在涉及到使用迭代器的时候，尽量不要动STL容器（删除、添加等）。
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
int n, m, countR;
int d, u, p, r;
map<int, pair<int, int>> riskRegion; // 区间是左闭右开的，判断上一次连续风险时间
struct node
{
    int recieveDate;
    int d; // 用户实际访问的时间
    int u; // 用户的标号
    int r; // 用户访问的地区
    bool operator<(const node &b) const
    {
        if(recieveDate!=b.recieveDate)
        {
            return recieveDate < b.recieveDate;
        }
        else if(d!=b.d)
        {
            return d<b.d;   
        }
        else if(u!=b.u)
        {
            return u<b.u;
        }
        else
        {
            return r<b.r;
        }
    }
};
set<node> mes; // 收到的消息
// queue<node> mes;

int main()
{
    fr(n);
    for (int i = 0; i < n; i++)
    {
        fr(countR);
        fr(m);
        for (int j = 1; j <= countR; j++)
        {
            fr(p); // 当日收到的风险地区列表
            // 容易发现，风险列表一定是向前看的。也就是说，中断了就续不上了。
            // 因此，对于每个在当日到达某地区的记录，如果当日此地没有风险，这条消息一定是废消息。
            if (riskRegion.find(p) == riskRegion.end())
            {
                riskRegion.insert(make_pair(p, make_pair(i, i + 7)));// 区间是左闭右开的
            }
            else
            {
                if (riskRegion[p].second < i)
                {
                    riskRegion[p].first = i;
                }
                riskRegion[p].second = i + 7;
            }
        }
        for (int j = 1; j <= m; j++)
        {
            fr(d);
            fr(u);
            fr(r);
            // 当日收到的漫游数据
            node t = {.recieveDate = i, .d = d, .u = u, .r = r};
            mes.insert(t);
        }
        set<int> listOfRiskUser;
        set<node> toRemove;
        for(auto it:mes)
        {
            if(it.d<=i-7||it.recieveDate<=i-7)// 保证接收日期在近七天，且漫游数据的时间在近七天
            {
                toRemove.insert(it);
                continue;
            }
            if(riskRegion.find(it.r)!=riskRegion.end()&&(riskRegion[it.r].first<=it.d&&riskRegion[it.r].second>i))
            {
                listOfRiskUser.insert(it.u);
            }
        }
        for(auto it:toRemove)
        {
            mes.erase(it);
        }
        printf("%d ",i);
        for(auto it:listOfRiskUser)
        {
            printf("%d ",it);
        }
        printf("\n");
    }
}