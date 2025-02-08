/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-08 16:45:08
 * @LastEditTime : 2025-02-08 17:49:35
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1656.cpp
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

int n,m;
const int maxN=160;
map<pair<int,int>,int> ans;
vector<vector<int>> rail(maxN,vector<int>(0));
int a,b;
int cnt;//dfs序
struct node{
    int num;//dfs序
    int low;

}nodes[maxN];
void tarjan(int x,int fa)
{
    cnt++;
    nodes[x].num=cnt;
    nodes[x].low=cnt;
    for(auto it:rail[x])
    {
        if(it==fa)
        {
            continue;
        }
        if(nodes[it].num==0)
        {
            tarjan(it,x);
            nodes[x].low=min(nodes[x].low,nodes[it].low);
        }
        else
        {
            nodes[x].low=min(nodes[x].low,nodes[it].num);
        }
        if(nodes[it].low>nodes[x].num)
        {
            int c=it;
            int d=x;
            if(c>d)
            {
                swap(c,d);
            }
            ans[make_pair(c,d)]++;
        }
    }
}
int main()
{
    fr(n);
    fr(m);
    for(int i=1;i<=m;i++)
    {
        fr(a);
        fr(b);
        rail[a].push_back(b);
        rail[b].push_back(a);
    }
    tarjan(1,0);
    for(auto i:ans)
    {
        cout<<i.first.first<<" "<<i.first.second<<endl;
    }
}