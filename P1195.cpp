/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-09 14:41:24
 * @LastEditTime : 2025-02-09 14:47:51
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1195.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
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

int n,m,k;
struct node{
    int u,v,w;
    bool operator<(const node& t)const 
    {
        return w<t.w;
    }
    bool operator>(const node& t)const 
    {
        return w>t.w;
    }
};
node tmp;
int cnt;
int ans;
priority_queue<node,vector<node>,greater<node>> sides;
const int maxN=1e3+10;
int fa[maxN];
int getFather(int x)
{
    if(fa[x]!=x)
    {
        fa[x]=getFather(fa[x]);
    }
    return fa[x];
}
void bind(int x,int y)
{
    if(getFather(x)!=getFather(y))
    {
        fa[fa[x]]=fa[y];
    }
}
int main()
{
    fr(n);
    fr(m);
    fr(k);
    for(int i=1;i<=n;i++)
    {
        fa[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        fr(tmp.u);
        fr(tmp.v);
        fr(tmp.w);
        sides.push(tmp);
    }
    while(!sides.empty()&&cnt<n-k)
    {
        tmp=sides.top();
        if(getFather(tmp.u)!=getFather(tmp.v))
        {
            bind(tmp.u,tmp.v);
            ans+=tmp.w;
            cnt++;
        }
        sides.pop();
    }
    if(cnt<n-k)
    {
        cout<<"No Answer";
    }
    else cout<<ans;
}