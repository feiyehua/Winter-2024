/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-22 11:47:38
 * @LastEditTime : 2025-02-22 19:22:14
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P3045.cpp
 * @     © 2024 FeiYehua
 */
/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-22 11:47:38
 * @LastEditTime : 2025-02-22 12:18:47
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P3045.cpp
 * @     © 2024 FeiYehua
 */
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
const int maxN = 5e4 + 10;
const ll maxM = 1e14 + 10;
int n, k;
ll m;
struct node
{
    int p, c;
    int dis;
    bool operator<(const node &t) const
    {
        return p < t.p;
    }
    bool operator>(const node &t) const
    {
        return p > t.p;
    }
} c[maxN];
bool cmp(const node& t1,const node& t2){
    return t1.c<t2.c;
}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
priority_queue<int,vector<int>,greater<int>> dis;
queue<int> pending;
int cnt;
ll tot; // 当前花费的总钱数

int main()
{
    fr(n);
    fr(k);
    fr(m);
    for (int i = 1; i <= n; i++)
    {
        fr(c[i].p);
        fr(c[i].c);
        c[i].dis = c[i].p - c[i].c;
    }
    sort(c + 1, c + 1 + n,cmp);
    int i = 1;
    for (; i <= k; i++)
    {
        q.push(make_pair(c[i].dis,i)); // 放入可用的虚拟优惠券
        if (tot + c[i].c <= m)
        {
            tot += c[i].c;
            cnt++;
        }
        else 
        {
            break;
        }
    }
    if (i <= k)
    {
        cout <<cnt<<endl;
        return 0;
    }
    //此时已有的优惠券已经用完
    //按照原价顺序排序
    sort(c+1+k,c+1+n);
    while(i<=n)
    {
        while(!pending.empty()&&c[pending.front()].p+tot<=m)
        {
            int t=pending.front();
            if(q.top().first<c[t].dis)//在q堆顶用券没有对i用券划算
            {
                dis.push(c[q.top().second].p);//q堆顶以原价入队
                q.pop();//移除q堆顶元素
                q.push(make_pair(c[t].dis,t));
                tot+=(q.top().first-c[t].dis);
            }
            else 
            {
                dis.push(c[t].p);//i原价入队
                tot+=c[t].p;
            }
            pending.pop();
            cnt++;
        }
        if(c[i].p+tot<=m)//可以直接不用券买
        {
            if(q.top().first<c[i].dis)//在q堆顶用券没有对i用券划算
            //！在这里，应该是用i替换一个原价最小的牛，而不是q堆顶的牛。何必在同一棵树上吊死呢？
            {
                dis.push(c[q.top().second].p);//q堆顶以原价入队
                q.pop();//移除q堆顶元素
                q.push(make_pair(c[i].dis,i));
                tot+=(q.top().first-c[i].dis+c[i].p);
            }
            else 
            {
                dis.push(c[i].p);//i原价入队
                tot+=c[i].p;
            }
            cnt++;
        }
        else
        //此时已经不能直接买了。需要抢券，容易发现一定不会替换其他用原价买的牛。
        {
            if(c[i].p+q.top().first-c[i].dis<=m)//在q堆顶用券没有对i用券划算
            {
                dis.push(c[q.top().second].p);//q堆顶以原价入队
                q.pop();//移除q堆顶元素
                q.push(make_pair(c[i].dis,i));
                tot+=(q.top().first-c[i].dis+c[i].p);
                cnt++;
            }
            else
            {
                //选择不买。但是以后如果出现了使tot足够小的情况，还是可以直接买这头牛的。
                pending.push(i);
            }
        }
        i++;
    }
    cout<<cnt;
}
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
template<typename T>
void fr(T& num)
{
    char ch;
    T sign=1;
    ch=getchar_unlocked();
    num=0;
    while(ch>'9'||ch<'0')
    {
        if(ch=='-') sign=-1;
        ch=getchar_unlocked();
    }
    while(isdigit(ch))
    {
        num=num*10+ch-'0';
        ch=getchar_unlocked();
    }
    (num)*=sign;
    return;
}
const int maxN=5e4+10;
int n,k,m;
struct cow{
    int p,c;
}cows[maxN];
struct node{
    int save,i;//存储用券的优惠金额，用券的下标
    bool operator<(const node& t)const 
    {
        return save<t.save;
    }
    bool operator>(const node& t)const 
    {
        return save>t.save;
    }
};
bool buy[maxN];
int sum,cnt;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> p;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> c;
priority_queue<node,vector<node>,greater<node>> t;//记录用券信息
signed main()
{
    fr(n);
    fr(k);
    fr(m);
    for(int i=1;i<=n;i++)
    {
        fr(cows[i].p);
        fr(cows[i].c);
        // fr(t);
        p.push(make_pair(cows[i].p,i));//原价队列
        // fr(t);
        c.push(make_pair(cows[i].c,i));//优惠价队列
    }
    while(!p.empty()&&!c.empty())
    {
        while(!p.empty()&&buy[p.top().second])
        {
            p.pop();
        }
        while(!c.empty()&&buy[c.top().second])
        {
            c.pop();
        }
        if(p.empty()||c.empty())//注意这里的边界检查
        {
            break;
        }
        if((long long)t.size()<k) 
        {
            if(p.top().first<=c.top().first)//原价价格低
            {
                sum+=p.top().first;
                buy[p.top().second]=1;
                p.pop();
            }
            else
            {
                sum+=c.top().first;
                buy[c.top().second]=1;
                node tmp;
                tmp.i=c.top().second;
                tmp.save=cows[c.top().second].p-cows[c.top().second].c;
                t.push(tmp);
                c.pop();
            }
        }
        else
        {
            //券已经用完了，现在可以原价买，或者抢券买。
            if(p.top().first<=t.top().save+c.top().first)
            //原价买更便宜
            {
                sum+=p.top().first;
                buy[p.top().second]=1;
                p.pop();
            }
            else
            {
                sum+=t.top().save+c.top().first;
                t.pop();
                node tmp;
                tmp.i=c.top().second;
                tmp.save=cows[c.top().second].p-cows[c.top().second].c;
                buy[tmp.i]=1;
                t.push(tmp);
                c.pop();
                /*
                // 或者使用这一段代码：
                （不同点：是将整个使用优惠券折扣对应的牛弹出，在考虑要不要用原价买这头牛。）
                为什么重新买回的一定是这一头被弹出的牛，即不需要记录下是哪一头牛使用了优惠券？
                我们已知ci<cj，savei<savej。
                且pj>savei+cj>savei+ci=pi，得证。
                sum+=cows[c.top().second].c+min(p.top().first,cows[t.top().i].p)-cows[t.top().i].c;
                p.push(make_pair(cows[t.top().i].p,c.top().second));
                pair<int,int> tmp1=make_pair(cows[t.top().i].c,c.top().second);
                buy[t.top().i]=0;
                t.pop();
                buy[p.top().second]=1;
                p.pop();
                buy[c.top().second]=1;
                node tmp;
                tmp.i=c.top().second;
                tmp.save=cows[c.top().second].p-cows[c.top().second].c;
                t.push(tmp);
                c.pop();
                c.push(tmp1);
                */
            }
        }
        if(sum<=m)
        {
            cnt++;
        }
        else 
        {
            break;
        }
    }
    cout<<cnt<<endl;
}
