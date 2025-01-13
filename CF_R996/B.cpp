/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-01-12 23:21:07
 * @LastEditTime : 2025-01-12 23:36:39
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : B.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=2e5+10;
int t;
int n,a[maxN],b[maxN];
int c[maxN];
// 对于每一个数，只要自己增加1，那么对于所有其他的代价就是-1.
// 如果只有一个不满足要求，判断其他的是否能支撑增长就可以了
// 如果有两个不满足，那么显然“按下去葫芦起来瓢”，一个加上去了，另一个就会减下去。
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        int minOver=INT_MAX;//最少多余
        int req=0;//需要的
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];//拥有的
        }
        for(int j=1;j<=n;j++)
        {
            cin>>b[j];//需要的
            c[j]=a[j]-b[j];
            if(c[j]<0&&req==0)
            {
                req=-c[j];
            }
            else if(c[j]<0&&req!=0)
            {
                req=INT_MAX;
            }
            else 
            {
                minOver=min(minOver,c[j]);
            }
        }
        if(minOver>=req&&minOver!=INT_MAX)
        {
            cout<<"yes\n";
        }
        else 
        {
            cout<<"no\n";
        }
    }
}