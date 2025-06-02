#include<bits/stdc++.h>
using namespace std;

/*
 Eventually all the elements will equal to gcd of whole array.
 So the problem reduces to finding minimum length subsequence 
 whose gcd equal g = gcd(a1,a2,a3,.....an).
 We can use dp to find our answer;

 Edges cases-> When some elements of array equal to g
               then result = n-cnt , where cnt = number of elements equal to g

*/
vector<int> a;
const int inf=1e8;
int n;

// f(i,currG,g) -> min steps to make gcd of subsequence = g if current gcd is currG;
int f(int i,int currG,int g,vector<vector<int>> &dp){
   if(currG==g) return 0;
   if(i>=n) return inf;
   if(dp[i][currG]!=-1) return dp[i][currG];
   int op1= f(i+1,__gcd(currG,a[i]),g,dp)+1;
   int op2= f(i+1,currG,g,dp);
   return dp[i][currG]=min(op1,op2);
}

int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      cin>>n;
      a.resize(n);
      int g=0,cntg=0,mx=0;
      for(int i=0;i<n;i++){
         cin>>a[i];
         g=__gcd(g,a[i]);
         mx=max(mx,a[i]);
      }
      for(int i=0;i<n;i++) cntg+=(a[i]==g);
      if(cntg){
         cout<<n-cntg<<"\n";
         continue;
      }
      vector<vector<int>> dp(n+1,vector<int> (mx+1,-1));
      cout<<n-2+f(0,0,g,dp);
      
      cout<<"\n";
      
   }
   
return 0;
}
 
