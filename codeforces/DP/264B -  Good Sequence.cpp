#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5;
int dp[N+5],ind[N+5];

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int n; cin>>n;
   int ans=0;
   for(int i=1;i<=n;i++) {
      int x; cin>>x;
      for(int j=1;j*j<=x;j++){
         if(x%j==0){
            dp[i]=max(dp[i],dp[ind[x/j]]+1LL);
            if(j>1) dp[i]=max(dp[i],dp[ind[j]]+1);
            ans=max(ans,dp[i]);
            ind[j]=ind[x/j]=i;
         }
      }
   }
   cout<<ans<<endl;
   
return 0;
}

