/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-28 12:16:20
 * @LastEditTime : 2025-03-28 12:26:37
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : 5299.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
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
typedef long long ll;
const ll mod = 1e9 + 7;
// 如何解决乘法问题？
// 考虑维护一个结构体，维护每一个求值单元里每一个未知数的系数
// 乘法就是求值单元之间乘法
//  但是这样需要考虑多个未知数相乘，不太方便。
//  由于是求偏导数，考虑一边带值一边展开：未知数参与乘法，更改次数；已知数直接带入值
//  最后转化成了关于未知数的两个未知多项式相乘的问题
//  总共元素不超过120个，所以未知数的最高次数就是120，可以直接用数组存下来。

struct node
{
    ll co[300]; // 下标对应次数（从0开始），数组内的值代表前面的次数
    // 注意取模
    node operator*(const node &b) const
    {
        node c = {.co = {0}};
        for (int i = 0; i <= 120; i++)
        {
            for (int j = 0; j <= 120; j++)
            {
                c.co[i + j] += co[i] * b.co[j];
                c.co[i + j] %= mod;
            }
        }
        return c;
    }
    node operator+(const node &b) const
    {
        node c = {.co = {0}};
        for (int i = 0; i <= 120; i++)
        {
            c.co[i] += (co[i] + b.co[i]);
            c.co[i] %= mod;
        }
        return c;
    }
    node operator-(const node &b) const
    {
        node c = {.co = {0}};
        for (int i = 0; i <= 120; i++)
        {
            c.co[i] += (-co[i] + b.co[i]);
            c.co[i] %= mod;
        }
        return c;
    }
} el[300];
int n, m;
string s;
ll a[300];
int j;
ll getAns(node &f) // 对j求偏导，aj
{
    f.co[0] = {0};
    for (int i = 1; i <= 120; i++)
    {
        f.co[i - 1] = f.co[i] * i;
        f.co[i - 1] %= mod;
        f.co[i] = 0;
    }
    ll ans = 0;
    ll tmp = 1; // 0次

    for (int i = 0; i <= 120; i++)
    {
        ans += tmp * f.co[i];
        ans %= mod;
        tmp *= a[j];
        tmp %= mod;
    }
    if (ans < 0)
    {
        ans += mod;
    }
    return ans;
}
void solve() // 求关于xj的偏导，且所有系数在a数组中给出
{
    stack<node> els;
    for (int i = 0; i < s.size(); i++)
    {
        node newNode = {.co = {0}};
        if (isdigit(s[i])||(s[i]=='-'&&isdigit(s[i+1])))
        {
            newNode.co[0] = stoll(s.substr(i));
            if(s[i]=='-')
            {
                i++;
            }
            els.push(newNode);
            while (isdigit(s[i]) && i < s.size())
            {
                i++;
            }
        }
        else if (s[i] == 'x')
        {
            i++;
            int num = stoll(s.substr(i));
            if (num != j)
            {
                newNode.co[0] = a[num] % mod;
            }
            else
            {
                newNode.co[1] = 1;
            }
            els.push(newNode);
            while (isdigit(s[i]) && i < s.size())
            {
                i++;
            }
        }
        else if (s[i] == ' ')
        {
            continue;
        }
        else if (s[i] == '-')
        {
            node a = els.top();
            els.pop();
            node b = els.top();
            els.pop();
            node c = a - b;
            els.push(c);
        }
        else if (s[i] == '+')
        {
            node a = els.top();
            els.pop();
            node b = els.top();
            els.pop();
            node c = a + b;
            els.push(c);
        }
        else if (s[i] == '*')
        {
            node a = els.top();
            els.pop();
            node b = els.top();
            els.pop();
            node c = a * b;
            els.push(c);
        }
    }
    assert(els.size() == 1);
    node fi = els.top();
    ll ans = getAns(fi);
    printf("%lld\n", ans);
}
int main()
{
    fr(n);
    fr(m);
    // cin >> s;
    getline(cin,s);
    for (int i = 1; i <= m; i++)
    {
        cin >> j;
        for (int j = 1; j <= n; j++)
        {
            fr(a[j]);
        }
        solve();
    }
}