## 题目：HDU - 2027
地址：https://vjudge.net/problem/HDU-2027
---
这道题提醒了我格式的问题

答案最后有一个回车

并且也说明了我字符串处理能力很差，对于带空格的句子一下子找不到思路

以后要加强这方面的学习
## 代码：
```cpp
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main () {
    int  n;
    char tmp;
    scanf("%d", &n);
    scanf("%c", &tmp);
    while (n--) {
        int a = 0, e = 0, i = 0, o = 0, u = 0;
        char c;
        while (~scanf("%c", &c)) {
            if (c == '\n') break;
            if (c == 'a' || c == 'A') a++;
            else if(c == 'e' ||c == 'E') e++;
            else if (c == 'i' ||c == 'I') i++;
            else if (c == 'o' || c== 'O') o++;
            else if (c == 'u' || c == 'U') u++;
        }
        cout << "a:" << a << "\ne:" << e <<"\ni:" << i <<"\no:" <<o << "\nu:" <<u <<endl;
        if (n != 0) cout << endl;
    }
    return 0;
}
```