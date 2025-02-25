/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-25 11:08:58
 * @LastEditTime : 2025-02-25 11:29:38
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P2949.cpp
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
    int d,p;
    bool operator<(const node& t)const{
        return d<t.d;
    }
    bool operator>(const node& t)const{
        return d>t.d;
    }
};
priority_queue<node,vector<node>,greater<node>> works;
node tmp;
priority_queue<int,vector<int>,greater<int> > t;//存储所有当前完成的工作
int cnt;
int ans;
signed main()
{
    fr(n);
    for(int i=1;i<=n;i++)
    {
        fr(tmp.d);
        fr(tmp.p);
        works.push(tmp);
    }
    while(!works.empty()&&cnt<=1e9)
    {
        // cnt++;
        if(cnt+1<=works.top().d)//当前的完成时间小于等于截止时间
        {
            cnt++;
            t.push(works.top().p);
            works.pop();
        }
        else
        {
            if(!t.empty()&&t.top()<works.top().p)
            {
                t.pop();
                t.push(works.top().p);
            }
            works.pop();
        }
    }
    while(!t.empty())
    {
        ans+=t.top();
        t.pop();
    }
    cout<<ans<<endl;
}