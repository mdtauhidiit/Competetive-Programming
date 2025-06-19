#include<bits/stdc++.h>
#define int long long
using namespace std;

string s1,s2;
int n,dp[15][2][2];
int f(int i,int t1,int t2){
   if(i==n) return 0;
   if(dp[i][t1][t2]!=-1) return dp[i][t1][t2];
   int ans=1e12;
   int ub=(t1)?(s2[i]-'0'):9;
   int lb=(t2)?(s1[i]-'0'):0;
   for(int j=lb;j<=ub;j++){
      int c1=(s1[i]-'0')==j;
      int c2=(s2[i]-'0')==j;
      ans=min(ans,c1+c2+f(i+1,t1&(j==ub),t2&(lb==j)));
   }
   return dp[i][t1][t2]=ans;
}

int32_t main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
       int l,r; cin>>l>>r;
       s2=to_string(r);
       s1=to_string(l);
       n=s1.size();
       memset(dp,-1,sizeof(dp));
       cout<<f(0,1,1)<<endl;
   }
   
return 0;
}

    
