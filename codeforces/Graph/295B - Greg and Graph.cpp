#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    int a[n+1][n+1],dp[n+1][n+1];
    for(int i=1;i<=n;i++){
       for(int j=1;j<=n;j++){
          cin>>a[i][j];
          dp[i][j]=a[i][j];
       }
    }
    vector<int> x(n),ans;
    for(int i=0;i<n;i++) cin>>x[i];
    reverse(x.begin(),x.end());
    for(int k=0;k<n;k++){
       for(int i=1;i<=n;i++){
          for(int j=1;j<=n;j++){
             dp[i][j]=min(dp[i][j],dp[i][x[k]]+dp[x[k]][j]);
          }
       }
       int sum=0;
       for(int i=0;i<=k;i++){
          for(int j=0;j<=k;j++){
             sum+=dp[x[i]][x[j]];
          }
       }
       ans.push_back(sum);
    }
    reverse(ans.begin(),ans.end());
    for(auto i: ans) cout<<i<<" ";
    
    return 0;
}
