/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-03-16 19:44:25
 * @LastEditTime : 2025-03-16 23:34:53
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : 5298.cpp
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
double k,theta;
const int maxN=1e5+10;
double sumK[maxN],sumTheta[maxN];
int op;
int i,j,x,y;
double rx,ry;
int main()
{
    fr(n);
    fr(m);
    sumK[0]=1.0;
    for(int i=1;i<=n;i++)
    {
        fr(op);
        k=1.0;
        theta=0;
        if(op==1)
        {
            // fr(k);
            scanf("%lf",&k);
        }
        else
        {
            scanf("%lf",&theta);
            // fr(theta);
        }
        sumK[i]=sumK[i-1]*k;
        sumTheta[i]=sumTheta[i-1]+theta;
    }
    for(int ii=1;ii<=m;ii++)
    {
        fr(i);
        fr(j);
        fr(x);
        fr(y);
        theta=sumTheta[j]-sumTheta[i-1];
        k=sumK[j]/sumK[i-1];
        rx=x*cos(theta)-y*sin(theta);
        ry=x*sin(theta)+y*cos(theta);
        rx*=k;
        ry*=k;
        printf("%.3lf %.3lf\n",rx,ry);
    }
}