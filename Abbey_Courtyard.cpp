#include <stdio.h>

#include <vector>
#include <limits>
#include <algorithm>

#include <cmath>

int main()
{
    long long  a;
    scanf("%d",&a);

    auto line = sqrtl(a);
    printf("%.7f",line * 4.0);

    return 0;
}