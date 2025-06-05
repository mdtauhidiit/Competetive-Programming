#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=1e5+5;
int dp[N][2],n;
string s;

int f(int i,int j){
   if(i>=n) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
   if(isupper(s[i])){
      if(j) dp[i][j]=min(f(i+1,j),1+f(i+1,0));
      else dp[i][j]=f(i+1,0)+1;
   }
   else {
      if(j) dp[i][j]=min(f(i+1,1)+1,f(i+1,0));
      else dp[i][j]=f(i+1,0);
   }
   return dp[i][j];
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   memset(dp,-1,sizeof(dp));
   cin>>s;
   n=s.size();
   cout<<min(f(0,0),f(0,1))<<'\n';
   
   
return 0;
}

