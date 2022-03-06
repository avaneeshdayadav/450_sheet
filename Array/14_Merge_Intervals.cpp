
// Leetcode problem no 56


class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        
        for(int i=1;i<intervals.size();i++)
        {
            if(intervals[i][0] <= res[res.size()-1][1])
            {
                vector<int> pushVec;
                pushVec.push_back(res[res.size()-1][0]);
                pushVec.push_back(max(intervals[i][1],res[res.size()-1][1]));
                
                res.pop_back();
                res.push_back(pushVec);
            }
            else
                res.push_back(intervals[i]);
        }
        
        return res;
    }
};
