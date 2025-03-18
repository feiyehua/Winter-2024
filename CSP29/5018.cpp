/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-18 15:53:29
 * @LastEditTime : 2025-03-18 16:02:15
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : 5018.cpp
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
/*
断言：有属性，且与之相等
反断言～ 有属性，且与之不等
逻辑操作：｜，&

*/

int n;
int m;
int attriCnt;
const int maxN = 3e3;
struct node
{
    unordered_map<int, int> attri;
    int dn;
} users[maxN];
set<int> dnlist;
string query;
enum op
{
    ASSERT,
    ANTIASSERT
};
enum logic
{
    AND,
    OR
};
int pairedBracket[maxN];
void getPairedBracket(const string &s)
{
    stack<int> stk;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] != '(' && s[i] != ')')
        {
            continue;
        }
        else if (s[i] == '(')
        {
            stk.push(i);
        }
        else if (s[i] == ')')
        {
            pairedBracket[stk.top()] = i;
            stk.pop();
        }
    }
}
bool parseBaseExpr(const string &s, int user)
{
    int attri = 0;
    int num = 0;
    int i = 0;
    op op;
    for (; i < s.size(); i++)
    {
        if (!isdigit(s[i]))
        {
            break;
        }
        attri *= 10;
        attri += s[i] - '0';
    }
    if (s[i] == ':')
    {
        op = ASSERT;
    }
    else
    {
        op = ANTIASSERT;
    }
    i++;
    for (; i < s.size(); i++)
    {
        num *= 10;
        num += s[i] - '0';
    }
    auto it = users[user].attri.find(attri);
    if (it == users[user].attri.end())
    {
        return 0;
    }
    if (op == ASSERT && it->second == num)
    {
        return 1;
    }
    else if (op == ANTIASSERT && it->second != num)
    {
        return 1;
    }
    return 0;
}
bool parseExpr(int user, int l, int r) // l-r的闭区间
{
    logic logic;
    if (query[l] == '&')
    {
        logic = AND;
    }
    else if (query[l] == '|')
    {
        logic = OR;
    }
    else
    {
        // 是一个基础表达式
        return parseBaseExpr(query.substr(l, r - l + 1), user);
    }
    // 判断是不是一个基础表达式：看字串中有没有括弧
    int firstLeftBracket = l + 1;
    int firstRightBracket = pairedBracket[firstLeftBracket];
    int secondLeftBracket = firstRightBracket + 1;
    int secondRightBracket = pairedBracket[secondLeftBracket];
    assert(query[firstLeftBracket] == '(' && query[secondLeftBracket] == '(' && query[firstRightBracket] == ')' && query[secondRightBracket] == ')');
    if (logic == AND)
    {
        return parseExpr(user, firstLeftBracket + 1, firstRightBracket - 1) & parseExpr(user, secondLeftBracket + 1, secondRightBracket - 1);
    }
    else
    {
        return parseExpr(user, firstLeftBracket + 1, firstRightBracket - 1) | parseExpr(user, secondLeftBracket + 1, secondRightBracket - 1);
    }
}
int main()
{
#ifdef TEST
    freopen("1.in", "r", stdin);
#endif
    fr(n);
    for (int i = 1; i <= n; i++)
    {
        fr(users[i].dn);
        fr(attriCnt);
        for (int j = 1; j <= attriCnt; j++)
        {
            int x, y;
            fr(x);
            fr(y);
            users[i].attri.insert(make_pair(x, y));
        }
    }
    fr(m);
    for (int i = 1; i <= m; i++)
    {
        cin >> query;
        memset(pairedBracket, 0, sizeof pairedBracket);
        getPairedBracket(query);
        dnlist.clear();
        for (int j = 1; j <= n; j++)
        {
            if (query.find('(') == query.npos)
            {
                if (parseBaseExpr(query, j))
                {
                    dnlist.insert(users[j].dn);
                }
            }
            if (parseExpr(j, 0, query.size() - 1))
            {
                dnlist.insert(users[j].dn);
            }
        }
        for (auto it : dnlist)
        {
            printf("%d ", it);
        }
        printf("\n");
    }
}


