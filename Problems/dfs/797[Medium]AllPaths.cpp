class Solution {
public:
    //index 1 to 14
    bool visited[15] = {false};
    void dfs(vector<vector<int>>& graph, int x, vector<int>& temp, vector<vector<int>>& output) {
        //Target found
        if(x == graph.size() - 1) {
            output.push_back(temp);
            return ;
        }
        
        //Skip the visited node
        if(visited[x]) {
            return ;
        }
        
        //Depth First Search
        for(auto i:graph[x]) {
            temp.push_back(i);
            dfs(graph,i,temp,output);
            temp.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        vector<vector<int>> output;
        vector<int> temp;
        temp.push_back(0);
        
        dfs(graph,0,temp,output);
        return output;
    }
};
