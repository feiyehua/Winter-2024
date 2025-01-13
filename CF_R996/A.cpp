/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-01-12 23:00:01
 * @LastEditTime : 2025-01-12 23:17:05
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : A.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t;
int n,a,b;
// 对于每只青蛙，每次向对方移动，一定是最优的。
// 相遇时，如果a先动，a输；b先动，b输
// 在前期移动时，无论如何移动，都不改变相遇时的先后手关系
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>a>>b;
        if(abs(b-a)%2==1)
        {
            cout<<"no\n";
        }
        else 
        {
            cout<<"yes\n";
        }
    }
}