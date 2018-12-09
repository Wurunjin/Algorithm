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
