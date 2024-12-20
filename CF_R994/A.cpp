/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-20 22:27:24
 * @LastEditTime : 2024-12-20 22:48:02
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : A.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t;
int a[200];
int n;
bool flag0;
//最多操作两次：两次均选全部。
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        flag0=1;
        cin>>n;
        for(int j=1;j<=n;j++)
        {
            cin>>a[j];
            if(a[j]!=0)
            {
                flag0=0;
            }
        }
        if(flag0)
        {
            cout<<"0\n";
        }
        else
        {
            //一次解决，当且仅当前面全是0｜｜后面全是0，且中间没有0
            bool flag1=1;
            int l=1;
            int r=n;
            while(a[l]==0)
            {
                l++;
            }
            while(a[r]==0)
            {
                r--;
            }
            for(int k=l;k<=r;k++)
            {
                if(a[k]==0)
                {
                    flag1=0;
                    break;
                }
            }
            if(flag1)
            {
                cout<<"1\n";
            }
            else
            {
                cout<<"2\n";
            }
        }
    }
}