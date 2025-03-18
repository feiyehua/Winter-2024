/***
 * @Author       : FeiYehua
 * @Date         : 2025-03-17 20:51:25
 * @LastEditTime : 2025-03-18 10:58:22
 * @LastEditors  : FeiYehua
 * @Description  :
 * @FilePath     : 5082.cpp
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

int s; // 字节数量
const int maxN = 3e5 + 10;
string lastLine;
uint64_t comdata[maxN];
uint64_t oridata[maxN];
int p = -1; // 当前已经输出的字节数量，索引从0开始
// 返回d的第index个字节
uint16_t getByte(int loc, int index)
{
    uint64_t d = comdata[loc];
    for (int i = 1; i <= 8 - index - 1; i++)
    {
        d /= 256;
    }
    return d & 255;
}
uint16_t getOriByte(int loc, int index)
{
    uint64_t d = oridata[loc];
    for (int i = 1; i <= 8 - index - 1; i++)
    {
        d /= 256;
    }
    return d & 255;
}
uint16_t getOriByte(int loc)
{
    return getByte(loc / 8 + 1, loc % 8);
}
uint16_t c[100];
const uint64_t offsetOfByte[] = {1LL << 56, 1LL << 48, 1LL << 40, 1LL << 32, 1LL << 24, 1LL << 16, 1LL << 8, 1LL};
void writeByte(int loc, uint16_t d)
{
    // 在第loc字节的位置输出d
    int a = loc / 8; // 对应uint64的下标
    int b = loc % 8; // 对应uint64的第b个字节
    oridata[a] += offsetOfByte[b] * d;
}
void printByte(int loc)
{
    printf("%02x", getOriByte(loc / 8, loc % 8));
}
void reverseWrite(int o, int l)
{
    int initOffset = p - o + 1;
    if (o >= l)
    {
        for (int i = 0; i < l; i++)
        {
            p++;
            writeByte(p, getOriByte((initOffset + i) / 8, (initOffset + i) % 8));
        }
    }
    else
    {
        int i = 0;
        while (l > 0)
        {
            l--;
            if (i >= o)
            {
                i = 0;
            }
            p++;
            writeByte(p, getOriByte((initOffset + i) / 8, (initOffset + i) % 8));
            i++;
        }
    }
}
int parseLead()
{
    int i = 0;
    int cnt = 0;
    while (1)
    {
        uint16_t curByte = getByte(i / 8 + 1, i % 8);
        c[cnt] = curByte;
        cnt++;
        i++;
        if ((curByte & (uint16_t)128) == 0)
        {
            // c[cnt]+=128;
            break;
        }
        else
        {
            c[cnt - 1] -= 128;
        }
    }
    return cnt; // 返回引导区的字节数量
}
uint32_t getL(int l, int loc)
{
    uint32_t length = 0;
    for (int i = l - 59; i >= 1; i--)
    {
        length <<= 8;
        length += getOriByte(loc + i - 1);
    }
    return length + 1;
}
void parseElement(int &loc) // 从第loc个字节开始解析
{
    uint16_t firstByte = getOriByte(loc);
    loc++;
    if (firstByte % 4 == 0) // 是一个字面量
    {
        int l = firstByte / 4; // 后面l字节是原始字节
        int length = l;
        if (l < 60) // 后面l字节就是原始字节
        {
            length++;
        }
        else
        {
            length = getL(l, loc);
            loc += (l - 59);
        }
        for (int i = loc; i < length + loc; i++)
        {
            p++;
            writeByte(p, getOriByte(i));
        }
        loc = length + loc;
        return;
    }
    else if (firstByte % 4 == 1)
    {
        firstByte /= 4;
        int l = firstByte % 8 + 4;
        firstByte /= 8;
        uint16_t o = (firstByte << 8) + getOriByte(loc);
        loc++;
        reverseWrite(o, l);
    }
    else if (firstByte % 4 == 2)
    {
        int l = firstByte / 4 + 1;
        uint16_t o = (getOriByte(loc + 1) << 8) + getOriByte(loc);
        loc += 2;
        reverseWrite(o, l);
    }
}
int totalByte;
int loc = 1;
size_t tmp;
int main()
{
#ifdef TEST
    freopen("1.in", "r", stdin);
#endif
    fr(s);
    for (int i = 1; i < ceil(s / 8.0); i++)
    {
        scanf("%llx", &comdata[i]); // 读入
    }
    cin >> lastLine;
    totalByte = (ceil(s / 8.0) - 1) * 8 + (lastLine.size() / 2);
    while (lastLine.size() < 16)
    {
        lastLine += '0';
    }
    comdata[(int)ceil(s / 8.0)] = stoull(lastLine, &tmp, 16);
    loc = parseLead();
    while (loc < totalByte)
    {
        parseElement(loc);
    }
    // freopen("1.out", "w", stdout);
    for (int i = 0; i <= p; i++)
    {
        printByte(i);
        if (i % 8 == 7)
        {
            printf("\n");
        }
    }
}
