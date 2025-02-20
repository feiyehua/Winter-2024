/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-20 11:39:51
 * @LastEditTime : 2025-02-20 11:49:14
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1113.cpp
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
int n;
const int maxN=1e4+10;
struct node{
    int t;
    int len;
    vector<int> p;
    int in;
    bool vis;
}w[maxN];
int tmp;
int ans;
void tuopu(int x)
{
    w[x].vis=1;
    for(auto it:w[x].p)
    {
        w[it].t=max(w[it].t,w[x].t+w[it].len);
        w[it].in--;
        if(w[it].in==0)
        {
            tuopu(it);
        }
    }
}
int main()
{
    fr(n);
    for(int i=1;i<=n;i++)
    {
        fr(tmp);
        fr(w[i].len);
        w[i].t=w[i].len;
        fr(tmp);
        while(tmp!=0)
        {
            w[i].in++;
            w[tmp].p.push_back(i);
            fr(tmp);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(w[i].in==0&&!w[i].vis)
        {
            tuopu(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        ans=max(ans,w[i].t);
    }
    cout<<ans<<endl;
}