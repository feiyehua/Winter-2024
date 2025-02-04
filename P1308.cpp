/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-02-04 10:37:30
 * @LastEditTime : 2025-02-04 11:09:49
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1308.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
string a,pass;
map<string,int> b;
int num,loc=-1;
void upperToLower(string& a)
{
    for(auto &it:a)
    {
        if(it>='A'&&it<='Z')
        {
            it=it+'a'-'A';
        }
    }
}
void get()
{
    pass=" "+pass+" ";
    auto l=pass.find(' ');
    auto r=pass.find(' ',1);
    while(r!=string::npos)
    {
        string t=pass.substr(l+1,r-l-1);
        if(t==a)
        {
            if(loc==-1)
            {
                loc=l;
            }
            num++;
        }
        l=r;
        r=pass.find(' ',l+1);
    }
}
int main()
{
    cin>>a;
    upperToLower(a);
    getchar();
    getline(cin,pass);
    upperToLower(pass);
    get();
    if(num!=0)
    cout<<num<<" "<<loc<<endl;
    else
    {
        cout<<"-1";
    }
}