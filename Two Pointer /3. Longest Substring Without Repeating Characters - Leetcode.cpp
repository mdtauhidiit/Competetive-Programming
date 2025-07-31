class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int l=0,r=0,ans=0;
        while(r<n){
            if(mp.find(s[r])!=mp.end()) l=max(l,mp[s[r]]+1);
            int len=r-l+1;
            ans=max(ans,len);
            mp[s[r]]=r;
            r++;
        }
        return ans;
    }
};
