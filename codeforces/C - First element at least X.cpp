#include <bits/stdc++.h>
#define int long long
using namespace std;
 
class SegmentTree{
public:

    
    vector<int> seg;
    vector<int> a;
    int n;
    
    SegmentTree(vector<int> &Arr){
       n=Arr.size();
       a=Arr;
       seg.resize(4*n+1);
    }
    
    int f(int l,int r){
       return max(l,r);
    }
    
    void Build(int id,int l,int r){
       if(r-l==1){
          seg[id] = a[l];
          return ;
       }
       int mid=(l+r)/2;
       Build(2*id,l,mid);
       Build(2*id+1,mid,r);
       seg[id]=f(seg[2*id],seg[2*id+1]);
    }
    
    void Modify(int pos,int val,int id,int l,int r){
       if(r-l==1){
          a[pos]= val;
          seg[id] = val;
          return ;
       }
       int mid=(l+r)/2;
       if(pos<mid) Modify(pos,val,2*id,l,mid);
       else Modify(pos,val,2*id+1,mid,r);
       seg[id]=f(seg[2*id],seg[2*id+1]);
    }
    
    int Query(int x,int id,int l,int r){
       if(r-l==1){
          if(seg[id]>=x) return l;
          return -1;
       }
       int mid=(l+r)/2;
       if(seg[2*id]>=x){
          return Query(x,2*id,l,mid);
       }
       else {
          return Query(x,2*id+1,mid,r);
      }
    }
    
};
 
int32_t main() {
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    int n,q; cin>>n>>q;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    SegmentTree st(a);
    st.Build(1,0,n);
    while(q--){
       int t; cin>>t;
       if(t==1){
          int i,v; cin>>i>>v;
          st.Modify(i,v,1,0,n);
      }
      else {
         int k; cin>>k;
         cout<<st.Query(k,1,0,n)<<'\n';
      }
    } 
 
    return 0;
 
}
