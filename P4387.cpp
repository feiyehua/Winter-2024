/***
 * @Author       : FeiYehua
 * @Date         : 2025-01-31 12:22:39
 * @LastEditTime : 2025-01-31 12:23:44
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P4387.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
int t;
int n;

const int maxN = 1e5 + 10;
int a[maxN];
int b[maxN];
int tmp;
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
    fr(t);
    for (int i = 1; i <= t; i++)
    {
        fr(n);
        stack<int> c;
        stack<int> d;
        for (int j = 1; j <= n; j++)
        {
            fr(a[j]);
        }
        for (int j = 1; j <= n; j++)
        {
            fr(b[j]);
        }
        for(int j=n;j>=1;j--)
        {
            d.push(b[j]);
        }
        for(int j=1;j<=n;j++)
        {
            c.push(a[j]);
            while(!c.empty()&&c.top()==d.top())
            {
                c.pop();
                d.pop();
            }
        }
        if(c.empty())
        {
            cout<<"Yes\n";
        }
        else 
        {
            cout<<"No\n";
        }
    }
}