class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int,int>>v;
        for(int i=0; i<points.size(); i++)
        {
            v.push_back({points[i][0],points[i][1]});
        }
        sort(v.begin(),v.end());
        int cnt=1;
        //int start=v[0].first;
        int end=v[0].second;
        for(int i=1; i<v.size();i++)
        {
            if(v[i].first<=end)
            {
                end= min(end,v[i].second);
                continue;
            }
            cnt++;
            end=v[i].second;
        }
        return cnt;
    }
};