/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-04 10:16:18
 * @LastEditTime : 2025-03-04 10:16:20
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : patch.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
int n;
const int maxN = 2e3 + 10;
// string ori[maxN];
vector<string> ori;
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
int nnDelta;
char ch;
string tmp;
enum type
{
    START,
    ADD,
    DEL,
    ORI,
    DEFAULT
};
vector<pair<string, type>> diff;
struct node
{
    int it;
    int NN, MM, nn, mm;
};
node tmpNode;
vector<node> patchStart;
int getDiff(string &s, node &tmp)
{
    tmp.mm = 0;
    tmp.MM = 0;
    tmp.NN = 0;
    tmp.nn = 0;
    if (s[0] != '@' || s[1] != ' ' || s[2] != '-')
    {
        return -1;
    }
    int i = 3;
    while (s[i] != ',' && i < s.size())
    {
        if (!isdigit(s[i]))
        {
            return -1;
        }
        tmp.NN = tmp.NN * 10 + s[i] - '0';
        i++;
    }
    i++;
    while (s[i] != ' ' && i < s.size())
    {
        if (!isdigit(s[i]))
        {
            return -1;
        }
        tmp.MM = tmp.MM * 10 + s[i] - '0';
        i++;
    }
    i++;
    if (s[i] != '+' && i < s.size())
    {
        if (!isdigit(s[i]))
        {
            return -1;
        }
        return -1;
    }
    i++;
    while (s[i] != ',' && i < s.size())
    {
        if (!isdigit(s[i]))
        {
            return -1;
        }
        tmp.nn = tmp.nn * 10 + s[i] - '0';
        i++;
    }
    i++;
    while (s[i] != ' ' && i < s.size())
    {
        if (!isdigit(s[i]))
        {
            return -1;
        }
        tmp.mm = tmp.mm * 10 + s[i] - '0';
        i++;
    }
    i++;
    if (s[i] != '@' || s[i + 1] != '@' || i + 1 < s.size())
    {
        return -1;
    }
    return 0;
}
type getType(char ch)
{
    if (ch == '@')
    {
        return START;
    }
    if (ch == ' ')
    {
        return ORI;
    }
    if (ch == '+')
    {
        return ADD;
    }
    if (ch == '-')
    {
        return DEL;
    }
    return DEFAULT;
}
bool check(vector<string> &oriStr, int NN, int delta)
{
    // 从NN+delta开始替换
    for (int i = 0; i < oriStr.size(); i++)
    {
        if (oriStr[i] != ori[NN + delta + i])
        {
            return 0;
        }
    }
    return 1;
}
bool beginPatch;
int main()
{
    freopen("/Users/xiong/Downloads/CSP202409-3/4.in","r",stdin);
    fr(n);
    ori.push_back("");
    for (int i = 1; i <= n; i++)
    {
        do
        {
            getline(cin, tmp);
        } while (tmp.empty());
        ori.push_back(tmp);
    }
    while (1)
    {
        ch = getchar();
        if (ch == EOF)
        {
            break;
        }
        getline(cin, tmp);
        if (ch != '@' && !beginPatch)
        {
            continue;
        }
        if (ch == '#')
        {
            continue;
        }
        else if (ch != ' ' && ch != '+' && ch != '-' && ch != '@')
        {
            cout << "Patch is damaged." << endl;
            return 0;
        }
        else
        {
            diff.push_back(make_pair(tmp, getType(ch)));
            if (ch == '@')
            {
                beginPatch = 1;
                getDiff(tmp, tmpNode);
                tmpNode.it = diff.size() - 1;
                patchStart.push_back(tmpNode);
            }
        }
    }
    if (patchStart.empty())
    {
        cout << "Patch is damaged." << endl;
        return 0;
    }
    tmpNode.it = diff.size();

    patchStart.push_back(tmpNode);
    for (int i = 0; i < patchStart.size() - 1; i++)
    {
        patchStart[i].NN += nnDelta;
        if (i != 0)
        {
            if (patchStart[i].NN < patchStart[i - 1].MM + patchStart[i - 1].NN)
            {
                cout << "Patch is damaged." << endl;
                return 0;
            }
        }
        vector<string> oriStr;
        vector<string> newStr;
        auto it = patchStart[i].it + 1;
        while (it < patchStart[i + 1].it)
        {
            if (diff[it].second == ADD || diff[it].second == ORI)
            {
                newStr.push_back(diff[it].first);
            }
            if (diff[it].second == DEL || diff[it].second == ORI)
            {
                oriStr.push_back(diff[it].first);
            }
            it++;
        }
        if (oriStr.size() != patchStart[i].MM || newStr.size() != patchStart[i].mm)
        {
            cout << "Patch is damaged." << endl;
            return 0;
        }
        int j = 0;
        int find = 99999;
        for (j = 0; j < patchStart[i].MM; j++)
        {
            if (check(oriStr, patchStart[i].NN, j))
            {
                find = j;
                break;
            }
            if (check(oriStr, patchStart[i].NN, -j))
            {
                find = -j;
                break;
            }
        }
        if (find==99999)
        {
            cout << "Patch is damaged." << endl;
            return 0;
        }
        nnDelta += find;
        
        for(int k=1;k<=patchStart[i].MM;k++)
        {   
            ori.erase(ori.begin()+patchStart[i].NN+find);
        }
        for(int k=1;k<=patchStart[i].mm;k++)
        {
            ori.insert(ori.begin()+patchStart[i].NN+find+k-1,newStr[k-1]);
        }
    }
    for(auto it:ori)
    {
        cout<<it<<endl;
    }
}