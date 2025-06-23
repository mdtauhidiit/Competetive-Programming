#include<bits/stdc++.h>
#define int long long
using namespace std;

const int inf=1e18;

int f(int i,int k,vector<vector<int>> &dp,vector<int> &a){
   int n=a.size();
   if(i==n) return 0;
   if(dp[i][k]!=-1) return dp[i][k];
   int mini=inf,ans=inf;
   for(int d=0;d<=k;d++){
      if(i+d<n){
         mini=min(mini,a[i+d]);
         ans=min(ans,f(i+d+1,k-d,dp,a)+(d+1)*mini);
      }
   }
   return dp[i][k]=ans;
}

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin>>t;
    while(t--){
       int n,k; cin>>n>>k;
       vector<int> a(n);
       for(int i=0;i<n;i++) cin>>a[i];
       vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
       cout<<f(0,k,dp,a)<<'\n';
    }
    
    return 0;
}
