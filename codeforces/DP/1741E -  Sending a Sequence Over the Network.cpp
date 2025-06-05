#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      int n; cin>>n;
      vector<int> a(n+1),dp(n+1,0);
      for(int i=1;i<=n;i++) cin>>a[i];
      dp[0]=1;
      for(int i=1;i<=n;i++){
         if(i+a[i]<=n && dp[i-1]) dp[i+a[i]]=1;
         if(i-a[i]-1>=0 && dp[i-a[i]-1]) dp[i]=1;
      }
      if(dp[n]) cout<<"YES\n";
      else cout<<"NO\n";
   }
   return 0;
}
