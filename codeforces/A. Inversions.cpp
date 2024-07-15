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
   
    int n; cin>>n;
    vector<int> a(n+1);
    Fenwick fn(n);
    for(int i=1;i<=n;i++){
       cin>>a[i];
    }
    cout<<0<<' ';
    for(int i=2;i<=n;i++){
       fn.Update(a[i-1],1);
       cout<<fn.Sum(a[i],n)<<' ';
    }
    return 0;

}
