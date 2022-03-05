// LeetCode problem 31.


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int flag = 0;
        
        for(int i=nums.size()-2;i>=0;i--)
        {
            if(nums[i] < nums[i+1])
            {
                flag = 1;
                
                for(int j = nums.size()-1;j>i;j--)
                {
                    if(nums[j] > nums[i])
                    {
                        swap(nums[j],nums[i]);
                        break;
                    }
                        
                }
                
                reverse(nums.begin()+i+1,nums.end());
                break;
            }
        }
        
        if(flag == 0)
            sort(nums.begin(),nums.end());
    }
};
