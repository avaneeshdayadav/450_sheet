class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
    }
    int findDuplicate(vector<int>& nums) {
        
        while(true)
        {
            int val = nums[0];
            
            if(val == nums[val])
                return val;
            
            swap(nums[0],nums[val]);
        }
    }
};
