class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++) nums[i]=nums[i]%2;
        map<int,int> mp;
        mp[0]=1;
        int preSum=0,ans=0;
        for(int i=0;i<n;i++){
            preSum+=nums[i];
            ans+=mp[preSum-k];
            mp[preSum]++;
        }
        return ans;

    }
};
