# 白银组-cAPS lOCK

来源：CodeForces - 131A

地址：https://vjudge.net/problem/CodeForces-131A

## 思路：

循环检查第2位到最后一位是否全为大写，如果不是，直接输入原来的，如果是，大小写转换

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    string str, tmp;
    int n = 0;
    cin >> str;
    tmp = str;
    for (int i = 1; i < str.size(); i++) {
        if (tmp[i] >= 'A' && tmp[i] <= 'Z') {
            n++;
            tmp[i] = tmp[i] + ('a' - 'A');
        } else {
            cout << str << endl;
            break;
        }
    }
    if (n == str.size() - 1) {
        if (tmp[0] >= 'A' && tmp[0] <= 'Z') tmp[0] = tmp[0] + ('a' - 'A');
        else tmp[0] = tmp[0] + ('A' - 'a');
        cout << tmp << endl;
    }
    return 0;
}
```