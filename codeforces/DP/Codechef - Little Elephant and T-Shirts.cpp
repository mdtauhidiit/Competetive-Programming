#include <bits/stdc++.h>
#define int long long
using namespace std;

int have[11][101];
int dp[101][1025];
int n;
const int mod=1e9+7;

int f(int i,int mask){
    if(mask==((1<<n)-1)) return 1;
    if(i>=100) return 0;
    if(dp[i][mask]!=-1) return dp[i][mask];
    int ans=f(i+1,mask);
    for(int j=0;j<n;j++){
        int ok=(1<<j)&mask;
        if(have[j][i] && ok==0){
            int newMask=(1<<j)|mask;
            ans+=f(i+1,newMask);
            ans%=mod;
        }
    }
    return dp[i][mask]=ans;
}

int32_t main() {
	// your code goes here
	int t; cin>>t;
	while(t--){
	    cin>>n;
	    memset(dp,-1,sizeof(dp));
	    memset(have,0,sizeof(have));
	    string s; 
	    cin.ignore();
	    for(int i=0;i<n;i++){
	        getline(cin,s);
	        stringstream in(s);
	        int a;
	        while(in>>a) {have[i][a-1]=1;}
	    }
	   
	    cout<<f(0,0)<<'\n';
	}
}
