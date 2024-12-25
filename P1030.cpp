/*** 
 * @Author       : FeiYehua
 * @Date         : 2024-12-25 10:24:31
 * @LastEditTime : 2024-12-25 11:18:28
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P1030.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
string ldr,lrd;
string getdlr(const string& ldr,const string& lrd)
{
    assert(ldr.size()==lrd.size());
    // if(ldr.size()==3)
    // {
    //     return lrd.back()+lrd.substr(0,2);
    // }
    if(ldr.size()<=1)
    {
        return ldr;
    }
    else
    {
        char d=lrd.back();
        auto it=find(ldr.begin(),ldr.end(),d);
        string lldr(ldr.begin(),it);
        string llrd(lrd.begin(),lrd.begin()+lldr.size());
        string rldr(it+1,ldr.end());
        string rlrd(lrd.begin()+lldr.size(),lrd.end()-1);
        return d+getdlr(lldr,llrd)+getdlr(rldr,rlrd);
    }
}
int main()
{
    cin>>ldr>>lrd;
    cout<<getdlr(ldr,lrd);
}