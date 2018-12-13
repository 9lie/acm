# string vector map 简单教程

## string

```cpp
#include <string>
```

首先，需要这个头文件

```cpp
string a = "hello";
string b = "world";
cout << a << ' ' << b << endl;
if (a != b) {
    cout << "NO" << endl;
}
string c = a + b;
cout << c << endl;
```

上面是一个使用的简单例子

同时，`string` 也可以像数组一样操作

```cpp
string a = "hello";
cout << a[3] << endl;
```

上面会输出`l`这个字符

最后，你可以通过 `a.size()` 获取字符串的长度，通过这个，我们就可以遍历整个字符串

```cpp
string a = "hello";
for (int i = 0; i < a.size(); i++) cout << a[i] << endl;
```

## vector

`vector` 的使用和 `string` 类似，我们通过具体例子来学习

```cpp
#include <vector>

vector<int> a = {1, 2, 3, 4};

cout << a[1] << endl;
```

和我们平时用的数组差不多，不过数组的内容的类型写在 **<>** 里面

和数组不同的是，这个可以动态扩充大小

```cpp
vector<int> a = {1, 2};
a.push_back(1);
a.push_back(123);
cout << a[3] << endl;
```

上面输出的是 `123` ，`a.push_back()` 这个函数可以在 `a` 的末尾增加一个元素

一样的， `vector` 也有 `size()` 函数，用法与 `string` 一样

## map

直接上例子

```cpp
#include <map>
map<string, int> a;
a["red"] = 3;
a["blue"] = 12;
```

是不是很好用，数组的下标居然可以是其他类型的东西

map的 **<>** 里，第一个是下标的类型，第二个是储存的数据的类型

一样的，也有 `size()` 函数，不过 `map` 的顺序与你输入的顺序可能不同，你可以把它看做无序的，就像集合一样