#include<bits/stdc++.h>

using namespace std;
const int inf = 9999;
const int MAXN = 111;
int mp[MAXN][MAXN], dis[MAXN], vis[MAXN];
int n, s, m, x, y, d;
vector<int> vec;
int path[MAXN] = {-1};

void in() {
    vec.clear();
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) mp[i][j] = 0;
            else mp[i][j] = inf;
        }
    }
    while (m--) {
        cin >> x >> y >> d;
        mp[x][y] = mp[y][x] = d;
    }
}

void print(int s, int n) {
    stack<int> q;
    int p = n;
    while (path[p] != -1) {
        q.push(p);
        p = path[p];
    }
    cout << dis[n] << endl;
    cout<<q.top();
    q.pop();
    while (!q.empty()) {
        cout << "->" << q.top();
        q.pop();
    }
    cout << endl;
}


void Dijkstra() {
    int i, j, k;
    for (s = 1, i = 1; i <= n; i++) {
        dis[i] = inf;
        vis[i] = 0;
    }
    for (dis[s] = 0, j = 1; j <= n; j++) {
        for (k = -1, i = 1; i <= n; i++) {
            if (!vis[i] && (k == -1 || dis[i] < dis[k])) {
                k = i;
            }
        }
        for (vis[k] = 1, i = 1; i <= n; i++) {
            if (!vis[i] && dis[k] + mp[k][i] < dis[i]) {
                dis[i] = dis[k] + mp[k][i];
                vec.push_back(k);
                path[i] = k;
            }
        }
    }
}


int main() {
    freopen("in.txt", "r", stdin);
    while (cin >> n >> m) {
        if (n == 0 && m == 0)break;
        in();
        Dijkstra();
        print(s, n);
    }
}
