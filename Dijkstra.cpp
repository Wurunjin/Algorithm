#include <bits/stdc++.h>

using namespace std;
const int inf = 9999;
const int MAXN = 111;
int mp[MAXN][MAXN];
int dis[MAXN];
int vis[MAXN];
int n, s;

void scf() {
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mp[i][j];
            if (mp[i][j] == 0) {
                mp[i][j] = inf;
            }
        }
    }
}

void Dijkstra() {
    for (int i = 0; i < n; i++) {
        dis[i] = inf;
        vis[i] = 0;
    }
    int i, j, k;
    for (dis[s] = 0, j = 0; j < n; j++) {
        for (k = -1, i = 0; i < n; i++) {
            if (!vis[i] && (k == -1 || dis[i] < dis[k])) {
                k = i;
            }
        }
        for (vis[k] = 1, i = 0; i < n; i++) {
            if (!vis[i] && dis[k] + mp[k][i] < dis[i]) {
                dis[i] = dis[k] + mp[k][i];
            }
        }
    }
}

int main() {
    scf();
    Dijkstra();
    for (int i = 0; i < n; i++) {
        if (i != s) {
            if (dis[i] < inf)
                printf("%d ", dis[i]);
            else
                printf("%d ", -1);
        }
    }
    //dis[]={6,0,4,7};
    return 0;
}

//test in
// 4 1
// 0 3 0 1
// 0 0 4 0
// 2 0 0 0
// 0 0 1 0

//test out
//6 4 7
