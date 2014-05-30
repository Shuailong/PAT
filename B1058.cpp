#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int g1, s1, k1;
    int g2, s2, k2;
    scanf("%d.%d.%d %d.%d.%d", &g1, &s1, &k1, &g2, &s2, &k2);
    int g, s, k;
    k = (k1 + k2) % 29;
    s = (s1 + s2 + (k1 + k2) / 29) % 17;
    g = (g1 + g2) + (s1 + s2 + (k1 + k2) / 29) / 17;

    printf("%d.%d.%d\n", g, s, k);
    system("pause");
    return 0;
}