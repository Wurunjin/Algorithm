#include <bits/stdc++.h>
using namespace std;
int v[100000];
int dp[100001]={0};
int LIS(int n){
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
int main() {
    int n;
    cin>>n;
    cout<<LIS(n)<<endl;
}
//我们可以通过二分查找中改变“上确界”和“下确界”，以及符号（“<”和“<=”或“>”、“>=”等），求出最长不下降、不上升、严格下降子序列等问题。

//example in

//7
//2 5 3 4 1 7 6

//example out

//4

