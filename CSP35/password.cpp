/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-03-03 19:32:46
 * @LastEditTime : 2025-03-03 19:38:13
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : password.cpp
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
string a;
int t[114514];
bool flagLetter;//包含字母、数字和特殊字符
bool flagNumbers;
bool flagMarks;
bool flag2;//同一个字符出现不超过 2 次

int main()
{
    fr(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        flagLetter=0;
        flagNumbers=0;
        flagMarks=0;
        flag2=1;
        memset(t,0,sizeof t);
        for(auto c:a)
        {
            t[c]++;
            if(t[c]>2)
            {
                flag2=0;
            }
            if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
            {
                flagLetter=1;
            }
            if(c>='0'&&c<='9')
            {
                flagNumbers=1;
            }
            if(c=='#'||c=='*')
            {
                flagMarks=1;
            }
        }
        if(flag2&&flagLetter&&flagMarks&&flagNumbers)
        {
            cout<<"2\n";
        }
        else if(flagLetter&&flagMarks&&flagNumbers)
        {
            cout<<"1\n";
        }
        else 
        {
            cout<<"0\n";
        }
    }
}