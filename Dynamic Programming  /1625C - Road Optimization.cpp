#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,l,k; 
int a[501],d[501];
int dp[501][501];

//f(i,k) -> min time to go to ith index and at most k signs can be removed
int f(int i,int k){
   if(k<0) return 1e18;
   if(i==n) return 0;
   if(dp[i][k]!=-1) return dp[i][k];
   int ans=1e18;
   for(int j=i+1;j<=n;j++){
      ans=min(ans,f(j,k-(j-i-1))+(d[j]-d[i])*a[i]);
   }
   return dp[i][k]=ans;
}

int32_t main(){
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>l>>k;
    for(int i=0;i<n;i++) cin>>d[i];
    for(int i=0;i<n;i++) cin>>a[i];
    d[n]=l;
    memset(dp,-1,sizeof(dp));
    cout<<f(0,k)<<'\n';
    
	return 0;
}
