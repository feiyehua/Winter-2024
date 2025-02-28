/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-28 21:53:22
 * @LastEditTime : 2025-02-28 22:07:51
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P4933.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int ans;
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
const int maxN=1e3+10;
const int maxV=2e4+10;
int h[maxN];
int s[maxN][maxN];
int dp[maxN][maxV*2];//表示到i结束，以j为公差的取法有多少种
int main()
{
    fr(n);
    for(int i=1;i<=n;i++)
    {
        fr(h[i]);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            s[j][i]=h[j]-h[i]+2e4;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<i;j++)
        {
            dp[i][s[i][j]]+=dp[j][s[i][j]]+1;
            dp[i][s[i][j]]%=mod;
        }
        dp[i][0]+=1;
        dp[i][0]%=mod;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=4e4;j++)
        {
            ans+=dp[i][j];
            ans%=mod;
        }
    }
    cout<<ans<<endl;
}