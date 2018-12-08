#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,m,n,mn,s,mp[22][22],v[22][22]={0};
int ans=0;
int net[4][2]={ {0,1}, {1,0}, {0,-1},{-1,0}};
void dfs(int x,int y,int step){
    int tx,ty;
    if(x==c&&y==d){
        ans++;
        if(step<mn)mn=step;
        //cout<<step<<endl;
        return;
    }
    for(int i=0;i<4;i++){
        tx=x+net[i][0];
        ty=y+net[i][1];
        if(!(x>=0&&x<m&&y>=0&&y<n))return;
        if(mp[tx][ty]==0&&v[tx][ty]==0){
            v[tx][ty]=1;
            dfs(tx,ty,step+1);
            v[tx][ty]=0;
        }
    }
}
int main(){
    while(cin>>m>>n){
        s=0;mn=999999;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
                cin>>mp[i][j];
        }cin>>a>>b>>c>>d;a--;b--;c--;d--;
        dfs(a,b,0);
        //cout<<"ans="<<ans<<endl;
        (mn==999999)?cout<<"No Way!"<<endl:cout<<mn<<endl;
    }
    return 0;
}
