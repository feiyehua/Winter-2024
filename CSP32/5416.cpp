/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-03-11 16:12:40
 * @LastEditTime : 2025-03-11 16:46:34
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P5416.cpp
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
typedef long long ll;
ll n;
int kk,q;
const int maxN=1.1e5+10;
bool isPrime[maxN];//0 是质数
//1 不是质数
int prime[maxN];
int cnt;
void getPrime()
{
    // prime[1]=2;
    isPrime[1]=1;
    for(int i=2;i<=1e5+10;i++)
    {
        if(isPrime[i]==0)
        {
            cnt++;
            prime[cnt]=i;
        }
        // else 
        {
            for(int j=1;j<=cnt;j++)
            {
                if(prime[j]*i>=1e5+10)
                {
                    break;
                }
                isPrime[prime[j]*i]=1;
                if(i%prime[j]==0)   
                {
                    break;
                }
            }
        }
    }
}
int main()
{
    fr(q);
    getPrime();
    for(int i=1;i<=q;i++)
    {
        fr(n);
        fr(kk);
        ll orin=n;
        for(int j=1;j<=cnt&&n>=prime[j];j++)
        {
            int t=0;
            while(n%prime[j]==0)
            {
                n/=prime[j];
                t++;
            }
            if(t<kk)
            {
                for(int k=1;k<=t;k++)
                {
                    n*=prime[j];
                }
            }
        }
        n=orin/n;
        printf("%lld\n",n);
    }
    
}