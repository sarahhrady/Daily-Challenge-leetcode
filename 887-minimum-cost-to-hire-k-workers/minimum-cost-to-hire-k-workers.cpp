class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=quality.size();
        double currQ = 0;
        double totalC = numeric_limits<double>::max();
        vector<pair<double,int>>v;
        for(int i=0; i<n; i++)
        {
            v.push_back({static_cast<double>(wage[i])/quality[i], quality[i]});
        }   
        sort(v.begin(),v.end());
        priority_queue<int> pq;
        for(int i=0; i<n; i++)
        {
            pq.push(v[i].second);
            currQ+=v[i].second;
            if(pq.size()>k)
            {
                currQ-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
            {
                totalC =  min(totalC, currQ*v[i].first);
            }
        }

    return totalC;
    }
};