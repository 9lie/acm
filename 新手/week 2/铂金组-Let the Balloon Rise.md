# 铂金组-Let the Balloon Rise

来源：HDU - 1004

地址：https://vjudge.net/problem/HDU-1004

## 思路：

先学习一下 **map**

```cpp
map<string, int> color;
color["red"]++;
```

使用就是这么简单

遍历的方法：

```cpp
map<string, int>::iterator it;
for (it = color.begin(); it != color.end(); it++) {
    cout << it->first << "->" << it->second << endl;
}
```

也很简单，和 `vector` 类似

不过这次没有用到，因为只要在输入的过程中不断记录最大的那个颜色就行了

## 代码：

```cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (~scanf("%d", &n) && n != 0) {
        map<string, int> color;
        int most = 0;
        string c, ans;
        for (int i = 0; i < n; i++) {
            cin >> c;
            color[c]++;
            if (color[c] > most) {
                most = color[c];
                ans = c;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
```