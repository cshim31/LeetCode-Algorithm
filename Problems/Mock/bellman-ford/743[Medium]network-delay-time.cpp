class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // distance from source node to each target node
        vector<int> dist(N + 1, INT_MAX);
        dist[0] = 0;
        dist[K] = 0;
        int i;
        for(i = 0; i < dist.size(); i++) {
            for(vector<int> temp : times) {
                int u = temp[0];
                int v = temp[1];
                int w = temp[2];
                
                if(dist[u] != INT_MAX  && dist[v] > dist[u] + w) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        
        int maxVal = 0;
        for(i = 0; i < dist.size(); i++){
            maxVal = max(maxVal, dist[i]);
        } 
        return maxVal != INT_MAX? maxVal : -1;
    }
};