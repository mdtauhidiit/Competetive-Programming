#include<bits/stdc++.h>
using namespace std;

string s;

bool isPalindrome(int i,int j,vector<vector<int>> &pal){
   if(i>=j) return 1;
   if(pal[i][j]!=-1) return pal[i][j];
   if(s[i]==s[j]) pal[i][j]=isPalindrome(i+1,j-1,pal);
   else pal[i][j]=0;
   return pal[i][j];
}

int f(int i,int j,vector<vector<int>> &dp,vector<vector<int>> &pal){
   if(i>j) return 0;
   if(dp[i][j]!=-1) return dp[i][j];
   dp[i][j]=isPalindrome(i,j,pal)+f(i+1,j,dp,pal)+f(i,j-1,dp,pal)-f(i+1,j-1,dp,pal);
   return dp[i][j];
}


int main(){
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
    cin>>s;
   int q; cin>>q;
   int n=s.size();
   vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
   vector<vector<int>> pal(n+1,vector<int>(n+1,-1));
   while(q--){
      int l,r; cin>>l>>r;
      l--; r--;
      cout<<f(l,r,dp,pal)<<'\n';
   }
   
return 0;
}

