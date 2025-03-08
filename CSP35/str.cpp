/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-03 19:46:01
 * @LastEditTime : 2025-03-03 20:00:20
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : str.cpp
 * @     © 2024 FeiYehua
 */
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
string tmp;
char f[200][40];
int m;
const int maxM = 1e3 + 10;
int k[maxM];
string oris;
int maxK;
int main()
{
    getline(cin, s);
    oris = s;
    cin >> n;
    for (int i = 0; i <= 25; i++)
    {
        f['A' + i][1] = 'A' + i;
        f['a' + i][1] = 'a' + i;
    }
    for (int i = 0; i <= 9; i++)
    {
        f['0' + i][1] = '0' + i;
    }
    f[' '][1] = ' ';
    for (int i = 1; i <= n; i++)
    {
        do
        {
            getline(cin, tmp);
        } while (tmp.empty());
        f[tmp[1]][1] = tmp[2];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> k[i];
        maxK = max(maxK, k[i]);
    }
    for (int j = 2; j <= log2(maxK) + 2; j++)
    {
        for (int i = 0; i <= 25; i++)
        {
            f['A' + i][j] = f[f['A' + i][j - 1]][j - 1];
            f['a' + i][j] = f[f['a' + i][j - 1]][j - 1];
        }
        for (int i = 0; i <= 9; i++)
        {
            f['0' + i][j] = f[f['0' + i][j - 1]][j - 1];
        }
        f[' '][j] = f[f[' '][j - 1]][j - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        s = oris;
        int cnt = 1;
        while (k[i] > 0)
        {
            if (k[i] % 2 == 1)
            {
                for (auto &c : s)
                {
                    c = f[c][cnt];
                }
            }
            k[i] /= 2;
            cnt++;
        }
        cout<<"#" << s << "#\n";
    }
}