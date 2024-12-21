/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-20 22:27:30
 * @LastEditTime : 2024-12-21 11:48:03
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : C.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t;
const int maxN=2e5+10;
int n,x,y;
int a[maxN];
int getNext(int x)
{
    if(x+1>n)
    {
        return (x+1)%n;
    }
    return x+1;
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>x>>y;
        int ox=x;
        for(int j=0;j<n;j++)
        {
            a[x]=j%2;
            x=getNext(x);
        }
        if(abs(x-y)%2==0||n%2==1)
        {
            a[ox]=2;
        }
        for(int j=1;j<=n;j++)
        {
            cout<<a[j]<<" ";
        }
        cout<<"\n";
    }
}