#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=3e5,inf=1e15;
int a[3*N+1],par[3*N+1],d[3*N+1];
vector<int>path;
vector<vector<int>>Adj;

void Dijkstra(int node){
    if(!Adj[node].size()) return;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    d[node]=0;par[node]=-1;
    pq.push({d[node],node});
    int w=1;
    while(!pq.empty()){
         auto p=pq.top();
         pq.pop();
         int u=p.second;
         for(auto v : Adj[u]){
             if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                par[v]=u;
                pq.push({d[v],v});
             }
         }
    }

}

void Trace(int target){

    while(target!=-1){
        if(target<=N){
            path.push_back(target);
        }
        target=par[target];
    }
    reverse(path.begin(),path.end());
}

int32_t main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin>>n;
    map<int,int> pos;
    for(int i=1;i<=3*N;i++) d[i]=inf;
    Adj.resize(3*N);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        pos[i+1]=x;
        int k=x;
        for(int d=2;d*d<=x;d++){
            if(x%d==0){
                Adj[i+1].push_back(d+N);
                Adj[d+N].push_back(i+1);
                while(x%d==0) x/=d;
            }
        }
        if(x>1) {
            Adj[i+1].push_back(x+N);
            Adj[x+N].push_back(i+1);
        }
    }
    int x,y; cin>>x>>y;
    if(x==y){
        cout<<"1\n"<<x<<'\n';
        return 0;
    }
    if(__gcd(pos[x],pos[y])!=1){
        cout<<2<<"\n";
        cout<<x<<" "<<y<<'\n';
        return 0;
    }
    Dijkstra(x);
    if(d[y]==inf) cout<<-1<<'\n';
    else {
        Trace(y);
        cout<<path.size()<<'\n';
        for(auto i: path) cout<<i<<" ";
    }
    return 0;
}
