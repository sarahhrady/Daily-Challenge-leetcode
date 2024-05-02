class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int res=-1;
        set<int>s(nums.begin(),nums.end());
        for(int i:s)
        {
            if(s.find(-i)!=s.end())res=max(res,i);
        }
        return res;
    }
};