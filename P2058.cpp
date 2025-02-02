/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-01-31 12:40:49
 * @LastEditTime : 2025-02-02 11:30:41
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : P2058.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
int n;
int k;
int tmp;
const int maxN=1e5+10;
struct node{
    int t;
    vector<int> x;
}ships[maxN];
queue<pair<int,int>> tours;
int passengerCount[maxN];
int cnt;
template <typename T>
void fr(T &num)
{
    char ch;
    T sign = 1;
    ch = getchar_unlocked();
    num = 0;
    while (ch > '9' || ch < '0')
    {
        if (ch == '-')
            sign = -1;
        ch = getchar_unlocked();
    }
    while (isdigit(ch))
    {
        num = num * 10 + ch - '0';
        ch = getchar_unlocked();
    }
    (num) *= sign;
    return;
}
int main()
{
    fr(n);
    for(int i=1;i<=n;i++)
    {
        fr(ships[i].t);
        while(!tours.empty()&&tours.front().first<=ships[i].t-86400)
        {
            passengerCount[tours.front().second]--;
            if(passengerCount[tours.front().second]==0)
            {
                cnt--;
            }
            tours.pop();
        }
        fr(k);
        for(int j=1;j<=k;j++)
        {
            fr(tmp);
            if(passengerCount[tmp]==0)
            {
                cnt++;
            }
            // ships[i].x.push_back(tmp);
            tours.push(make_pair(ships[i].t,tmp));
            passengerCount[tmp]++;
        }
        cout<<cnt<<endl;
    }
}