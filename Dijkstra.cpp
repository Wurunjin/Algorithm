#include <cstdio>
#include <cstdlib>
#include <stack>
#include <algorithm>
#include<bits/stdc++.h>

using namespace std;
const int MAXN = 50;
const int INF = 1000000000;
int mat[MAXN][MAXN], min_distance[MAXN], v[MAXN];
int n, s;

void in() {
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
            if (mat[i][j] == 0)
                mat[i][j] = INF;
        }
    }
}

void dijkstra() {
    int i, j, k;
    for (i = 0; i < n; i++) {//初始化min_distance[]&v[]
        min_distance[i] = INF;
        v[i] = 0;
    }
    for (min_distance[s] = 0, j = 0; j < n; j++) {
        for (k = -1, i = 0; i < n; i++) {
            if (not v[i] && (k == -1 || min_distance[i] < min_distance[k])) {
                k = i;
            }
        }
        cout << k << endl;
        //上面这个for循环 作用是i点未访问 and 找到第一个最小的点赋给k
        //在未选择的点里找到那个离k最近（路径最短）的点 然后选择这个点
        for (v[k] = 1, i = 0; i < n; i++) {
            if (not v[i] && min_distance[k] + mat[k][i] < min_distance[i]) {
                min_distance[i] = min_distance[k] + mat[k][i];
            }
        }
    }
}

int main() {
    //ifstream cin("in.txt");
    in();
    dijkstra();
    for (int i = 0; i < n; i++) {
        if (i != s) {
            if (min_distance[i] < INF)
                printf("%d ", min_distance[i]);
            else
                printf("%d ", -1);
        }
    }
    return 0;
}
/*
4 1
0 3 0 1
0 0 4 0
2 0 0 0
0 0 1 0
 */
