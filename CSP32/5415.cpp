/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-03-11 16:00:57
 * @LastEditTime : 2025-03-11 16:07:06
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : 5415.cpp
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
const int maxM=20;
const int maxN=1e3+10;
struct node{
    int d[maxM];
    int fa;
    bool operator<(const node& t)const 
    {
        for(int i=1;i<=m;i++)
        {
            if(t.d[i]<=d[i])
            {
                return 0;
            }
        }
        return 1;
    }
}w[maxN];
void getFa()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j==i)
            {
                continue;
            }
            else if(w[i]<w[j])
            {
                w[i].fa=j;
                break;
            }
        }
    }
}
int main()
{
    fr(n);
    fr(m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            fr(w[i].d[j]);
        }
    }
    getFa();
    for(int i=1;i<=n;i++)
    {
        printf("%d\n",w[i].fa);
    }
}