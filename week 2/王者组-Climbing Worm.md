# 王者组-Climbing Worm

来源：HDU - 1049

地址：https://vjudge.net/problem/HDU-1049

## 思路：

这道题属于小学奥数题，注意如果最后一次爬上井就停止计时

我们可以去掉最后一次的路程，对于剩余的路程就可以用除法计算要爬几次，然后就可以算总的时间了

还有一点要注意就是总路程小于一次爬的路程的特殊情况

## 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    while ((~scanf("%d%d%d", &a, &b, &c)) && a != 0 && b != 0 && c != 0) {
        if (a < b) printf("1\n");
        else {
            int res = (a - b) / (b - c);
            if ((a - b) % (b - c) != 0) res++;
            printf("%d\n", res * 2 + 1);
        }
    }
    return 0;
}
```