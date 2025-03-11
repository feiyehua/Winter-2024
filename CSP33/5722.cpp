/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-11 10:36:39
 * @LastEditTime : 2025-03-11 10:40:36
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : 5722.cpp
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
const int maxM = 3e5 + 10;
int c, m, n, x, w, p;
pair<int, int> tmpW[maxM];
struct node
{
    int l;
    int r;
    int w;
    int x;
} node[maxM];
class List
{
private:
    int cnt = 0;

public:
    map<int, int> Map;
    void insert(int &x, int &w)
    {
        Map.insert(make_pair(x, ++cnt)); // 插入新元素，并维护其键值
        auto it = Map.upper_bound(x);
        if (Map.rbegin()->first != x)
        {
            node[cnt].r = it->second;
            node[it->second].l = cnt;
        }
        if (Map.begin()->first != x)
        {
            it--;
            it--;
            node[cnt].l = it->second;
            node[it->second].r = cnt;
        }

        node[cnt].w = w;
        node[cnt].x = x;
    }
    void erase(int x)
    {
        int p = Map[x];
        Map.erase(x);
        node[node[p].l].r = node[p].r;
        node[node[p].r].l = node[p].l;
    }
    void boom(int p)
    {
        node[p].w = 0;
        if (node[p].l != 0)
        {
            node[node[p].l].w++;
        }
        if (node[p].r != 0)
        {
            node[node[p].r].w++;
        }
        erase(node[p].x);
        if (node[p].l != 0 && node[node[p].l].w >= 5)
        {
            boom(node[p].l);
        }
        if (node[p].r != 0 && node[node[p].r].w >= 5)
        {
            boom(node[p].r);
        }
    }
    void add(int &p)
    {
        // auto it=Map.lower_bound(p);
        node[p].w++;
        if (node[p].w >= 5)
        {
            boom(p);
        }
    }

    List()
    {
        for (int i = 1; i <= m; i++)
        {
            fr(x);
            fr(w);
            insert(x, w);
        }
    }
};
int main()
{
    fr(c);
    fr(m);
    fr(n);
    List l;
    for (int i = 1; i <= n; i++)
    {
        fr(p);
        l.add(l.Map[p]);
        // cout << l.Map.size() << endl;
        printf("%ld\n",l.Map.size());
    }
}