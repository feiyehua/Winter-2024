/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-16 23:44:22
 * @LastEditTime : 2025-03-17 09:20:27
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : 5417.cpp
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
template <typename T>
void fp(T x)
{
    if (x < 10)
    {
        putchar_unlocked(x + '0');
    }
    else
    {
        fp(x / 10);
        putchar_unlocked(x % 10 + '0');
    }
}
/*
题意：给定一棵树，树节点和其后继节点的权值和和其他所有节点的权值和可以得到一个差值（绝对值）delta
每次取出delta最小的节点（delta相等时取出编号最小的点），判断所给节点是否为该取出节点或其后继
如果是的，则仅保留节点及其后代；
如果不是，则去除节点及其所有后代
如此，直到只剩下一个类别，即可确定所属类别
*/

const int maxN = 2e3 + 10;
/*
对于每个节点，维护其后继
每次询问时，维护一个已经被排除的节点列表
对堆顶元素，判断是否被排除；被排除了就继续
维护堆内可用元素数量，只剩下1的时候退出
空间复杂度为n^2,时间复杂度为m*n*log(n)
*/
typedef long long ll;
struct node
{
    int fa;
    vector<int> child;
    int cnt;
    // set<int> decendants;
    bool can;
    // int child[maxN];
    ll w;
    ll oriw;
} nodes[maxN];
struct dm
{
    ll deltam;
    int num;
    bool operator<(const dm &t) const
    {
        if (deltam != t.deltam)
        {
            return deltam < t.deltam;
        }
        return num < t.num;
    }
    bool operator>(const dm &t) const
    {
        if (deltam != t.deltam)
        {
            return deltam > t.deltam;
        }
        return num > t.num;
    }
} leaf[maxN], minLeaf;
int n;
int m;
ll sumW;
int q;
int cnt;
ll dfs(int x)
{
    nodes[x].w = nodes[x].oriw;
    for (auto i : nodes[x].child)
    {
        // if (nodes[i].can == 0) // 移除时，会将整棵树丛树根移除，其他的不用管。只需要判断树根是否被移除即可
        {
            nodes[x].w += dfs(i);
        }
    }
    return nodes[x].w;
}
void getMinDeltaW(int x) // 从根节点x开始搜索
{
    cnt++;
    leaf[x].deltam = abs(sumW - 2 * nodes[x].w);
    // leaf[x].num = x;
    minLeaf = min(minLeaf, leaf[x]);
    for (auto i : nodes[x].child)
    {
        if (nodes[i].can == 0) // 移除时，会将整棵树丛树根移除，其他的不用管。只需要判断树根是否被移除即可
        {
            getMinDeltaW(i);
        }
    }
}
bool path[maxN];
int currentRoot;
int main()
{
    // freopen("1.in","r",stdin);
    // freopen("1.out","w",stdout);
    // auto start = chrono::high_resolution_clock::now();
    fr(n);
    fr(m);
    for (int i = 1; i <= n; i++)
    {
        leaf[i].num = i;
    }
    for (int i = 1; i <= n; i++)
    {
        fr(nodes[i].oriw);
    }
    for (int i = 2; i <= n; i++)
    {
        fr(nodes[i].fa);
        nodes[nodes[i].fa].child.push_back(i);
    }
    for (int i = 1; i <= m; i++)
    {
        fr(q);
        for (int j = 1; j <= n; j++)
        {
            nodes[j].can = 0;
        }
        int cur = q;
        memset(path, 0, sizeof path);
        while (cur != 1)
        {
            path[cur] = 1;
            cur = nodes[cur].fa;
        }
        path[1] = 1;
        currentRoot = 1;
        dfs(1);
        while (1)
        {
            cnt = 0;
            sumW = nodes[currentRoot].w;
            minLeaf.deltam = 1e11 + 10;
            getMinDeltaW(currentRoot);
            if (cnt <= 1)
            {
                break;
            }
            // printf("%d ", minLeaf.num);
            fp(minLeaf.num);
            putchar_unlocked(' ');
            if (path[minLeaf.num] == 1)
            {
                currentRoot = minLeaf.num;
            }
            else
            {
                nodes[minLeaf.num].can = 1;
                cur = minLeaf.num;
                while (cur != currentRoot)
                {
                    nodes[nodes[cur].fa].w -= nodes[minLeaf.num].w;
                    cur = nodes[cur].fa;
                }
            }
        }
        putchar_unlocked('\n');
        // printf("\n");
    }
    // auto end = chrono::high_resolution_clock::now();
    // std::chrono::duration<double, std::milli> ms = end - start;
    // std::cout << "Time taken: " << ms.count() << " milliseconds" << std::endl;
}
