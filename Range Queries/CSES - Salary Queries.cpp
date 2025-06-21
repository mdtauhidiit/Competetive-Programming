#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef pair<int,int> pii;


tree<pii, null_type, less<pii>, rb_tree_tag,
tree_order_statistics_node_update> T;
 
int32_t main() {
   
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   
    int n,q; cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++) {
       cin>>a[i];
       T.insert({a[i],i});
    }
    while(q--){
       char c; cin>>c;
       if(c=='!'){
          int k,x; cin>>k>>x;
          T.erase({a[k],k});
          T.insert({x,k});
          a[k]=x;
       }
       else {
          int a,b; cin>>a>>b;
          cout<<T.order_of_key({b+1,0})-T.order_of_key({a,0})<<'\n';
       }
    } 
 
    return 0;
 
}
