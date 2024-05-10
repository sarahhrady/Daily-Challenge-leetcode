class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        priority_queue<pair<double,pair<int,int>>>pq;
        for(int i=0; i<arr.size();i++)
        {
            pq.push({-1.0*arr[i]/arr.back(),{i,arr.size()-1}});
        }
        k-=1;
        while(k--)
        {
            pair<int,int> p =  pq.top().second;
            pq.pop();
            p.second--;
            pq.push({-1.0*arr[p.first]/arr[p.second], {p.first,p.second}});
        }
        pair<int,int>res = pq.top().second;
        return {arr[res.first],arr[res.second]};
    }
};