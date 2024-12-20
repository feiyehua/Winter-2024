/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-19 22:34:33
 * @LastEditTime : 2024-12-19 23:43:23
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : C.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1e5+10;
int t;
int n,k;
string s;
//既然最前面是1，那么一定可以选出一个长度小于s的子串，实现异或后最高位为1，这样一定最优。
//只需要枚举接下来选出来的另一个子串就行了。
//同理，前面连续多少个1，选出来的长度必须小于等于s-t，t是连续的1个数
int getCon1(const string& s)
{
    int cnt=0;
    while(s[cnt]=='1'&&cnt<s.size())
    {
        cnt++;
    }
    return cnt;
}
struct binStr
{
    vector<char> a;//一个二进制串
    int highest;
    bool operator>(const binStr& b) const
    {
        if(highest!=b.highest)
        {
            return highest>b.highest;
        }
        else 
        {
            for(int i=highest-1;i>=0;i--)
            {
                if(a[i]!=b.a[i])
                {
                    return a[i]>b.a[i];
                }
            }
        }
        return 1;
    }
    // binStr operator=(const binStr&b)
    // {
    //     highest=b.highest;
    //     a.clear();
    //     a=b.a;
    // }
};
binStr getXor(const string& a,const string& b)
{
    // if(a.size()<b.size())
    // {
    //     swap(a,b);
    // }
    int i=a.size()-1;
    int j=b.size()-1;
    binStr k;
    k.highest=0;
    while(i>=0&&j>=0)
    {
        k.highest++;
        k.a.push_back((a[i]-'0')^(b[j]-'0'));
        i--;j--;
    }
    while(k.a[k.highest-1]==0)
    {
        k.highest--;
    }
    return k;
}
binStr maxStr;
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>s;
        cout<<"1 "<<s.size();
        int cnt=getCon1(s);
        if(cnt==s.size())
        {
            cout<<" 1 1\n";
            continue;
        }
        else
        {
            int l,r;
            maxStr.highest=0;
            maxStr.a.clear();
            for(int j=s.size()-cnt;j>=1;j--)
            {
                for(int k=0;k+j<=s.size();k++)
                {
                    binStr p=getXor(s,s.substr(k,j));
                    if (p > maxStr)
                    {
                        maxStr = p;
                        l=k+1,r=k+j;
                    }
                }
                if(maxStr.highest>0) break;
            }
            cout<<" "<<l<<" "<<r<<"\n";
        }
        // for(int i=s.size()-1;i>=)
        //cout<<
    }
    return 0;
}