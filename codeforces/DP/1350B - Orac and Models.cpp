#include<bits/stdc++.h>
#define int long long
using namespace std;


int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      int n; cin>>n;
      vector<int> a(n+1),dp(n+1,1);
      for(int i=1;i<=n;i++) cin>>a[i];
      for(int i=1;i<=n;i++){
         for(int j=i;j<=n;j+=i){
            if(a[j]>a[i]){
               dp[j]=max(dp[j],dp[i]+1);
            }
         }
      }
      int ans=*max_element(dp.begin(),dp.end());
      cout<<ans<<endl;
   }
   
return 0;
}

