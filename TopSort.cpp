#include<bits/stdc++.h>

using namespace std;
const int inf = 9999999;
const int MAXN = 1e5 + 5;
vector<int> g[MAXN];
int du[MAXN]；//计算每个顶点的度
int l[MAXN];//储存TopSort的结果
int n, m, a, b;

bool Top_Sort() {
    int tot = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < g[i].size(); j++)
            du[g[i][j]]++;
    priority_queue<int, vector<int>, less<int> > q;//也可以priority_queue<int, vector<int>, greater<int> > q or queue<int>q...;
    for (int i = 1; i <= n; i++)
        if (!du[i])
            q.push(i);
    while (!q.empty()) {
        int x = q.top();
        q.pop();
        l[tot++] = x;
        for (int j = 0; j < g[x].size(); j++) {
            int t = g[x][j];
            du[t]--;
            if (!du[t]) {
                q.push(t);
            }
        }
    }
    if (tot == n + 1)
        return true;
    return false;
}

int main() {
    //ifstream cin("in.txt");
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(du,0,sizeof(du));
        memset(l,0,sizeof(l));
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            g[a].push_back(b);
        }
        if (Top_Sort()) {
            for (int i = 1; i <= n; i++) {
                if (i - 1)cout << " ";
                cout << l[i];
            }
            cout << endl;
        } else {
            cout << -1 << endl;
        }
    }
}

//test in
//1
//4 3
//1 2 
//2 3
//4 3

//test out
//4 1 2 3
