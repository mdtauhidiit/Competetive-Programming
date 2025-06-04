 #include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5;
int dp[N+5][2];
int n,g[N+5],h[N+5];

int f(int i,int j){
   if(i>n) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
   if(j==0){
      dp[i][j]=max(g[i]+f(i+1,1),f(i+1,j));
   }
   else {
      dp[i][j]=max(h[i]+f(i+1,0),f(i+1,j));
   }
   return dp[i][j];
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin>>n;
   for(int i=1;i<=n;i++) cin>>h[i];
   for(int i=1;i<=n;i++) cin>>g[i];
   memset(dp,-1,sizeof(dp));
   cout<<max(f(1,0),f(1,1))<<'\n';
   
   
return 0;
}

