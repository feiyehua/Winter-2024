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

int n, k;
const int maxN = 1e5 + 10;
struct node
{
    int u;
    int v;
    int w;
    bool operator<(const node &t) const
    {
        return w < t.w;
    }
    bool operator>(const node &t) const
    {
        return w > t.w;
    }
} r[maxN];
int father[maxN];
bool isEnemy[maxN];
int tmp;
long long ans;
int getFather(int x)
{
    if (father[x] != x)
    {
        father[x] = getFather(father[x]);
    }
    return father[x];
}
void bind(int x, int y, bool a)
{
    if (getFather(x) != getFather(y))
    {
        father[getFather(x)] = getFather(y);
        isEnemy[getFather(y)] = a;//标记这一坨是敌人还是友军
        isEnemy[getFather(x)] = a;
    }
}
int main()
{
    fr(n);
    fr(k);
    for (int i = 1; i <= k; i++)
    {
        fr(tmp);
        isEnemy[tmp] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        father[i] = i;
    }
    for (int i = 1; i < n; i++)
    {
        fr(r[i].u);
        fr(r[i].v);
        fr(r[i].w);
        ans += r[i].w;
        //正难则反，先摧毁所有的路，再建摧毁代价高的路，尽量使敌人之间不连通。
    }
    sort(r + 1, r + n, greater<node>());
    for (int i = 1; i < n; i++)
    {
        if (isEnemy[getFather(r[i].u)] && isEnemy[getFather(r[i].v)])//如果两坨都是敌人，就不能连在一起
        {
            continue;
        }
        else//反之，就连在一起
        {
            ans -= r[i].w;
            bind(r[i].u, r[i].v, isEnemy[getFather(r[i].u)] || isEnemy[getFather(r[i].v)]);
            //不是敌人的人和敌人连在一起会被传染敌人属性
            // if (isEnemy[r[i].u] || isEnemy[r[i].v])
            // {
            //     isEnemy[r[i].u] = 1;
            //     isEnemy[r[i].v] = 1;
            // }
        }
    }
    cout << ans << endl;
}