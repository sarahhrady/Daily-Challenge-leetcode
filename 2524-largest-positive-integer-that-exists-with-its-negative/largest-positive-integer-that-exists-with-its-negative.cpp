class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<int>s;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<0)s.insert(nums[i]);
            else break;
        }
        
        for(int i= nums.size()-1; i>=0; i--)
        {
           if(s.find(nums[i]*-1)!=s.end())return nums[i];
        }
        return -1;
    }
};