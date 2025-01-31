/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-01-12 23:50:56
 * @LastEditTime : 2025-01-13 09:48:15
 * @LastEditors  : FeiYehua
 * @Description  : 
 * @FilePath     : C.cpp
 * @     © 2024 FeiYehua
 */
#include<bits/stdc++.h>
using namespace std;
const int maxN=1010;
int t;
int gridMap[maxN][maxN];
int n,m;
string s;
// 性质：如果出现相当数量的连续D/R后，对于一个空格子，其所在行或者所在列之一最多只有一个格子没有填。
// 也就是说，确定其行和、列和后，其有无解是可以唯一确定的。
// 变数出现在直角拐弯，但是最坏情况也只会导致出现行列中均有两个未知数。
// 对于起终点，还是可以确定的。
// 感觉像是一个搜索之类的东西。
// 正解：
// 每行、每列的和，是相等的（没看到草）
// 由于每次m不等于n，所以只有每行、每列的和为0的情况。
// 由此可以确定至少最左上和最右下的格子。
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m>>s;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=m;k++)
            {
                cin>>gridMap[j][k];//读入
            }
        }
        
    }
}