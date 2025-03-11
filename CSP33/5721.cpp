/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-08 10:36:02
 * @LastEditTime : 2025-03-10 20:55:17
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : 5721.cpp
 * @     © 2024 FeiYehua
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
map<string, int> a;
const double eps = 1e-6;
double matrix[50][50];
string tmp;
enum lastElement
{
    DIGITS,
    LETTERS,
    SPACE
};
void parseStr(string &s, int &numberOfElements)
{
    a.clear();
    memset(matrix, 0, sizeof matrix);
    int numberOfThings = 1;
    int tmpN = 0;
    string elementName = "";
    lastElement lastElement = SPACE;
    s += ' ';
    for (auto it : s)
    {
        if (it == ' ')
        {
            matrix[a[elementName]][numberOfThings] = tmpN;
            numberOfThings++; // 物质数量
            tmpN = 0;
            elementName = "";
            lastElement = SPACE;
        }
        else
        {
            if (!isdigit(it)) // 是字母
            {
                if (lastElement == DIGITS) // 进入到了同一物质的下一个元素
                {
                    matrix[a[elementName]][numberOfThings] = tmpN;

                    elementName = "";
                    tmpN = 0;
                }
                lastElement = LETTERS;
                elementName += it;
            }
            else
            {
                if (lastElement == LETTERS)
                {
                    // 此前是字母，那么需要维护元素对应的索引
                    if (a.find(elementName) == a.end())
                    {
                        a.insert(make_pair(elementName, a.size() + 1));
                    }
                }
                lastElement = DIGITS;
                tmpN = tmpN * 10 + it - '0';
            }
        }
    }
    numberOfElements = a.size();
}
int numberOfThings, numberOfElements;
bool getSolu(const int &numberOfThings, const int &numberOfElements)
{
    for (int i = 1; i <= numberOfElements; i++)
    {
        {
            for (int j = i + 1; j <= numberOfElements; j++)
            {

                if ((abs(matrix[j][i]) >= eps && abs(matrix[j][i]) < abs(matrix[i][i])) || (abs(matrix[i][i]) <= eps && (abs(matrix[j][i]) >= eps)))
                {
                    for (int k = i; k <= numberOfThings; k++)
                    {
                        swap(matrix[i][k], matrix[j][k]);
                    }
                }
            }
            if (abs(matrix[i][i]) <= eps)
            {
                continue;
            }
        }
        for (int j = i + 1; j <= numberOfElements; j++)
        {
            if (abs(matrix[j][i]) <= eps)
            {
                continue;
            }
            double g = matrix[j][i] / matrix[i][i];
            for (int k = i + 1; k <= numberOfThings; k++)
            {
                matrix[j][k] -= g * matrix[i][k];
            }
            matrix[j][i] = 0;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= numberOfElements; i++)
    {
        for (int j = i; j <= numberOfThings; j++)
        {
            if (abs(matrix[i][i]) >= eps)
            {
                cnt++;
                break;
            }
        }
    }
    if (cnt < numberOfThings)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
signed main()
{
    fr(n);
    for (int i = 1; i <= n; i++)
    {
        fr(numberOfThings);
        getline(cin, tmp);
        parseStr(tmp, numberOfElements);
        if (numberOfElements < numberOfThings || getSolu(numberOfThings, numberOfElements))
        {
            cout << "Y\n";
        }
        else
        {
            cout << "N\n";
        }
    }
}
