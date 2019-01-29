# A-Pots

 来源：POJ - 3414

地址：https://cn.vjudge.net/problem/POJ-3414

# 思路

BFS，把a，b两个瓶的水的量看做x，y坐标，倒水的过程就是坐标的移动，终点就是x的坐标为总水量的一半

用一个step数组记录前一个坐标，act数组记录经过什么操作到达这个坐标

为了操作方便，用一个判断来确保a瓶大于b瓶，然后准备两组操作

# 代码

```cpp
//#include <bits/stdc++.h>
#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define endl '\n'
typedef pair<int, int> pii;

string action[2][6] = {
    "FILL(1)",
    "FILL(2)",
    "DROP(1)",
    "DROP(2)",
    "POUR(1,2)",
    "POUR(2,1)",
    "FILL(2)",
    "FILL(1)",
    "DROP(2)",
    "DROP(1)",
    "POUR(2,1)",
    "POUR(1,2)",
};

int act[101][101];
int step[101][101];
bool used[101][101];

int main(){
    int a, b, c;
    while (cin >> a >> b >> c) {
        pii pre[101][101];
        memset(used, false, sizeof(used));
        memset(act, -1, sizeof(used));
        memset(step, 0, sizeof(step));
        int swaped = 0;
        if (a < b) {
            swap(a, b);
            swaped = 1;
        }
        queue<pii> q;
        int ansi = 0, ansj = 0;
        q.push(pii(0,0));
        used[0][0] = true;

        while (!q.empty()) {
            pii p = q.front(); q.pop();
            int i = p.first, j = p.second, ni, nj;
            if (i == c || j == c) {
                ansi = i;
                ansj = j;
                break;
            }
            // 0
            ni = a; nj = j;
            if (!used[ni][nj]) {
                used[ni][nj] = true;
                step[ni][nj] = step[i][j] + 1;
                act[ni][nj] = 0;
                q.push(pii(ni, nj));
                pre[ni][nj] = pii(i,j);
            }
            // 1
            ni = i; nj = b;
            if (!used[ni][nj]) {
                used[ni][nj] = true;
                step[ni][nj] = step[i][j] + 1;
                act[ni][nj] = 1;
                q.push(pii(ni, nj));
                pre[ni][nj] = pii(i,j);
            }
            // 2
            ni = 0; nj = j;
            if (!used[ni][nj]) {
                used[ni][nj] = true;
                step[ni][nj] = step[i][j] + 1;
                act[ni][nj] = 2;
                q.push(pii(ni, nj));
                pre[ni][nj] = pii(i,j);
            }
            // 3
            ni = i; nj = 0;
            if (!used[ni][nj]) {
                used[ni][nj] = true;
                step[ni][nj] = step[i][j] + 1;
                act[ni][nj] = 3;
                q.push(pii(ni, nj));
                pre[ni][nj] = pii(i,j);
            }
            // 4
            ni = (i+j>b ? i+j-b : 0); nj = (i+j>b ? b : i+j);
            if (!used[ni][nj]) {
                used[ni][nj] = true;
                step[ni][nj] = step[i][j] + 1;
                act[ni][nj] = 4;
                q.push(pii(ni, nj));
                pre[ni][nj] = pii(i,j);
            }
            // 5
            ni = (i+j>a ? a : i+j); nj = (i+j>a ? i+j-a : 0);
            if (!used[ni][nj]) {
                used[ni][nj] = true;
                step[ni][nj] = step[i][j] + 1;
                act[ni][nj] = 5;
                q.push(pii(ni, nj));
                pre[ni][nj] = pii(i,j);
            }
        }
        if (step[ansi][ansj] == 0) printf("impossible\n");
        else {
            printf("%d\n", step[ansi][ansj]);
            vector<int> s;

            while (step[ansi][ansj]) {
                s.push_back(act[ansi][ansj]);
                int pi = pre[ansi][ansj].first;
                int pj = pre[ansi][ansj].second;
                ansi = pi;
                ansj = pj;
            }
            for (int i = s.size() - 1; i >= 0; i--) {
                cout << action[swaped][s[i]] << endl;
            }
        }
    }
	return 0;
}
```