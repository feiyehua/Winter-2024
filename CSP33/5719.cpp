/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-03-08 10:25:38
 * @LastEditTime : 2025-03-08 10:26:42
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : 5719.cpp
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
const int maxM=1000;
int mCount[maxM];
int mP[maxM];
int tmp;
int l;
bool e[maxM];
int main()
{
    fr(n);
    fr(m);
    for(int i=1;i<=n;i++)
    {
        fr(l);
        memset(e,0,sizeof e);
        for(int j=1;j<=l;j++)
        {
            fr(tmp);
            mCount[tmp]++;
            if(e[tmp]==0)   
            {
                e[tmp]=1;
                mP[tmp]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<mP[i]<<" "<<mCount[i]<<endl;
    }
}