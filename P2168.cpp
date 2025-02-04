/***
 * @Author       : FeiYehua
 * @Date         : 2025-02-02 11:37:17
 * @LastEditTime : 2025-02-02 11:39:33
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : P2168.cpp
 * @     © 2024 FeiYehua
 */
/*
此题是k叉哈夫曼树。
在k=2时，其实就是合并果子。（每次找两个最小的合并，最后编一下号就可以了）
在k>2时，要注意向其中补充权值为0的点（注意当节点个数正好能保证树的每个节点度数为k的情况的处理）
由于哈夫曼树算法没有要求取出树的顺序，所以哈夫曼树算法给出的结果只保证了编码总长度相等，而不保证最长编码的长度相等。
想要使最长编码的长度最短，需要在每次取出时都取出一棵深度最小的树（先取出来的树，会在最终得到的树的较下层）
*/
#include <bits/stdc++.h>
#define int long long
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
int n;
int k;
const int maxN = 1e5 + 10;
struct node // 树节点结构体，存储了子节点
{
    int weight;
    int chi[15];
    // int pa;

} nodes[3 * maxN];
struct node1
{
    int weight;
    int num;
    int depth;
    bool operator<(const node1 &b) const
    {
        if (weight != b.weight)
            return weight < b.weight;
        return depth < b.depth;
    }
    bool operator>(const node1 &b) const
    {
        if (weight != b.weight)
            return weight > b.weight;
        return depth > b.depth;
    }
};
node1 tmp;
priority_queue<node1, vector<node1>, greater<node1>> t;
int total;
int cnt;
int totalLength;
int maxLength;
void dfs(int x, int l) // x是当前访问的下标，cnt是编码长度
{
    if (x <= total) // 是一个叶子节点
    {
        if (x <= n)
        {
            maxLength = max(maxLength, l);
        }
        totalLength += nodes[x].weight * l;
        return;
    }
    for (int i = 1; i <= k; i++)
    {
        dfs(nodes[x].chi[i], l + 1);
    }
}
signed main()
{
    fr(n);
    fr(k);
    // memset(nodes,0xff,sizeof(nodes));
    if (((n - 1) % (k - 1)) == 0)
    {
        total = n;
    }
    else
    {
        total = n + k - 1 - ((n - 1) % (k - 1));
    }
    cnt = total;
    for (int i = 1; i <= n; i++)
    {
        fr(nodes[i].weight);
        tmp.num = i;
        tmp.weight = nodes[i].weight;
        tmp.depth=1;
        t.push(tmp); // 将所有节点加入优先队列
    }

    for (int i = n + 1; i <= total; i++)
    {
        nodes[i].weight = 0;
        tmp.num = i;
        tmp.weight = nodes[i].weight;
        tmp.depth=1;
        t.push(tmp); // 将补充节点加入优先队列
    }
    while (t.size() > 1)
    {
        cnt++;
        // nodes[total].weight=0;
        tmp.depth=0;
        for (int i = 1; i <= k; i++)
        {
            nodes[cnt].chi[i] = t.top().num;
            nodes[cnt].weight += t.top().weight;
            tmp.depth=max(t.top().depth,tmp.depth);
            t.pop();
        }
        tmp.num = cnt;
        tmp.weight = nodes[cnt].weight;
        tmp.depth++;
        t.push(tmp);
    }
    dfs(cnt, 0);
    cout << totalLength << endl
         << maxLength << endl;
}