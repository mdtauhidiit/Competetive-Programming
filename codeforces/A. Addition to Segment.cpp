#include <bits/stdc++.h>
#define int long long
using namespace std;

class Fenwick{
public:
   vector<int> bit;
   int n;
   
   Fenwick(int x){
      bit.resize(x+1,0);
      n=x;
   }
   
   void Update(int k,int val){ 
      while(k<=n){
         bit[k]+=val;
         k+=(k&(-k));
      }
   }
   
   void Update(int l,int r,int val){
      Update(l,val);
      Update(r+1,-val);
   }
   
   int Pre(int k){
      int ans=0;
      while(k>0){
         ans+=bit[k];
         k-=(k&(-k));
      }
      return ans;
   } 
   
   int Sum(int l,int r){
      return Pre(r)-Pre(l-1);
   }
   
};


int32_t main() {
   
    int n,m; cin>>n>>m;
    Fenwick fn(n);
    while(m--){
       int t; cin>>t;
       if(t==1){
          int l,r,v; cin>>l>>r>>v;
          fn.Update(l+1,r,v);
       }
       else {
          int i; cin>>i;
          cout<<fn.Sum(1,i+1)<<'\n';
       }
    }
    return 0;

}
