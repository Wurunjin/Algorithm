#include <bits/stdc++.h>
using namespace std;
int v[100000];
int dp[100001]={0};
int LIS_01(int n){
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(v[j]<v[i]&&dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
    }
    return *max_element(dp,dp+n);
}
int LIS_02(int n){
    int len=1;
    for(int i=0;i<n;i++)cin>>v[i];
    dp[0]=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]>dp[len]){
            dp[++len]=v[i];
        }else{
            int j=lower_bound(dp+1,dp+len+1,v[i])-dp;
            dp[j]=v[i];
        }
    }
    return len;
}
int main() {
    int n;
    cin>>n;
    cout<<LIS_01(n)<<endl;
    //cout<<LIS_02(n)<<endl;
}
//我们可以通过二分查找中改变“上确界”和“下确界”，以及符号（“<”和“<=”或“>”、“>=”等），求出最长不下降、不上升、严格下降子序列等问题。

//example in

//7
//2 5 3 4 1 7 6

//example out

//4

