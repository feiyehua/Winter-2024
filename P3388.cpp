/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-04 12:35:04
 * @LastEditTime : 2025-02-04 12:58:54
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P3388.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int maxN=2e4+10;
const int maxM=1e5+10;
int x,y;
vector<vector<int>> sides(maxN,vector<int>(0));
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
struct node
{
    int low;
    int dfn;
    int child;
    bool vis;
    bool cut;
}nodes[maxN];
int cnt;
int cutCnt;
void tarjan(int x,int root)
{
    cnt++;
    nodes[x].dfn=cnt,nodes[x].low=cnt;
    nodes[x].vis=1;
    for(auto it:sides[x])
    {
        if(!nodes[it].vis)
        {
            tarjan(it,root);
            nodes[x].low=min(nodes[x].low,nodes[it].low);
            nodes[x].child++;
            if(nodes[it].low>=nodes[x].dfn&&x!=root&&nodes[x].cut!=1)
            {
                nodes[x].cut=1;
                cutCnt++;
            }
            else if(x==root&&nodes[x].child>=2&&nodes[x].cut!=1)
            {
                nodes[x].cut=1;
                cutCnt++;
            }
        }
        else 
        {
            nodes[x].low=min(nodes[x].low,nodes[it].dfn);
        }

    }
}

int main()
{
    fr(n);
    fr(m);
    for(int i=1;i<=m;i++)
    {
        fr(x);
        fr(y);
        sides[x].push_back(y);
        sides[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(!nodes[i].vis)
        {
            tarjan(i,i);
        }
    }
    printf("%d\n",cutCnt);
    for(int i=1;i<=n;i++)
    {
        if(nodes[i].cut)
        {
            printf("%d ",i);
        }
    }
}