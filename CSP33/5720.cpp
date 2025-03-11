/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-03-08 10:29:40
 * @LastEditTime : 2025-03-08 10:35:08
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : 5720.cpp
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

void upperToLower(string& s)    
{
    for(auto &it:s)
    {
        if(it>='A'&&it<='Z')
        {
            it=it-'A'+'a'   ;
        }
    }
}
int n,m;
string tmp;
set<string> passcup;
set<string> pass1;
set<string> pass2;
int cnt;
int main()
{
    fr(n);
    fr(m);
    for(int i=1;i<=n;i++)
    {
        cin>>tmp;
        upperToLower(tmp);
        pass1.insert(tmp);
        passcup.insert(tmp);
    }
    for(int i=1;i<=m;i++)
    {
        cin>>tmp;
        upperToLower(tmp);
        pass2.insert(tmp);
        passcup.insert(tmp);
    }
    for(auto it:pass1)
    {
        if(pass2.find(it)!=pass2.end())
        {
            cnt++;
        }
    }
    cout<<cnt<<endl;
    cout<<passcup.size()    ;
    return 0;
}