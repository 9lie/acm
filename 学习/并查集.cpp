#include <bits/stdc++.h>
using namespace std;
const int un_max = 1000;
int par[un_max];
int rnk[un_max] = {1};

void initun(int n) {
    for (int i = 0; i <= n; i++) {
        par[i] = i;
        rnk[i] = 1;
    }
}

int findr(int x) {
    int r = x, tmp;
    while (par[r] != r) r = par[r];
    while (x != r) {
        tmp = par[x];
        par[x] = r;
        x = tmp;
    }
    return r;
}

int unite(int x, int y) {
    x = findr(x); y = findr(y);
    if (x == y) return x;
    if (rnk[x] < rnk[y]) swap(x, y);
    par[y] = x;
    if (rnk[x] == rnk[y]) rnk[x]++;
    return x;
}

int main() {
    //����һ������һ�㵫Ч�ʸ�һ��Ĳ��鼯
    //findr()���õݹ��ֹ��ջ
    return 0;
}
