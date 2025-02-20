/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-20 20:28:45
 * @LastEditTime : 2025-02-20 21:08:15
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P4568.cpp
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
int s,t;
int a,b,c;
const int maxN = 1e4+10;
const int maxM = 5e4+10;
struct node1{
    int v;
    int next;
    int w;
}sides[maxM*2];
int head[maxN];
int cnt;
//加边
void add(int u,int v,int w)
{
    cnt++;
    sides[cnt].v=v;
    sides[cnt].next=head[u];
    head[u]=cnt;
    sides[cnt].w=w;
}
struct node{
    int city;
    int layer;
    int dis;
    bool operator<(const node& t)const {
        return dis<t.dis;
    }
    bool operator>(const node& t)const {
        return dis>t.dis;
    }
};
int dis[maxN][12];
priority_queue<node,vector<node>,greater<node>> q;
void diji()
{
    memset(dis,0x3f,sizeof dis);
    dis[s][0]=0;
    node tmp={s,0,0};
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.top();
        int from=tmp.city;
        int layer=tmp.layer;
        // assert(layer<=10);
        int side=head[tmp.city];
        q.pop();
        while(side!=0)
        {
            if(dis[sides[side].v][layer]>dis[from][layer]+sides[side].w)
            {
                dis[sides[side].v][layer]=dis[from][layer]+sides[side].w;
                q.push({sides[side].v,layer,dis[sides[side].v][layer]});
            }
            if(layer+1<=k&&dis[sides[side].v][layer+1]>dis[from][layer])
            {
                dis[sides[side].v][layer+1]=dis[from][layer];
                q.push({sides[side].v,layer+1,dis[sides[side].v][layer+1]});
            }
            side=sides[side].next;
        }
        while(!q.empty())
        {
            tmp=q.top();
            if(tmp.dis>dis[tmp.city][tmp.layer])
            {
                q.pop();
            }
            else 
            {
                break;
            }
        }
    }
}
int main()
{
    fr(n);
    fr(m);
    fr(k);
    fr(s);
    fr(t);
    for(int i=1;i<=m;i++)
    {
        fr(a);
        fr(b);
        fr(c);
        add(a,b,c);
        add(b,a,c);
    }
    add(t,t,0);//防止免费次数过多导致免费次数用不完
    diji();
    cout<<dis[t][k];
}