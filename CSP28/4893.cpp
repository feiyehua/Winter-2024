/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-19 19:30:22
 * @LastEditTime : 2025-03-19 19:49:02
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : 4893.cpp
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

int q[10][10];
int n;
int t;
int m[10][10];
double mm[10][10];
const double pi = acos(-1.0);
int x[65] = {1, 2, 1, 1, 2, 3, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7, 8, 7, 6, 5, 4, 3, 2, 1, 2, 3, 4, 5, 6, 7, 8, 8, 7, 6, 5, 4, 3, 4, 5, 6, 7, 8, 8, 7, 6, 5, 6, 7, 8, 8, 7, 8};
int y[65] = {1, 1, 2, 3, 2, 1, 1, 2, 3, 4, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2, 1, 1, 2, 3, 4, 5, 6, 7, 8, 8, 7, 6, 5, 4, 3, 2, 3, 4, 5, 6, 7, 8, 8, 7, 6, 5, 4, 5, 6, 7, 8, 8, 7, 6, 7, 8, 8};
double alpha(int u)
{
    if (u == 0)
    {
        return sqrt(0.5);
    }
    return 1.0;
}
int output[10][10];
int cnt=-1; // 读入数据数量的统计
void readM()
{
    // 到达左边界时，向下一次，然后开始向右上；
    // 到达下边界时，向下一次，然后开始向右上；
    // 到达上边界时，向右一次，然后向左下；
    // 到达右边界时，向下一次，然后向左下
    for (int i = 1; i <= 64; i++)
    {
        cnt++;
        if (cnt < n)
        {
            fr(m[y[cnt % 64] - 1][x[cnt % 64] - 1]);
        }
        else
        {
            m[y[cnt % 64] - 1][x[cnt % 64] - 1] = 0;
        }
    }
}
void multiM()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            m[i][j] *= q[i][j];
        }
    }
}
void reverseM()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            for (int u = 0; u < 8; u++)
            {
                for (int v = 0; v < 8; v++)
                {
                    mm[i][j] += alpha(u) * alpha(v) * m[u][v] * cos(pi / 8 * (i + 0.5) * u) * cos(pi / 8 * (j + 0.5) * v);
                }
            }
            mm[i][j] /= 4;
            mm[i][j]+=128;
            output[i][j] = nearbyint(mm[i][j]);
            if (output[i][j] > 255)
            {
                output[i][j] = 255;
            }
            else if (output[i][j] < 0)
            {
                output[i][j] = 0;
            }
        }
    }
}
int main()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            fr(q[i][j]);
        }
    }
    fr(n);
    fr(t);
    readM();
    switch (t)
    {
    case 0:
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
        break;
    case 1:
        multiM();
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d ", m[i][j]);
            }
            printf("\n");
        }
        break;
    case 2:
        multiM();
        reverseM();
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                printf("%d ", output[i][j]);
            }
            printf("\n");
        }
        break;
    default:
        break;
    }
}