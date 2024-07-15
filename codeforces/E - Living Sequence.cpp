#include <bits/stdc++.h>
#define int long long
using namespace std;

string Base9(int n){
   string ans="";
   while(n){
      int rem=n%9;
      n/=9;
      ans=to_string(rem)+ans;
   }
   return ans;
}

int32_t main() {
   
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   
   int t; cin>>t;
   while(t--){
      int n; cin>>n;
      string ans=Base9(n);
      for(auto i: ans){
         int x=i-'0';
         if(x>3) cout<<x+1;
         else cout<<x;
      }
      cout<<'\n';
   }
   
   return 0;
}

