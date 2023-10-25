class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int maxdist = 0;
        int ans = 0;
        int nextdist = 0;
        for(int i = 0; i <= maxdist; i++){
            nextdist = max(nextdist, i + nums[i]);
            if(i == maxdist){
                maxdist = nextdist;
                ans++;
            }

            if(maxdist >= nums.size() - 1) break;
        }
        return ans;
    }
};