#include <bits/stdc++.h>
#define int long long
using namespace std;
 
class Node{
public:
   int prefix,total;
};
 
class SegmentTree{
public:
    vector<Node> seg;
    vector<int> a;
    int n;
    
    SegmentTree(vector<int> &Arr){
       n=Arr.size();
       a=Arr;
       seg.resize(4*n+1);
    }
    
    Node f(Node n1,Node n2){
       Node n3;
       n3.prefix=max({n1.prefix,n1.total+n2.prefix});
       n3.total=n1.total+n2.total;
       return n3;
    }
    
    void Build(int id,int l,int r){
       if(r-l==1){
          seg[id] ={a[l],a[l]};
          return ;
       }
       int mid=(l+r)/2;
       Build(2*id,l,mid);
       Build(2*id+1,mid,r);
       seg[id]=f(seg[2*id],seg[2*id+1]);
    }
    
    Node Query(int x,int y,int id,int l,int r){
       if(l>=y || r<=x) return  {0,0};
       if(l>=x && r<=y) return seg[id];
       int mid=l+(r-l)/2;
       return f(Query(x,y,2*id,l,mid),Query(x,y,2*id+1,mid,r));
    }
    
    void Modify(int pos,int val,int id,int l,int r){
       if(r-l==1){
          a[pos]=val;
          seg[id]={val,val};
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
          int k,v; cin>>k>>v;
          k--;
          st.Modify(k,v,1,0,n);
       }
       else {
          int l,r; cin>>l>>r;
          l--;
          int q1=st.Query(l,r,1,0,n).prefix;
          if(r-l==1) q1=max(q1,0LL);
          cout<<q1<<'\n';
       }
    } 
 
    return 0;
 
}
