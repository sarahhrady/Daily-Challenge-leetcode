class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>res;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1]==nums[i]){
                nums[i-1]=INT_MAX;
                nums[i]=INT_MAX;
            }
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]!=INT_MAX){
                res.push_back(nums[i]);
            }
        }
        return res;
    }
};