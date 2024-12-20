/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-19 22:34:30
 * @LastEditTime : 2024-12-19 22:43:59
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : B.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+10;
int t;
int n,k;
int ans[maxN];
int fornt,tail;//标记当前首尾元素
int cnt;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>k;
        fornt=n,tail=1,cnt=0;
        for(int j=1;j<=n;j++)
        {
            cnt++;
            if(cnt==k)
            {
                ans[j]=tail;
                tail++;
                cnt=0;
            }
            else
            {
                ans[j]=fornt;
                fornt--;
            }
        }
        for(int j=1;j<=n;j++)
        {
            cout<<ans[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}