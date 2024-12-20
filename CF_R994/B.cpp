/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-20 22:27:27
 * @LastEditTime : 2024-12-20 23:06:26
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : B.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int t;
int n;
string s;
bool flagS;
bool flagP;
bool flagCan;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n;
        cin>>s;
        flagS=1;
        flagP=1;
        flagCan=1;
        if(s[0]=='s') s[0]='.';
        if(s[s.size()-1]=='p') s[s.size()-1]='.';
        for(int j=0;j<s.size();j++)
        {
            if(flagP==0&&flagS==0&&s[j]=='s')
            {
                flagCan=0;
            }
            if(s[j]=='s')
            {
                flagS=0;
            }
            else if(s[j]=='p')
            {
                flagP=0;
            }
        }
        //如果只有sp中一种字符，显然是可以的
        if((!(flagS==0&&flagP==0)))
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"no\n";
        }
    }
}