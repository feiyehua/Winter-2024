/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-03-16 19:39:38
 * @LastEditTime : 2025-03-16 19:41:48
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : 5297.cpp
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
const int maxN=110;
int y[maxN];
int x[maxN];
int dx,dy;
int tx,ty;
int main()
{
    fr(n);
    fr(m);
    for(int i=1;i<=n;i++)//操作
    {
        fr(tx);
        fr(ty);
        dx+=tx;
        dy+=ty;
    }
    for(int i=1;i<=m;i++)
    {
        fr(x[i]);
        fr(y[i]);
        printf("%d %d\n",x[i]+dx,y[i]+dy);
    }
    
}