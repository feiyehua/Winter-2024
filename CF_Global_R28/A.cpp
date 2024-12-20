/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-19 22:34:26
 * @LastEditTime : 2024-12-19 22:36:56
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : A.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t;

int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int n;
        cin>>n;
        if(n%33==0)
        {
            cout<<"Yes\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}