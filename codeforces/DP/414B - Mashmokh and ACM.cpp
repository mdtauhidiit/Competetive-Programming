#include<bits/stdc++.h>
using namespace std;

const int N=2e3+5;
const int mod=1e9+7;
int dp[N][N],n,k;


//f(n,k) -> no. of good sequence ending at n having length k
//The idea is to iterate over all factors of n and find good 
//sequence of length k-1 ending at "i" where n%i==0

int f(int n,int k){
   if(k<=0) return 0;
   if(k==1) return 1;
   if(dp[n][k]!=-1) return dp[n][k];
   long long ans=0;
   for(int i=1;i*i<=n;i++){
      if(n%i==0){
         ans=(ans+f(i,k-1))%mod;
         if(i!=n/i) ans=(ans+f(n/i,k-1))%mod;
      }
   }
   return dp[n][k]=ans;
}

int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   cin>>n>>k;
   memset(dp,-1,sizeof(dp));
   long long ans=0;
   for(int i=1;i<=n;i++){
      ans=(ans+f(i,k))%mod;
   }
   cout<<ans<<endl;
   
return 0;
}

