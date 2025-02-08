/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-09 00:22:18
 * @LastEditTime : 2025-02-09 00:53:54
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1194.cpp
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
int a,b;
struct node{
    int u,v,w;
    bool operator<(const node&t)const{
        return w<t.w;
    }
    bool operator>(const node&t)const{
        return w>t.w;
    }
};
node t;
priority_queue<node,vector<node>,greater<node>> sides;
int cnt;
const int maxB=550;
int fa[maxB];
int ans;
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
    fr(a);
    fr(b);
    for(int i=1;i<=b;i++)
    {   
        fa[i]=i;
    }
    for(int i=1;i<=b;i++)
    {
        for(int j=1;j<=b;j++)
        {

            fr(t.w);
            if(t.w==0)
            {
                t.w=a;
            }
            if(j>i)
            {
                continue;
            }
            t.w=min(0,t.w-a);
            t.u=i;
            t.v=j;
            sides.push(t);
        }
    }
    ans=b*a;
    while(!sides.empty()&&cnt<b-1)
    {
        t=sides.top();
        if(getFather(t.u)!=getFather(t.v))
        {
            ans+=t.w;
            cnt++;
            bind(t.u,t.v);
        }
        sides.pop();
    }
    cout<<ans<<endl;
}