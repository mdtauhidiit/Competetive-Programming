class Solution {
public:
    const int mod=1e9+7;
    long long Add(long long a,long long b){
        return (a%mod+b%mod)%mod;
    }

    long long Mul(long long a,long long b){
        return ((a%mod)*(b%mod))%mod;
    }

    int sumSubarrayMins(vector<int>& a) {
        int n=a.size();
        vector<int> nextS(n,-1),prevS(n,-1);
        stack<int> st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && a[st.top()]>a[i]) st.pop();
            nextS[i]=(st.empty())?n:st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=0;i<n;i++){
            while(!st.empty() && a[st.top()]>=a[i]) st.pop();
            prevS[i]=(st.empty())?-1:st.top();
            st.push(i);
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long rd=nextS[i]-i;
            long long ld=i-prevS[i];
            long long temp=Mul(rd,ld);
            temp=Mul(temp,a[i]);
            ans=Add(ans,temp);
        }
        return (int)ans;
    }
};
