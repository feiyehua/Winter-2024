/*** 
 * @Author       : FeiYehua
 * @Date         : 2025-01-12 23:50:56
 * @LastEditTime : 2025-01-13 00:03:24
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
// 性质：如果出现相当数量的连续D/R后，对于一个空格子，其所在行或者所在列之一最多只有一个格子没有填。
// 也就是说，确定其行和、列和后，其有无解是可以唯一确定的。
// 变数出现在直角拐弯，但是最坏情况也只会导致出现行列中均有两个未知数。
// 对于起终点，还是可以确定的。
// 感觉像是一个搜索之类的东西。
int main()
{
    
}