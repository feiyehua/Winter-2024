/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-25 11:36:02
 * @LastEditTime : 2025-02-25 11:43:24
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P4053.cpp
 * @     © 2024 FeiYehua
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

int n;
struct node{
    int t1,t2;
    bool operator<(const node& t)const 
    {
        return t2<t.t2;
    }
    bool operator>(const node& t)const 
    {
        return t2>t.t2;
    }
    
}tmp;
priority_queue<node,vector<node>,greater<node>>q;
int cnt;
int curTime;
priority_queue<int> t;//当前修理所需要的时间

signed main()
{
    fr(n);
    for(int i=1;i<=n;i++)
    {
        fr(tmp.t1);
        fr(tmp.t2);
        q.push(tmp);
    }
    while(!q.empty())
    {
        if(curTime+q.top().t1<=q.top().t2)
        {
            cnt++;
            curTime+=q.top().t1;
            t.push(q.top().t1);
            q.pop();
        }
        else
        {
            if(curTime+q.top().t1-t.top()<=q.top().t2&&q.top().t1-t.top()<0)
            {
                curTime+=q.top().t1-t.top();
                t.pop();
                t.push(q.top().t1);
            }
            q.pop();
        }

    }
    cout<<cnt<<endl;
}