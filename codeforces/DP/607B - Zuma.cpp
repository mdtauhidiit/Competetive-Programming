#include<bits/stdc++.h>
#define int long long
using namespace std;

int dp[505][505],c[505];
int n;

int f(int i,int j){
   if(i>=j) return 1;
   if(dp[i][j]!=-1) return dp[i][j];
   int ans=INT_MAX;
   if(c[i]==c[j]) ans=f(i+1,j-1);
   for(int k=i+1;k<j;k++){
      if(c[k]==c[i]) ans=min(ans,f(i+1,k-1)+f(k+1,j));
      if(c[k]==c[j]) ans=min(ans,f(i,k-1)+f(k+1,j-1));
   }
   ans=min(ans,f(i+1,j)+1);
   ans=min(ans,f(i,j-1)+1);
   return dp[i][j]=ans;
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin>>n;
   for(int i=1;i<=n;i++) cin>>c[i];
   memset(dp,-1,sizeof(dp));
   cout<<f(1,n);
   
   return 0;
}
