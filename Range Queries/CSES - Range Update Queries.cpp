#include<bits/stdc++.h>
#define int long long
using namespace std;
 
class FenwickTree{
   
public:
   vector<int> bit;
   int n;
   FenwickTree(int x){
      bit.resize(x+2,0);
      n=x+1;
   }
   
   void Update(int k,int val){ //Point Update
      while(k<=n){
         bit[k]+=val;
         k+=k&(-k);
      }
   }
   
   void Update(int a,int b,int val){ // Range Update
      Update(a,val);
      Update(b+1,-val);
   }
   
   int Sum(int k){
      int res=0;
      while(k>0){
         res+=bit[k];
         k-=k&(-k);
      }
      return res;
   }
   
   int Query(int l,int r){
      return Sum(r)-Sum(l-1);
   }
};
 
int32_t main(){
   
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   cout.tie(NULL);
   
   int n,q; cin>>n>>q;
   vector<int> a(n+1);
   FenwickTree fn(n);
   for(int i=1;i<=n;i++) {
      cin>>a[i];
      fn.Update(i,i,a[i]);
   }
   while(q--){
      int t; cin>>t;
      if(t==1){
         int a,b,u; cin>>a>>b>>u;
         fn.Update(a,b,u);
      }
      else{
         int k; cin>>k;
         cout<<fn.Sum(k)<<'\n';
      }
   }
   
   return 0;
}
 
