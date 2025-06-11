#include <bits/stdc++.h>
#define int long long
using namespace std;
 
class FenwickTree{
public:
    vector<int> bit;
    int n;
    FenwickTree(int n){
       bit.resize(n+1);
       this->n=n;
    }
    
    void Update(int k,int val){
       while(k<=n){
          bit[k]+=val;
          int lsb=k&(-k);
          k+=lsb;
       }
    }
    
    int Pre(int k){
       int res=0;
       while(k>0){
          res+=bit[k];
          int lsb=k&(-k);
          k-=lsb;
       }
       return res;
    }
    
    int Query(int l, int r){
       return Pre(r)-Pre(l-1);
    }
};
 
int32_t main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
 
    int n,q; cin>>n>>q;
    FenwickTree ft(n);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) {
       cin>>a[i];
       ft.Update(i,a[i]);
    }
    while(q--){
       int t; cin>>t;
       if(t==1){
          int k,u; cin>>k>>u;
          ft.Update(k,u-a[k]);
          a[k]=u;
       }
       else {
          int a,b; cin>>a>>b;
          cout<<ft.Query(a,b)<<'\n';
       }
    }
 
 return 0;
}
