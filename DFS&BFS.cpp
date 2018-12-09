#include<bits/stdc++.h>
using namespace std;
int m,n,sx,sy,mn,mp[22][22],c,d,s;
void prt(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%2d",mp[i][j]);
        }cout<<endl;
    }cout<<endl;
}
void dfs(int x,int y){
    if(!(x>=0&&x<m&&y>=0&&y<n&&mp[x][y]==0)) return ;
    if(x==c&&y==d){
        if(s<mn){mn=s;}return ;
    }
    s++;
    mp[x][y]=2;
    dfs(x+1,y);
    dfs(x-1,y);
    dfs(x,y+1);
    dfs(x,y-1);
    if(mp[x][y]==2){
        s--;mp[x][y]=0;
    }
}
int main(){
    while(cin>>m>>n&&m&&n){
        mn=999999;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)cin>>mp[i][j];
        }
        cin>>sx>>sy>>c>>d;
        sx--;sy--;c--;d--;
        dfs(sx,sy);
        if(mn==999999){
            cout<<"No Way!"<<endl;
        }else{
            cout<<mn<<endl;
        }
    }
}



















#include<bits/stdc++.h>
using namespace std;
struct node{int x,y,sp;};
int mp[22][22],m,n,sx,sy,ex,ey,b;
bool v[22][22];
int dis[4][2]={0,1,1,0,-1,0,0,-1};
int bfs(int x,int y){
    node now;now.x=x,now.y=y,now.sp=0;
    queue<node> q;
    q.push(now);
    while(!q.empty()){
        now=q.front();
        q.pop();
        if(now.x==ex&&now.y==ey)return now.sp;
        for(int i=0;i<4;i++){
            node next;
            next.x=now.x+dis[i][0];next.y=now.y+dis[i][1];
            next.sp=now.sp+1;
            if(next.x>=0&&next.y>=0&&next.x<m&&next.y<n&&mp[next.x][next.y]!=1){
                q.push(next);mp[next.x][next.y]=1;
            }}}return -1;
}
int main(){
    while(cin>>m>>n){
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                cin>>mp[i][j];
        }cin>>sx>>sy>>ex>>ey;sx--;sy--;ex--;ey--;
        b=bfs(sx,sy);
        if(b>0) cout<<b<<endl;
        else cout<<"No Way!"<<endl;
    }
}
