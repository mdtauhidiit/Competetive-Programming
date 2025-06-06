#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5;
int dp[N+5],f[N+5];
int a[N+5];

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int n; cin>>n;
   memset(dp,0,sizeof(dp));
   memset(f,0,sizeof(f));
   for(int i=0;i<n;i++) {
      int x; cin>>x;
      f[x]++;
   }
   dp[0]=0;
   dp[1]=f[1];
   for(int i=2;i<=N;i++){
      dp[i]=max(dp[i-2]+i*f[i],dp[i-1]);
   }
   cout<<dp[100000];
   
return 0;
}

