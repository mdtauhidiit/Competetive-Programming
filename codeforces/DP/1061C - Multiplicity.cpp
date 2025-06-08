#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e6+5;
const int mod=1e9+7;
int a[N],n,dp[N];

//dp[i]=number of subsequences of length i
//dp[len]=dep[len]+dp[len-1]

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   dp[0]=1;
   for(int i=1;i<=n;i++){
      int x=a[i];
      priority_queue<int> pq;
      for(int j=1;j*j<=x;j++){
         if(x%j==0){
            pq.push(j);
            if(j!=x/j) pq.push(x/j);
         }
      }
      while(!pq.empty()){
         int t=pq.top();
         pq.pop();
         dp[t]=(dp[t]+dp[t-1])%mod;
      }
   }
   int ans=0;
   for(int i=1;i<=n;i++) ans=(ans+dp[i])%mod;
   cout<<ans<<endl;
   
return 0;
}

