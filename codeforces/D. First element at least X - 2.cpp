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
    
    int f(int n1,int n2){
       return max(n1,n2);
    }
    
    void Build(int id,int l,int r){
       if(r-l==1){
          seg[id] =a[l];
          return ;
       }
       int mid=(l+r)/2;
       Build(2*id,l,mid);
       Build(2*id+1,mid,r);
       seg[id]=f(seg[2*id],seg[2*id+1]);
    }
    
    int Query(int x,int j,int id,int l,int r){
       if(r-l==1){
          if(seg[id]>=x && l>=j) return l;
          return -1;
       }
       int mid=(l+r)/2,res=-1;
       if(seg[2*id]>=x && mid>=j) res=Query(x,j,2*id,l,mid);
       if(res==-1) res=Query(x,j,2*id+1,mid,r);
       return res;
    }
    
    void Modify(int pos,int val,int id,int l,int r){
       if(r-l==1){
          a[pos]=val;
          seg[id]=val;
          return ;
       }
       int mid=(l+r)/2;
       if(pos<mid) Modify(pos,val,2*id,l,mid);
       else Modify(pos,val,2*id+1,mid,r);
       seg[id]=f(seg[2*id],seg[2*id+1]);
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
          int x,l; cin>>x>>l;
          cout<<st.Query(x,l,1,0,n)<<'\n';
       }
    } 
 
    return 0;
 
}
