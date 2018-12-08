## 题目：HDU - 1232
地址：https://vjudge.net/problem/HDU-1232
---
这道题用并查集解，但是我不记得怎么写了。。。

基本上靠回忆并查集的实现原理，实现了一个十分粗糙的并查集

最终勉强通过，但是并查集还是得重新复习一下
## 代码
```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int city[1005];
bool used[1005];
void add(int x, int y) {
	if (city[x] < 0 && city[y] < 0) {
		city[x] = y;
		city[y] = y;
	} else if (city[x] < 0) {
		city[x] = y;
	} else if (city[y] < 0) {
		city[y] = x;
	} else if (city[y] == y && city[x] == x) {
		city[x] = y;
	} else if (city[x] == x) {
		add(city[y], x);
	} else {
		add(city[x], y);
	}
}
int main() {
	int c, l;
	while ((cin >> c >> l) && c != 0) {
		memset(city, -1, sizeof(city));
		memset(used, 0, sizeof(used));
		vector<int> list;
		for (int i = 0; i < l; i++) {
			int x, y;
			cin >> x >> y;
			if (x == y) continue;
			add(x, y);
			if (!used[x]) {
				list.push_back(x);
				used[x] = true;
			}
			if (!used[y]) {
				list.push_back(y);
				used[y] = true;
			}
		}
		int res = c - list.size();
		for (int i = 0; i < list.size(); i++) {
			if (city[list[i]] == list[i]) res++;
		}
		cout << (res - 1) << endl;
	}
	return 0;
}
```