# 铂金组-A + B Again

来源：HDU - 2057

地址：https://vjudge.net/problem/HDU-2057

## 思路：

这道题需要注意如何输出16进制的负数

因为16进制用负数用**补码**表示，所以输出前要转成正数，然后手动输出负号

另外，还学到了输入输出的技巧

**%x %X** 可以输入输出16进制，分别对应大写和小写

更多技巧请看：https://blog.csdn.net/zhiboyongjian/article/details/45331611

## 代码：
```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b;
    while (~scanf("%llx%llx", &a, &b)) {
        if (a + b < 0) printf("-%llX\n", -(a + b));
        else printf("%llX\n", a + b);
    }
    return 0;
}

```