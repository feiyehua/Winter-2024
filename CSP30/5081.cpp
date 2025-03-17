/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-03-17 20:46:48
 * @LastEditTime : 2025-03-17 20:50:07
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : 5081.cpp
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
int n;
string s,tmp;
map<string,int> cnt;

int main()
{
    fr(n);
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        for(int j=1;j<=7;j++)
        {
            cin>>tmp;
            s+=tmp;
        }
        if(cnt.find(s)==cnt.end())
        {
            cnt.insert(make_pair(s,1));
            cout<<1<<endl;
        }
        else
        {
            cnt[s]++;
            cout<<cnt[s]<<endl;
        }
    }
}