/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-03-03 23:11:28
 * @LastEditTime : 2025-03-03 23:39:26
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : communicate.cpp
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
//建图跑最短路
const int maxN=5e3+10;
int n,m;
pair<int,int> nodes[maxN];
bool r[maxN][maxN];
int g[maxN][maxN];
int dis[maxN];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
struct node{
    int x,y;
    int r,t;
}sta[maxN];
long long getDis(int a,int b,int c,int d)
{
    return (long long)(a-c)*(long long)(a-c)+(long long)(b-d)*(long long)(b-d);
}
int main()
{
    fr(n);
    fr(m);
    memset(g,0x3f,sizeof g);
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=n;i++)
    {
        fr(nodes[i].first);
        fr(nodes[i].second);
    }
    for(int i=1;i<=m;i++)
    {
        fr(sta[i].x);
        fr(sta[i].y);
        fr(sta[i].r);
        fr(sta[i].t);
    }
    for(int i=1;i<=m;i++)//预处理距离+建图
    {
        vector<int> reachablePts;
        for(int j=1;j<=m;j++)
        {
            if(getDis(sta[i].x,sta[i].y,nodes[j].first,nodes[j].second)<=(long long)sta[i].r*(long long)sta[i].r)
            {
                reachablePts.push_back(j);
            }
        }
        for(auto it1:reachablePts)
        {
            for(auto it2:reachablePts)
            {
                if(it1!=it2)
                {
                    g[it1][it2]=min(sta[i].t,g[it1][it2]);
                }
            }
        }
    }
    //Dijkstra
    dis[1]=0;
    q.push(make_pair(0,1));
    while(!q.empty())
    {   
        pair<int,int> tmp=q.top();
        if(tmp.first>dis[tmp.second])  
        {
            continue;
        }
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(dis[i]>dis[tmp.second]+g[tmp.second][i]&&g[tmp.second][i]<=1e6)
            {
                dis[i]=dis[tmp.second]+g[tmp.second][i];
                q.push(make_pair(dis[i],i));
            }
        }
    }
    if(dis[n]<1e9)cout<<dis[n]<<endl;
    else cout<<"Nan\n";
}